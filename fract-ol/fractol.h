/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:41:18 by tmoeller          #+#    #+#             */
/*   Updated: 2024/06/14 18:30:18 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft_ext/libft_ext.h"
# include "minilibx/mlx.h"

# include <math.h>
# include <stdlib.h>

// ADJUSTABLES
# define COLOR_CODE 0x0000CD
# define SIZE 1000
# define MAX_ITERATIONS 42

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

// compute.c
void	compute_mandelbrot(t_fractal *fractal);
void	compute_julia(t_fractal *fractal);

// draw.c
int		draw_fractal(t_fractal *fractal, char *input);
void	*draw_mandelbrot(void *fractal_void);
void	draw_julia(t_fractal *fractal);
void	draw_first_fractal(t_fractal *fractal, int argc, char **argv);
void	draw_first_julia(t_fractal *fractal, int argc, char **argv);

// events.c
void	zoom(t_fractal *fractal, int x, int y, int zoom);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

// inits.c
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);

// main.c
int		main(int argc, char **argv);

//tools.c
void	color_pixel(t_fractal *fractal, int x, int y, int color);
int		exit_fractal(t_fractal *fractal);
double	ft_atod(char *s);

#endif
