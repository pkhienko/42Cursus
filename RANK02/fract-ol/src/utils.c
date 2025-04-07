#include "../include/fractol.h"

double	ft_atof(char *s)
{
	int		sign;
	double	nb;
	double	div;

	nb = 0.0;
	sign = 1;
	div = 0.1;
	while ((*s >= 0 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	while (*s && ft_isdigit(*s) && *s != '.')
		nb = nb * 10.0 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s && ft_isdigit(*s))
	{
		nb += (*s++ - '0') * div;
		div *= 0.1;
	}
	return (nb * sign);
}

double	map(double value, double new[2], double old[2])
{
	return ((new[1] - new[0]) * (value - old[0]) / (old[1] - old[0]) + new[0]);
}

int	get_fractal(t_fractol *f, t_complex *z, t_complex *c)
{
	int	i;


	if (f->set == MANDELBROT)
		i = mandelbrot_set(f, z, c);
	else if (f->set == JULIA)
		i = julia_set(f, z);
	else if (f->set == BURNING_SHIP)
		i = burning_ship(f, z, c);
	return (i);
}

int	julia_track(int button, int x, int y, t_fractol *f)
{
	if (button == Button1 || button == Button3)
	{
		f->julia_x = (map(x, (double [2]){-2, 2},
					(double [2]){0, WIDTH}) * f->zoom) + f->shift_x;
		f->julia_y = (map(y, (double [2]){2, -2},
					(double [2]){0, HEIGHT}) * f->zoom) + f->shift_y;
		render(f);
	}
	return (0);
}
