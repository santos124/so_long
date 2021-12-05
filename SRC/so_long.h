#ifndef SO_LONG_H
# define SO_LONG_H
# define SCREEN_H 600
# define SCREEN_W 800
# define BORDER_TXT "exit=esc, move=wasd"
# define STDIN 0
# define STDOUT 1
# define SIZE_BLOCK 50
//del before push 21
# include	<stdio.h>
//del before push 21
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	"../SRC_0/libft/libft.h"
# include	"../SRC_0/minilibx_opengl_20191021/mlx.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		width;
	int		height;
}				t_img;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	t_img	*space;
	t_img	*wall;
	t_img	*food;
	t_img	*exit;
	t_img	*pers;
	char	*map_name;
	char	**map;
}				t_game;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


// typedef struct	s_game {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	void	*mlx;
// 	void	*win;
// 	char	*map_name;
// 	char	**map;
// }				t_game;


#endif