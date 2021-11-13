#include "so_long.h"

int	ft_close(int keycode, t_vars *vars)
{
	printf("KEycode=%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
		
	return 0;
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ff_init_window(t_vars *vars)
{

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 600, "Hello world!");
	// mlx_key_hook(vars->win, key_hook, vars);
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

int	main(void)
{
	t_vars	*vars;


	vars = malloc(sizeof(t_vars));
	ff_init_window(vars);
	mlx_hook(vars->win, 2, 1L<<0, ft_close, vars);
	mlx_loop(vars->mlx);
	printf("New image\n");
	free(vars);
}

