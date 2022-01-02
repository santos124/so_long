/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:01:30 by wadina            #+#    #+#             */
/*   Updated: 2022/01/02 02:01:31 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void game_close(int err, t_game *game)
{
	if (err == 6)
	{
		ft_putendl_fd("Error\nNeed map name", 2);
		exit(6);
	}
	
	liberator(game);
	if (err == 1)
	{
		ft_putendl_fd("Error\nOpen error", 2);
		exit(1);
	}
	if (err == 2)
	{
		ft_putendl_fd("Error\nRead error", 2);
		exit(2);
	}
	if (err == 3)
	{
		ft_putendl_fd("Error\nMalloc error", 2);
		exit(3);
	}
	if (err == 4)
	{
		ft_putendl_fd("Error\nValid map error", 2);
		exit(4);
	}
	if (err == 5)
	{
		ft_putendl_fd("Game interupted of ESC", 2);
		exit(5);
	}
	if (err == 7)
	{
		ft_putendl_fd("Game over", 2);
		exit(7);
	}
	if (err == 0)
		ft_putendl_fd("Game done", 2);
	exit(0);
}

int button(t_game *game)
{
	game_close(0, game);
	return 0;
}