#include "../include/fractol.h"

static void	set_data(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->set = 0;
	f->color = WHITE;
	f->iterations = 50;
	f->julia_x = 0.0;
	f->julia_y = 0.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	f->img.img_ptr = NULL;
	f->img.pixels_ptr = NULL;
}

static void	set_name(t_fractol *f, char *av)
{
	int	i;
	int	size_av;

	size_av = ft_strlen(av);
	i = -1;
	while (av[++i])
		av[i] = ft_tolower(av[i]);
	if (!ft_strncmp("mandelbrot", av, 10) && size_av == 10)
		f->set = MANDELBROT;
	else if (!ft_strncmp("julia", av, 5) && size_av == 5)
		f->set = JULIA;
	else if (!ft_strncmp("burning_ship", av, 12) && size_av == 12)
		f->set = BURNING_SHIP;
	else
		handle_error(f, ERROR_MSG, EXIT_FAILURE);
}

static void	check_args(t_fractol *f, char **av, int ac)
{
	if (f->set != JULIA && ac > 2)
		handle_error(f, ERROR_MSG, EXIT_FAILURE);
	else if (f->set == JULIA && (ac == 2 || ac == 4))
	{
		if (ac == 2)
		{
			f->julia_x = -0.835;
			f->julia_y = -0.2321;
		}
		else if (ac == 4)
		{
			f->julia_x = ft_atof(av[2]);
			f->julia_y = ft_atof(av[3]);
			if ((f->julia_x >= 2 || f->julia_x <= -2)
				|| (f->julia_y >= 2 || f->julia_y <= -2))
				handle_error(f, ERROR_MSG, EXIT_FAILURE);
		}
	}
	else if (f->set == JULIA && (ac != 2 || ac != 4))
		handle_error(f, ERROR_MSG, EXIT_FAILURE);
}

int	main(int ac, char *av[])
{
	t_fractol	f;

	set_data(&f);
	if (ac < 2)
		handle_error(&f, ERROR_MSG, EXIT_FAILURE);
	set_name(&f, av[1]);
	check_args(&f, av, ac);
	init_fractol(&f);
	help_msg();
	render(&f);
	mlx_loop(f.mlx);
}
