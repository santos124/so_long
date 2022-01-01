#include "so_long.h"

static void draw_rectange(t_game *game, int x, int y, char block)
{
	int dx;
	int dy;

	dx = x * 50;
	dy = y * 50;
	mlx_put_image_to_window(game->mlx, game->win, game->space->img, dx, dy);
	if (block == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall->img, dx, dy);
	else if (block == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->food->img, dx, dy);
	else if (block == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit->img, dx, dy);
}


int	render(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while(x < game->w)
		{
			draw_rectange(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->pers->img, game->pX * 50, game->pY * 50);
	return (0);
}
