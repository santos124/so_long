#ifndef SO_LONG_H
# define SO_LONG_H
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	"../SRC_0/libft/libft.h"
# include	"../SRC_0/minilibx_opengl_20191021/mlx.h"

typedef struct	s_img {
	void	*img;
	int		width;
	int		height;
}				t_img;

// typedef struct	s_tank {
// 	t_img	*img00;
// 	t_img	*img10;
// 	t_img	*img20;
// 	t_img	*img30;
// 	t_img	*img01;
// 	t_img	*img11;
// 	t_img	*img21;
// 	t_img	*img31;
// }				t_tank;

// typedef struct	s_fuel {
// 	t_img	**img1;
// 	t_img	*img2;
// 	t_img	*img3;
// 	t_img	*img4;
// 	t_img	*img5;
// 	t_img	*img6;
// 	t_img	*img7;
// 	t_img	*img8;
// 	t_img	*img9;
// 	t_img	*img10;
// 	t_img	*img11;
// }				t_fuel;

typedef struct s_enemy {
	int		x;
	int		y;
	int		d;
}				t_enemy;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	t_img	*space;
	t_img	*wall;
	t_img	*exit;
	t_img	**tank;
	t_img	**fuel;
	t_img	*mine;
	t_enemy	**mines;
	char	*map_name;
	char	**map;
	int		h;
	int		w;
	int		moveCnt;
	int		foodCnt;
	int		exitCnt;
	int		persCnt;
	int		enemyCnt;
	int		pX;
	int		pY;
	int		didMove;
	int		eatFood;
	int		needClear;	
	int		i;
	int		j;
	int		pD;
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
int	render(t_game *game);


#endif