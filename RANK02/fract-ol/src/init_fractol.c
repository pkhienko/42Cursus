#include "../include/fractol.h"

void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		handle_error(f, "MLX: Failed to initialize MLX.", EXIT_FAILURE);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!f->win)
		handle_error(f, "MLX: Failed to create a new window.", EXIT_FAILURE);
	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
		handle_error(f, "MLX: Failed to create a new image.", EXIT_FAILURE);
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bpp, &f->img.line_bytes, &f->img.endian);
	mlx_hook(f->win, KeyPress, KeyPressMask, key_event, f);
	mlx_hook(f->win, ButtonPress, ButtonPressMask, mouse_event, f);
	mlx_hook(f->win, DestroyNotify, StructureNotifyMask, close_event, f);
}
