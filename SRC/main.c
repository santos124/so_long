#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void f_init_window(void **mlx, void **mlx_win, t_data *img)
{
	*mlx = mlx_init();
	*mlx_win = mlx_new_window(*mlx, SCREEN_W, SCREEN_H, "so_long!");
	img->img = mlx_new_image(*mlx, SCREEN_W, SCREEN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void f_draw(void	*mlx, void	*mlx_win, t_data	*img)
{
	int pic[SCREEN_H][SCREEN_W];
	int i = 0;
	int j = 0;

	while (i < SCREEN_H)
	{
		j = 0;	
		while (j < SCREEN_W)
		{
			pic[i][j] = 0xffffff - j;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			my_mlx_pixel_put(img, j, i, pic[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}

void f_draw2(void	*mlx, void	*mlx_win, t_data	*img)
{
	int pic[SCREEN_H][SCREEN_W];
	int i = 0;
	int j = 0;

	while (i < SCREEN_H)
	{
		j = 0;	
		while (j < SCREEN_W)
		{
			pic[i][j] = 0xffffff +i * 100;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			my_mlx_pixel_put(img, j, i, pic[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;

	img = malloc(sizeof(t_data));
	f_init_window(&mlx, &mlx_win, img);
	
	
	f_draw2(mlx, mlx_win, img);
	mlx_loop(mlx);
	f_draw(mlx, mlx_win, img);
	mlx_loop(mlx);
	free(img);
}