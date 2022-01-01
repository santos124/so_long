#include "so_long.h"

void	food(t_game	*game, int	px, int	py)
{
	mlx_put_image_to_window(game->mlx, game->win, game->fuel[game->i / 8]->img, px, py);
	game->j += 2;
	if (game->j > 62)
		game->j = 0;
}

void draw_rectange(t_game *game, int x, int y, char block)
{
	int dx;
	int dy;

	dx = x * 100;
	dy = y * 100;
	mlx_put_image_to_window(game->mlx, game->win, game->space->img, dx, dy);
	if (block == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall->img, dx, dy);
	else if (block == 'C')
		food(game, dx, dy);		
	else if (block == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit->img, dx, dy);
	
}

void	pers(t_game *game)
{


	if (game->i > 25)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tank[0 + game->pD]->img, game->pX * 100, game->pY * 100);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tank[4 + game->pD]->img, game->pX * 100, game->pY * 100);
	}
	game->i++;
	if (game->i > 50)
		game->i = 0;
	
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
	pers(game);

	return (0);
}
