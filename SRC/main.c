#include "so_long.h"

void init_imgs(t_game *game)
{
	game->pers->img = mlx_xpm_file_to_image(game->mlx, "imgs/persM.xpm", 
	&game->pers->width, &game->pers->height);
	if (game->pers->img == NULL)
		game_close(1, game);
	game->space->img = mlx_xpm_file_to_image(game->mlx, "imgs/spaceM.xpm", 
	&game->space->width, &game->space->height);
	if (game->space->img == NULL)
		game_close(1, game);
	game->wall->img = mlx_xpm_file_to_image(game->mlx, "imgs/wallM.xpm", 
	&game->wall->width, &game->wall->height);
	if (game->wall->img == NULL)
		game_close(1, game);
	game->food->img = mlx_xpm_file_to_image(game->mlx, "imgs/foodM.xpm", 
	&game->food->width, &game->food->height);
	if (game->wall->img == NULL)
		game_close(1, game);
	game->exit->img = mlx_xpm_file_to_image(game->mlx, "imgs/exitM.xpm", 
	&game->exit->width, &game->exit->height);
	if (game->exit->img == NULL)
		game_close(1, game);
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
	game->pX = 0;
	game->pY = 0;
	game->h = 0;
	game->w = 0;
	game->needClear = 0;
}

t_game *init_mem(char **av)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		game_close(3, game);
	init_game(game);
	game->space = malloc(sizeof(t_img));
	if (!game->space)
		game_close(3, game);
	game->wall = malloc(sizeof(t_img));
	if (!game->wall)
		game_close(3, game);
	game->food = malloc(sizeof(t_img));
	if (!game->food)
		game_close(3, game);
	game->exit = malloc(sizeof(t_img));
	if (!game->exit)
		game_close(3, game);
	game->pers = malloc(sizeof(t_img));
	if (!game->pers)
		game_close(3, game);
	game->map_name = ft_strdup(av[1]);
	if (!game->map_name)
		game_close(3, game);
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
	game->win = mlx_new_window(game->mlx, game->w * 50, game->h * 50, 
	"so_long");
	init_imgs(game);
	mlx_hook(game->win, 2, 1L<<0, key, game);
	mlx_hook(game->win, 17, 1L<<2, button, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
	return 0;
}