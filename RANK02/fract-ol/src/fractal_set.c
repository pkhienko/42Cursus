#include "../include/fractol.h"

int	mandelbrot_set(t_fractol *f, t_complex *z, t_complex *c)
{
	double	tmp;
	int		i;

	i = -1;
	while (++i < f->iterations)
	{
		if ((z->r * z->r + z->i * z->i) > 4)
			break ;
		tmp = (z->r * z->r) - (z->i * z->i) + c->r;
		z->i = 2 * z->r * z->i + c->i;
		z->r = tmp;
	}
	return (i);
}

int	julia_set(t_fractol *f, t_complex *z)
{
	double	tmp;
	int		i;

	i = -1;
	while (++i < f->iterations)
	{
		if ((z->r * z->r + z->i * z->i) > 4)
			break ;
		tmp = (z->r * z->r) - (z->i * z->i) + f->julia_x;
		z->i = 2 * z->r * z->i + f->julia_y;
		z->r = tmp;
	}
	return (i);
}

int	burning_ship(t_fractol *f, t_complex *z, t_complex *c)
{
	double	tmp;
	int		i;

	i = -1;
	while (++i < f->iterations)
	{
		if ((z->r * z->r + z->i * z->i) > 4)
			break ;
		z->r = fabs(z->r);
		z->i = fabs(z->i);
		tmp = (z->r * z->r) - (z->i * z->i) + c->r;
		z->i = 2 * z->r * z->i + c->i;
		z->r = tmp;
	}
	return (i);
}
