#include "../include/fractol.h"

static void	get_complex( t_fractol *f, t_complex *z, t_complex *c)
{
	if (f->set == JULIA && !f->julia_x && !f->julia_y)
	{
		f->julia_x = -0.835;
		f->julia_y = -0.2321;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

static void	put_pixel(t_fractol *f, int x, int y, int color)
{
	int	offset;

	offset = (y * f->img.line_bytes) + (x * (f->img.bpp / 8));
	*(unsigned int *)(f->img.pixels_ptr + offset) = color;
}

static t_complex	map_fractal(t_fractol *f, int x, int y)
{
	t_complex	z;

	if (f->set != BURNING_SHIP)
	{
		z.r = (map(x, (double [2]){-2, 2},
					(double [2]){0, WIDTH}) * f->zoom) + f->shift_x;
		z.i = (map(y, (double [2]){2, -2},
					(double [2]){0, HEIGHT}) * f->zoom) + f->shift_y;
	}
	else
	{
		z.r = (map(x, (double [2]){-2, 2},
					(double [2]){0, WIDTH}) * f->zoom) + f->shift_x;
		z.i = (map(y, (double [2]){-2, 2},
					(double [2]){0, HEIGHT}) * f->zoom) + f->shift_y;
	} 
	return (z);
}

static void	calculate_fractal(t_fractol *f, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z = map_fractal(f, x, y);
	get_complex(f, &z, &c);
	i = get_fractal(f, &z, &c);
	if (i != f->iterations)
	{
		color = get_color(BLACK, f->color, (double)i / f->iterations);
		put_pixel(f, x, y, color);
		return ;
	}
	put_pixel(f, x, y, BLACK);
}

void	render(t_fractol *f)
{
	int			x;
	int			y;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			calculate_fractal(f, x, y);
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}
