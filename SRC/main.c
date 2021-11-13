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
			pic[i][j] = 0xffffff +i * 10;
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

int ft_close(int code, t_vars *vars)
{
	(void)vars;
	printf("HE, code=%d\n", code);
	if (code == 53)
		exit(0);
	return 0;
}

int	render_next_frame(t_data *img)
{
	int pic[SCREEN_H][SCREEN_W];
	int i = 0;
	int j = 0;

	while (i < SCREEN_H)
	{
		j = 0;	
		while (j < SCREEN_W)
		{
			pic[i][j] = 0xffffff +i * 10;
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
	return 0;
}

int	ren_frame(t_data *img)
{
	my_mlx_pixel_put(img, 100, 100, 0xffffff);
	my_mlx_pixel_put(img, 102, 102, 0xffffff);
	my_mlx_pixel_put(img, 104, 104, 0xffffff);
	my_mlx_pixel_put(img, 106, 106, 0xffffff);
	my_mlx_pixel_put(img, 108, 108, 0xffffff);
	return 0;
}

int	main(void)
{
	t_vars	*vars = malloc(sizeof(t_vars));
	t_data	*img = malloc(sizeof(t_data));

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SCREEN_W, SCREEN_H, "Hello world!");
	img->img = mlx_new_image(vars->mlx, SCREEN_W, SCREEN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	// f_draw2(vars->mlx, vars->win, &img);
	// mlx_key_hook(vars->win, key_hook, vars);
	// mlx_hook(vars->win, 2, 1L<<0, ft_close, &vars);
	// mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop_hook(vars->mlx, ren_frame, img);
	
	mlx_loop(vars->mlx);
	
}