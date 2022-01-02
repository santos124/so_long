/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:00:05 by wadina            #+#    #+#             */
/*   Updated: 2022/01/02 02:00:07 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_game *game)
{
	game->pers->img = mlx_xpm_file_to_image(game->mlx, "imgs/persM.xpm",
			&game->pers->w, &game->pers->h);
	if (game->pers->img == NULL)
		game_close(1, game);
	game->space->img = mlx_xpm_file_to_image(game->mlx, "imgs/spaceM.xpm",
			&game->space->w, &game->space->h);
	if (game->space->img == NULL)
		game_close(1, game);
	game->wall->img = mlx_xpm_file_to_image(game->mlx, "imgs/wallM.xpm",
			&game->wall->w, &game->wall->h);
	if (game->wall->img == NULL)
		game_close(1, game);
	game->food->img = mlx_xpm_file_to_image(game->mlx, "imgs/foodM.xpm",
			&game->food->w, &game->food->h);
	if (game->wall->img == NULL)
		game_close(1, game);
	game->exit->img = mlx_xpm_file_to_image(game->mlx, "imgs/exitM.xpm",
			&game->exit->w, &game->exit->h);
	if (game->exit->img == NULL)
		game_close(1, game);
}

void	init_game(t_game *game)
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
	game->move_cnt = 0;
	game->food_cnt = 0;
	game->exit_cnt = 0;
	game->pers_cnt = 0;
	game->did_move = 0;
	game->eat_food = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->h = 0;
	game->w = 0;
	game->need_clear = 0;
}

t_game	*init_mem(char **av)
{
	t_game	*game;

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
	t_game	*game;

	if (ac != 2)
		game_close(6, NULL);
	game = init_mem(av);
	read_map(game, av[1]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->w * 50, game->h * 50,
			"so_long");
	init_imgs(game);
	mlx_hook(game->win, 2, 1L << 0, key, game);
	mlx_hook(game->win, 17, 1L << 2, button, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
	return (0);
}
