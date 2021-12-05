#include "so_long.h"

int	render_next_frame(t_game *game)
{
	(void)game;
	mlx_put_image_to_window(game->mlx, game->win, game->pers->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	(void)game;
	if (keycode == 53)
		exit(0);
	printf("    Hello from key_hook!                  %d\n", keycode);
	return 0;
}
void write_map(t_game *game)
{

	int i = -1;
	while (game->map[++i])
	{
		printf("map[%d]=%s\n", i, game->map[i]);
	}
}

void read_map(t_game *game, char *map_name)
{
	int fd;
	int ret;
	int cnt;
	char *line;
	char **oldMap = NULL;;
	
	int i = -1;

	cnt = 0;
	ret = 1;
	game->map = (char**)ft_calloc(sizeof(char*), cnt + 1);
	if (!game->map)
	{
		printf("CALLOC ERROR\n");
		exit(0);
	}
		
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		printf("map read error\n");
		exit(0);
	}
	while (ret > 0)
	{
		ret = gnl(fd, &line);
		if (ret == -1)
			exit(0);
		cnt++;
		oldMap = game->map;
		game->map = (char**)ft_calloc(sizeof(char*), cnt + 1);
		if (!game->map)
		{
			printf("CALLOC ERROR\n");
			exit(0);
		}
		while (oldMap[++i])
		{
			game->map[i] = oldMap[i];
		}
		game->map[i] = line;

		i = -1;
		free(oldMap);
	}
}

void init_imgs(t_game *game)
{
	game->pers->img = mlx_xpm_file_to_image(game->mlx, "./pers.xpm", &game->pers->width, &game->pers->height);
}

int	main(int ac, char **av)
{
	t_game *game = malloc(sizeof(t_game));
	if (ac != 2)
	{
		printf("Need map name(path2mapFile)\n");
		exit(0);
	}
	read_map(game, av[1]);
	write_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, BORDER_TXT);
	init_imgs(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);


	return 0;
}