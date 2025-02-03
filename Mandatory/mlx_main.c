#include "so_long.h"

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1920, 1080, "taha");
	void *img = mlx_xpm_file_to_image(mlx, "sa.xpm", 32, 32);
	mlx_put_image_to_window(mlx, win, img, 0 , 0);
	mlx_loop(mlx);
}