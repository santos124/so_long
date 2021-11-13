#ifndef SO_LONG_H
# define SO_LONG_H
# define SCREEN_H 600
# define SCREEN_W 800

//del before push 21
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	"../SRC_0/libft/libft.h"
# include	"../SRC_0/minilibx_opengl_20191021/mlx.h"
// #include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


#endif