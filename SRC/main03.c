#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./pers.xpm";
	void	*win;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	win = mlx_new_window(mlx, SCREEN_W, SCREEN_H, BORDER_TXT);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	// mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(mlx);

}