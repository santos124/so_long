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

static	void	errorer(const char *s, int err)
{
	ft_putendl_fd((char *)s, 2);
	exit(err);
}

void	game_close(int err, t_game *game)
{
	if (err == 6)
		errorer("Error\nNeed map name", 6);
	liberator(game);
	if (err == 1)
		errorer("Error\nOpen error", 1);
	if (err == 2)
		errorer("Error\nRead error", 2);
	if (err == 3)
		errorer("Error\nMalloc error", 3);
	if (err == 4)
		errorer("Error\nValid map error", 4);
	if (err == 5)
		errorer("Game interupted of ESC", 5);
	if (err == 7)
		errorer("Game over", 7);
	if (err == 0)
		errorer("Game done", 0);
	exit(0);
}

void	check_pointer(void *ptr, int err, t_game *game)
{
	if (!ptr)
		game_close(err, game);
}

int	button(t_game *game)
{
	game_close(0, game);
	return (0);
}
