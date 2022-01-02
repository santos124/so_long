/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:02:07 by wadina            #+#    #+#             */
/*   Updated: 2022/01/02 02:02:09 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	food(t_game	*game, int	px, int	py)
{
	mlx_put_image_to_window(game->mlx, game->win, game->fuel[game->i / 8]->img, px, py);
	game->j += 2;
	if (game->j > 62)
		game->j = 0;
}

void	enemy(t_game	*game)
{
	int i = -1;

	while (++i < game->enemyCnt)
	{
		if (game->mines[i]->d == 0)
		{
			if (game->i == 2)
			{
				if (game->map[game->mines[i]->y - 1][game->mines[i]->x] == '1')
					game->mines[i]->d = 1;
				else
					game->mines[i]->y -= 1;
			}
		}
		else
		{
			if (game->i == 2)
			{
				if (game->map[game->mines[i]->y + 1][game->mines[i]->x] == '1')
					game->mines[i]->d = 0;
				else
					game->mines[i]->y += 1;
			}
		}
		mlx_put_image_to_window(game->mlx, game->win, game->mine->img, game->mines[i]->x * 100, game->mines[i]->y * 100);
		if (game->pX == game->mines[i]->x && game->pY == game->mines[i]->y)
			game_close(7, game);
	}
}

void draw_rectange(t_game *game, int x, int y, char block)
{
	int dx;
	int dy;

	dx = x * 100;
	dy = y * 100;
	mlx_put_image_to_window(game->mlx, game->win, game->space->img, dx, dy);
	if (block == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall->img, dx, dy);
	else if (block == 'C')
		food(game, dx, dy);		
	else if (block == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit->img, dx, dy);
}

void	pers(t_game *game)
{
	if (game->i > 25)
		mlx_put_image_to_window(game->mlx, game->win, game->tank[0 + game->pD]->img, game->pX * 100, game->pY * 100);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->tank[4 + game->pD]->img, game->pX * 100, game->pY * 100);
	game->i++;
	if (game->i > 50)
		game->i = 0;
}

int	render(t_game *game)
{
	int		y;
	int		x;
	char	*str;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while(x < game->w)
		{
			draw_rectange(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
	pers(game);
	enemy(game);
	str = ft_itoa(game->moveCnt);
	if (!str)
		game_close(2, game);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFF0000, "MOVES");
	mlx_string_put(game->mlx, game->win, 50, 10, 0xFF0000, str);
	free(str);
	return (0);
}
