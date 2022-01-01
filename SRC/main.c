#include "so_long.h"

void init_imgs(t_game *game)
{
	game->pers->img = mlx_xpm_file_to_image(game->mlx, "./pers.xpm", &game->pers->width, &game->pers->height);
	if (game->pers->img == NULL)
		game_close(4, game);
	game->space->img = mlx_xpm_file_to_image(game->mlx, "./space.xpm", &game->pers->width, &game->pers->height);
	if (game->space->img == NULL)
		game_close(4, game);
	game->wall->img = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &game->pers->width, &game->pers->height);
	if (game->wall->img == NULL)
		game_close(4, game);
	game->food->img = mlx_xpm_file_to_image(game->mlx, "./collect.xpm", &game->pers->width, &game->pers->height);
	if (game->wall->img == NULL)
		game_close(4, game);
	game->exit->img = mlx_xpm_file_to_image(game->mlx, "./exit.xpm", &game->pers->width, &game->pers->height);
	if (game->exit->img == NULL)
		game_close(4, game);
}



void init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->space = NULL;
	game->wall = NULL;
	game->food = NULL;
	game->exit = NULL;
	game->pers = NULL;
	game->map_name = NULL;
	game->map = NULL;
	game->moveCnt = 0;
	game->foodCnt = 0;
	game->exitCnt = 0;
	game->persCnt = 0;
	game->didMove = 0;
	game->eatFood = 0;
	game->h = 0;
	game->w = 0;
	game->needClear = 0;
	game->pX = 0;
	game->pY = 0;
}

t_game *init_mem(char **av)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if (game == NULL)
		game_close(3, game);
	init_game(game);
	game->space = malloc(sizeof(t_img));
	game->wall = malloc(sizeof(t_img));
	game->food = malloc(sizeof(t_img));
	game->exit = malloc(sizeof(t_img));
	game->pers = malloc(sizeof(t_img));
	game->map_name = ft_strdup(av[1]);
	return (game);
}


int	main(int ac, char **av)
{
	t_game *game;

	if (ac != 2)
		game_close(6, NULL);	
	game = init_mem(av);
	read_map(game, av[1]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->w * 100, game->h * 100, "so_long");
	init_imgs(game);
	mlx_hook(game->win, 2, 1L<<0, key, game);
	mlx_hook(game->win, 17, 1L<<2, button, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
	return 0;
}