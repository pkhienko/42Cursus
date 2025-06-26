#include "../include/fractol.h"

void	handle_error(t_fractol *f, char *error_str, int exit_code)
{
	if (error_str)
		ft_putstr_fd(error_str, STDERR_FILENO);
	if (!f)
		exit(exit_code);
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx, f->img.img_ptr);
	if (f->mlx && f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
}

void	help_msg(void)
{
	ft_printf(BG"\n+================ Controls ================+\n");
	ft_printf(DY" Move:           W, A, S, D or Arrow Keys\n");
	ft_printf(" Zoom In/Out:    Scroll Mouse Wheel Up/Down\n");
	ft_printf(" Change Color:   Space Bar\n");
	ft_printf(" Iterations:     + or - \n");
	ft_printf(" Reset Fractal:  R \n");
	ft_printf(" Switch Fractal: 1, 2, 3 \n");
	ft_printf(" Rotate Julia:   Left/Right Mouse Click\n");
	ft_printf(" Quit:           ESC, X, or ^C\n");
	ft_printf(DG"+==========================================+\n"R);
}
