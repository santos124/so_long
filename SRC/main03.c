#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
			pic[i][j] = 0xffffff - j * 1000;
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

int key_hook(int code, t_vars *vars)
{
	(void)vars;
	printf("HE, code=%d\n", code);
	return 0;
}

int	main(void)
{
	t_vars	*vars = malloc(sizeof(t_vars));
	t_data	img;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SCREEN_W, SCREEN_H, "Hello world!");
	img.img = mlx_new_image(vars->mlx, SCREEN_W, SCREEN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	f_draw(vars->mlx, vars->win, &img);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
	
}