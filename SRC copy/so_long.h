/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:00:42 by wadina            #+#    #+#             */
/*   Updated: 2022/01/02 02:00:44 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	"../libft/libft.h"
# include	"../mlx/mlx.h"

typedef struct s_img {
	void	*img;
	int		w;
	int		h;
}				t_img;

typedef struct s_game {
	void	*mlx;
	void	*win;
	t_img	*space;
	t_img	*wall;
	t_img	*food;
	t_img	*exit;
	t_img	*pers;
	char	*map_name;
	char	**map;
	int		move_cnt;
	int		food_cnt;
	int		exit_cnt;
	int		pers_cnt;
	int		did_move;
	int		eat_food;
	int		p_x;
	int		p_y;
	int		h;
	int		w;
	int		need_clear;	
}				t_game;

void	game_close(int err, t_game *game);
void	read_map(t_game *game, char *map_name);
void	valid_map(t_game *game);
void	write_map(t_game	*game);
void	food_check(t_game	*game);
void	pers_find(t_game *game);
int		key(int keycode, t_game *game);
void	dir_left(t_game *game);
void	dir_right(t_game *game);
void	dir_down(t_game *game);
void	dir_up(t_game *game);
int		button(t_game *game);
void	liberator(t_game	*game);
int		render(t_game *game);

#endif
