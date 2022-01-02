/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:01:46 by wadina            #+#    #+#             */
/*   Updated: 2022/01/02 02:01:48 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**get_names_tank(t_game	*game)
{
	int		i;
	char	**tanks;

	i = 0;
	tanks = ft_calloc(sizeof(char*), 9);
	if (!tanks)
		game_close(1, game);
	tanks[0] = ft_strdup("imgs/tank00.xpm");
	if (!tanks[0])
		game_close(1, game);
	tanks[1] = ft_strdup("imgs/tank10.xpm");
	if (!tanks[1])
		game_close(1, game);
	tanks[2] = ft_strdup("imgs/tank20.xpm");
	if (!tanks[2])
		game_close(1, game);
	tanks[3] = ft_strdup("imgs/tank30.xpm");
	if (!tanks[3])
		game_close(1, game);
	tanks[4] = ft_strdup("imgs/tank01.xpm");
	if (!tanks[4])
		game_close(1, game);
	tanks[5] = ft_strdup("imgs/tank11.xpm");
	if (!tanks[5])
		game_close(1, game);
	tanks[6] = ft_strdup("imgs/tank21.xpm");
	if (!tanks[6])
		game_close(1, game);
	tanks[7] = ft_strdup("imgs/tank31.xpm");
	if (!tanks[7])
		game_close(1, game);
	return (tanks);
}

static void get_tank(t_game *game)
{
	int i;
	char **s;
	s = get_names_tank(game);
	i = 0;
	while (i < 8)
	{
		game->tank[i] = (t_img*)ft_calloc(sizeof(t_img), 1);
		if (!game->tank[i])
			game_close(3, game);
		game->tank[i]->img = mlx_xpm_file_to_image(game->mlx, s[i], &game->tank[i]->width , &game->tank[i]->height);
		if (game->tank[i]->img == NULL)
			game_close(4, game);
		i++;
	}
	i = 0;
	while (i < 8)
		free(s[i++]);
	free(s);
}

char	**get_names_fuel(t_game	*game)
{
	int		i;
	char	**fuels;

	i = 0;
	fuels = ft_calloc(sizeof(char*), 9);
	if (!fuels)
		game_close(3, game);
	fuels[0] = ft_strdup("imgs/fuel1.xpm");
	if (!fuels[0])
		game_close(3, game);
	fuels[1] = ft_strdup("imgs/fuel2.xpm");
	if (!fuels[1])
		game_close(3, game);
	fuels[2] = ft_strdup("imgs/fuel3.xpm");
	if (!fuels[2])
		game_close(3, game);
	fuels[3] = ft_strdup("imgs/fuel4.xpm");
	if (!fuels[3])
		game_close(3, game);
	fuels[4] = ft_strdup("imgs/fuel5.xpm");
	if (!fuels[4])
		game_close(3, game);
	fuels[5] = ft_strdup("imgs/fuel6.xpm");
	if (!fuels[5])
		game_close(3, game);
	fuels[6] = ft_strdup("imgs/fuel7.xpm");
	if (!fuels[6])
		game_close(3, game);
	fuels[7] = ft_strdup("imgs/fuel8.xpm");
	if (!fuels[7])
		game_close(3, game);
	return (fuels);
}

static void get_fuel(t_game *game)
{
	int i;
	char **s;
	s = get_names_fuel(game);
	i = 0;
	while (i < 8)
	{
		game->fuel[i] = (t_img*)ft_calloc(sizeof(t_img), 1);
		if (!game->fuel[i])
			game_close(3, game);
		game->fuel[i]->img = mlx_xpm_file_to_image(game->mlx, s[i], &game->fuel[i]->width , &game->fuel[i]->height);
		if (game->fuel[i]->img == NULL)
			game_close(4, game);
		i++;
	}
	i = 0;
	while (i < 8)
		free(s[i++]);
	free(s);
}

void init_imgs(t_game *game)
{
	
	get_tank(game);
	
	get_fuel(game);
	game->space->img = mlx_xpm_file_to_image(game->mlx, "imgs/grass.xpm", &game->space->width, &game->space->height);
	if (game->space->img == NULL)
		game_close(4, game);
	game->wall->img = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &game->wall->width, &game->wall->height);
	if (game->wall->img == NULL)
		game_close(4, game);
	game->mine->img = mlx_xpm_file_to_image(game->mlx, "imgs/mine.xpm", &game->mine->width, &game->mine->height);
	if (game->mine->img == NULL)
		game_close(4, game);
	game->exit->img = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &game->exit->width, &game->exit->height);
	if (game->exit->img == NULL)
		game_close(4, game);
}



void init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->space = NULL;
	game->wall = NULL;
	game->tank = NULL;
	game->fuel = NULL;
	game->exit = NULL;
	game->mine = NULL;
	game->map_name = NULL;
	game->map = NULL;
	game->mines = NULL;
	game->moveCnt = 0;
	game->foodCnt = 0;
	game->exitCnt = 0;
	game->persCnt = 0;
	game->didMove = 0;
	game->eatFood = 0;
	game->enemyCnt = 0;
	game->h = 0;
	game->w = 0;
	game->needClear = 0;
	game->pX = 0;
	game->pY = 0;
	game->i = 1;
	game->j = 0;
	game->pD = 0;
}

t_game *init_mem(char **av)
{
	t_game *game;
	
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		game_close(3, game);
	init_game(game);
	game->space = ft_calloc(sizeof(t_img), 1);
	if (!game->space)
		game_close(3, game);
	game->wall = ft_calloc(sizeof(t_img), 1);
	if (!game->wall)
		game_close(3, game);
	game->tank = ft_calloc(sizeof(t_img*), 9);
	if (!game->tank)
		game_close(3, game);
	game->fuel = ft_calloc(sizeof(t_img*), 12);
	if (!game->fuel)
		game_close(3, game);
	game->exit = ft_calloc(sizeof(t_img), 1);
	if (!game->exit)
		game_close(3, game);
	game->mine = ft_calloc(sizeof(t_img), 1);
	if (!game->mine)
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
	game->win = mlx_new_window(game->mlx, game->w * 100, game->h * 100, "so_long");
	init_imgs(game);
	mlx_hook(game->win, 2, 1L<<0, key, game);
	mlx_hook(game->win, 17, 1L<<2, button, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
	return 0;
}
