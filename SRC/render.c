/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:00:34 by wadina            #+#    #+#             */
/*   Updated: 2022/01/02 02:00:35 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_rectange(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->space->img, x * 50,
		y * 50);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall->img, x * 50,
			y * 50);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->food->img, x * 50,
			y * 50);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit->img, x * 50,
			y * 50);
}

int	render(t_game *game)
{
	int	y;
	int	x;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			draw_rectange(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->pers->img,
		game->p_x * 50, game->p_y * 50);
	return (0);
}
