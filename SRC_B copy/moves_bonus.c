/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:01:53 by wadina            #+#    #+#             */
/*   Updated: 2022/01/02 02:01:54 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int key(int keycode, t_game *game)
{
	game->moveCnt++;
	game->eatFood = 0;
	if (keycode == 53)
		game_close(5, game);
	else if (keycode == 0)
		dir_left(game);
	else if (keycode == 1)
		dir_down(game);
	else if (keycode == 2)
		dir_right(game);
	else if (keycode == 13)
		dir_up(game);
	else
		return(0);
	if (game->foodCnt == 0 && game->map[game->pY][game->pX] == 'E')
		game_close(0, game);
	return (0);
}

void dir_left(t_game *game)
{
	game->pD = 1;
	if (game->pX > 0)
	{
		if (game->map[game->pY][game->pX - 1] == 'C')
		{
			game->eatFood++;
			game->foodCnt--;
			game->map[game->pY][game->pX - 1] = '0';
		}
		if (game->map[game->pY][game->pX - 1] != '1')
		{
			game->pX--;
			game->didMove = 1;
		}
		else
		{
			game->didMove = 0;
			game->moveCnt--;
		}
	}
}

void dir_right(t_game *game)
{
	game->pD = 3;
	if (game->pX < game->w - 1)
	{
		if (game->map[game->pY][game->pX + 1] == 'C')
		{
			game->eatFood++;
			game->foodCnt--;
			game->map[game->pY][game->pX + 1] = '0';
		}
		if (game->map[game->pY][game->pX + 1] != '1')
		{
			game->pX++;
			game->didMove = 1;
		}
		else
		{
			game->didMove = 0;
			game->moveCnt--;
		}
	}
}

void dir_down(t_game *game)
{
	game->pD = 2;
	if (game->pY < game->h - 1)
	{
		if (game->map[game->pY + 1][game->pX] == 'C')
		{
			game->eatFood++;
			game->foodCnt--;
			game->map[game->pY + 1][game->pX] = '0';
		}
		if (game->map[game->pY + 1][game->pX] != '1')
		{
			game->pY++;
			game->didMove = 1;
		}
		else
		{
			game->didMove = 0;
			game->moveCnt--;
		}
	}
}

void dir_up(t_game *game)
{
	game->pD = 0;
	if (game->pY > 0)
	{
		if (game->map[game->pY - 1][game->pX] == 'C')
		{
			game->eatFood++;
			game->foodCnt--;
			game->map[game->pY - 1][game->pX] = '0';
		}
		if (game->map[game->pY - 1][game->pX] != '1')
		{
			game->pY--;
			game->didMove = 1;
		}
		else
		{
			game->didMove = 0;
			game->moveCnt--;
		}
	}
}
