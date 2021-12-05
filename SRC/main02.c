#include "so_long.h"


int I = 0;

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	draw_wall(t_game *game)
// {

// }

// void	draw_map(t_game *game)
// {
// 	int	i = 0;
// 	int	j = 0;
// 	while (game->map[i])
// 	{
// 		while (game->map[i][j])
// 		{
// 			if (game->map[i][j] == '1')
// 			{

// 			}		
// 		}
		
// 	}

// }

void f_draw1(t_game	*game)
{
	int pic[SIZE_BLOCK][SIZE_BLOCK];
	int i = 0;
	int j = 0;

	while (i < SIZE_BLOCK)
	{
		j = 0;	
		while (j < SIZE_BLOCK)
		{
			pic[i][j] = 0xffffff - j * 100;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < SIZE_BLOCK)
	{
		j = 0;
		while (j < SIZE_BLOCK)
		{
			my_mlx_pixel_put(game, j, i, pic[i][j]);
			j++;
		}
		i++;
	}
}

void f_draw2(t_game	*game)
{
	int pic[SIZE_BLOCK][SIZE_BLOCK];
	int i = 0;
	int j = 0;

	while (i < SIZE_BLOCK)
	{
		j = 0;	
		while (j < SIZE_BLOCK)
		{
			pic[i][j] = 0xffffff - j * 10;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < SIZE_BLOCK)
	{
		j = 0;
		while (j < SIZE_BLOCK)
		{
			my_mlx_pixel_put(game, 200 + j, 200 + i, pic[i][j]);
			j++;
		}
		i++;
	}
}

void f_draw(t_game	*game, int color)
{
	int pic[SIZE_BLOCK][SIZE_BLOCK];
	int i = 0;
	int j = 0;

	while (i < SIZE_BLOCK)
	{
		j = 0;	
		while (j < SIZE_BLOCK)
		{
			pic[i][j] = color;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < SIZE_BLOCK)
	{
		j = 0;
		while (j < SIZE_BLOCK)
		{
			my_mlx_pixel_put(game, 100 + j, i, pic[i][j]);
			j++;
		}
		i++;
	}
}
void draw_space(t_game	*game, int color)
{
	int pic[SIZE_BLOCK][SIZE_BLOCK];
	int i = 0;
	int j = 0;

	while (i < SIZE_BLOCK)
	{
		j = 0;	
		while (j < SIZE_BLOCK)
		{
			pic[i][j] = color;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < SIZE_BLOCK)
	{
		j = 0;
		while (j < SIZE_BLOCK)
		{
			my_mlx_pixel_put(game, 100 + j, i, pic[i][j]);
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_game *game)
{
	// f_draw2(game->mlx, game->win, game);
	// sleep(1);
	// f_draw(game->mlx, game->win, game);
	if (I++ % 2 == 0)
		f_draw1(game);
	else
		f_draw2(game);
		f_draw(game, 0x888888);
	// sleep(1);
	// printf("asd i=%d\n", I++);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return 0;
}

int	key_hook(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	if (keycode == 53)
		exit(0);
	printf("    Hello from key_hook!                  %d\n", keycode);
	return 0;
}
void write_map(t_game *game)
{

	int i = -1;
	// int j = -1;
	while (game->map[++i])
	{
		// j = -1;
		// while (game->map[i][++j])
		// {
		// 	printf("%d|", game->map[i][j]);
		// }
		// printf("\n");
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
			// printf("XYU oldMap[%d]=%s map[%d]=%s\n", i, oldMap[i], i, game->map[i]);
		}
		game->map[i] = line;
		// printf("cnt=%d, line=%s\n", cnt, line);
		// printf("XYU \n");
		// write_map(game);
		// printf("XYU \n");
		i = -1;
		free(oldMap);
	}
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
	game->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length,
								&game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);


	return 0;
}