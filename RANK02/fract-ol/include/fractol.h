/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:36:08 by pkhienko          #+#    #+#             */
/*   Updated: 2024/11/04 22:06:58 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"
# include "color.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <math.h>

# define ERROR_MSG "\033[1;31m+=========== ERROR WRONG COMMAND ===========+ \
\n\033[33m   Please enter:\n       ./fractol mandelbrot    or\n       ./fractol burning_ship  or\n       ./fractol julia <real>  <imaginary> \
\n\n   Examples:\n       ./fractol mandelbrot\n       ./fractol julia -0.4    +0.6\n       ./fractol julia -0.835  -0.2321 \
\n\033[31m+===========================================+\033[0m\n"

# define WIDTH 800
# define HEIGHT 800

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_bytes;
}	t_image;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		set;
	int		color;
	int		iterations;
	double	julia_x;
	double	julia_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
	t_image	img;

}	t_fractol;

// init_fractol
void		init_fractol(t_fractol *f);

// render
void		render(t_fractol *f);

// events
int			close_event(t_fractol *f);
int			key_event(int keycode, t_fractol *f);
int			mouse_event(int button, int x, int y, t_fractol *f);

// fractal_set
int			julia_set(t_fractol *f, t_complex *z);
int			burning_ship(t_fractol *f, t_complex *z, t_complex *c);
int			mandelbrot_set(t_fractol *f, t_complex *z, t_complex *c);

// color
void		shift_color(t_fractol *f);
int			get_color(int color1, int color2, double t);

// utils
double		ft_atof(char *s);
double		map(double value, double new[2], double old[2]);
int			julia_track(int button, int x, int y, t_fractol *f);
int			get_fractal(t_fractol *f, t_complex *z, t_complex *c);

// handle_error
void		help_msg(void);
void		handle_error(t_fractol *f, char *error_str, int exit_code);

#endif