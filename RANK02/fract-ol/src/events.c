#include "../include/fractol.h"

int	close_event(t_fractol *f)
{
	handle_error(f, NULL, EXIT_SUCCESS);
	return (0);
}

static void	select_fractal(int keycode, t_fractol *f)
{
	if (keycode == XK_1 && f->set != MANDELBROT)
		f->set = MANDELBROT;
	else if (keycode == XK_2 && f->set != JULIA)
		f->set = JULIA;
	else if (keycode == XK_3 && f->set != BURNING_SHIP)
		f->set = BURNING_SHIP;
	else
		return ;
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
}

static void	reset_fractal(t_fractol *f)
{
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
}

int	key_event(int keycode, t_fractol *f)
{
	if (keycode == XK_Escape)
		close_event(f);
	if (keycode == XK_Left || keycode == XK_a)
		f->shift_x -= (0.5 * f->zoom);
	else if (keycode == XK_Right || keycode == XK_d)
		f->shift_x += (0.5 * f->zoom);
	else if (keycode == XK_Up || keycode == XK_w)
		f->shift_y += (0.5 * f->zoom);
	else if (keycode == XK_Down || keycode == XK_s)
		f->shift_y -= (0.5 * f->zoom);
	else if (keycode == XK_plus || keycode == XK_equal || keycode == XK_KP_Add)
		f->iterations += 5;
	else if (keycode == XK_minus || keycode == XK_underscore
		|| keycode == XK_KP_Subtract)
		f->iterations -= 5;
	else if (keycode == XK_space)
		shift_color(f);
	else if (keycode == XK_1 || keycode == XK_2 || keycode == XK_3)
		select_fractal(keycode, f);
	else if (keycode == XK_r)
		reset_fractal(f);
	else
		return (0);
	render(f);
	return (0);
}

int	mouse_event(int button, int x, int y, t_fractol *f)
{
    double	mouse_x;
    double	mouse_y;

	mouse_x = ((x / (double)WIDTH) * 4 - 2) * f->zoom + f->shift_x;
	mouse_y = ((y / (double)HEIGHT) * -4 + 2) * f->zoom + f->shift_y;
    if (f->set == JULIA)
        julia_track(button, x, y, f);
    if (button == Button4)
    {
		f->zoom *=	0.75;
		f->shift_x = mouse_x - ((x / (double)WIDTH) * 4 - 2) * f->zoom;
		f->shift_y = mouse_y - ((y / (double)HEIGHT) * -4 + 2) * f->zoom;
    }
    else if (button == Button5)
	{
		f->zoom *=	1.25;
		f->shift_x = mouse_x - ((x / (double)WIDTH) * 4 - 2) * f->zoom;
		f->shift_y = mouse_y - ((y / (double)HEIGHT) * -4 + 2) * f->zoom;
	}
	else
		return (0);
	render(f);
	return (0);
}
