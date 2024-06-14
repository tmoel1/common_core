https://github.com/42Paris/minilibx-linux

https://github.com/PedroZappa/42_fractol?tab=readme-ov-file



#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft_ext/libft_ext.h"
# include "minilibx/mlx.h"

# include <math.h>
# include <stdlib.h>
// # include <pthread.h>

# define SIZE 1000
// # define THREAD_WIDTH 7
// # define THREAD_NUMBER 100

// KEYCODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

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
	int		endian; // used where???????????????????????????????????????????????
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














// below is working as of 1;26 friday

// draw.c

#include "../fractol.h"

void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			compute_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}


void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			compute_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}


// init.c

#include "../fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
}

// main.c

#include "../fractol.h"

//orignal working:
int	draw_fractal(t_fractal *fractal, char *input) // change to user_input? or terminal input?
{
	if (!ft_strncmp(input, "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(input, "julia", 6))
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.70176;
			fractal->cy = -0.3842;
		}
		draw_julia(fractal);
	}
	else
	{
		ft_printf("Please only input mandelbrot or julia for <fractal>\n");
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

#include <stdio.h> // Include necessary headers for printf and atof
#include <stdlib.h> // Include necessary headers for atof
//new fancy:
/*
int	draw_fractal(t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2 || argc > 4) // Check if the number of arguments is correct
	{
		ft_printf("Usage: ./fractol <fractal> [<cx> <cy>]\n");
		exit_fractal(fractal);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
		if (argc == 4) // Check if cx and cy are provided
		{
			fractal->cx = ft_atod(argv[2]);
			fractal->cy = ft_atod(argv[3]);
		}
		else // Default Julia set parameters
		{
			fractal->cx = -0.70176;
			fractal->cy = -0.3842;
		}
		draw_julia(fractal);
	}
	else
	{
		ft_printf("Please only input mandelbrot or julia for <fractal>\n");
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
	return (0);
}
*/

// draw_fractal(fractal, argc, argv)

//oringal working:

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
	{
		ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia");
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	//draw_fractal(fractal, argv[1]);
	draw_first_fractal(fractal, argc, argv);
	mlx_loop(fractal->mlx);
	return (0);
}

/////////////////

void	draw_first_julia(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 4) // Check if cx and cy are provided
	{
		fractal->cx = ft_atod(argv[2]);
		fractal->cy = ft_atod(argv[3]);
	}
	else // Default Julia set parameters
	{
		fractal->cx = -0.70176;
		fractal->cy = -0.3842;
	}
	draw_julia(fractal);
	return ;
}


void	draw_first_fractal(t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2 || argc > 4) // Check if the number of arguments is correct
	{
		ft_printf("Usage: ./fractol <fractal> [<cx> <cy>]\n");
		exit_fractal(fractal);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(argv[1], "julia", 6))
		draw_first_julia(fractal, argc, argv);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
	return ;
}

//////////////////






//new fancy:
/*
int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc >= 2)
	{
		ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia");
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argc, argv);
	mlx_loop(fractal->mlx);
	return (0);
}
*/

// determine_fractal_type



//////////// other option

/*
int	draw_fractal(t_fractal *fractal, char *input)
{
	if (!ft_strncmp(input, "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(input, "julia", 6))
	{
		if (!fractal->cx && !fractal->cy)
		{
			if (argc != 4)
			{
				ft_printf("Usage: ./fractol julia <cx> <cy>\n");
				exit_fractal(fractal);
			}
			fractal->cx = atod(argv[2]);
			fractal->cy = atod(argv[3]);
		}
		draw_julia(fractal);
	}
	else
	{
		ft_printf("Please only input mandelbrot or julia for <fractal>\n");
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
	{
		ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia");
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1], argc, argv);
	mlx_loop(fractal->mlx);
	return (0);
}
*/


// compute_fractals.c

#include "../fractol.h"

/**
 * @brief    Calculates the Mandelbrot fractal for one pixel.
 *
 * The z variables are set to 0, the beginning of the suite.
 *
 * The c constants are set to the coordinates of the pixel.
 *
 * For performance reasons, we use the (x * x) calculation instead of the
 * pow(x, 2) function.
 *
 * The exit conditions of the loop are the following:
 * - The absolute value of z is greater than the system's max values, then
 *   we can assure that the suite will diverge to infinity.
 * - The number of iterations is too high, then we can assure that
 *   the suite will stay stuck in an infinite loop.
 *
 * If the the suite diverges, we color it and multiply the color by the
 * number of iterations to make the mathematical depths more clear to the
 * eye.
 *
 * @param    fractal
 */
void	compute_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "mandelbrot";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
				* i));
}

/**
 * @brief    Calculates the Julia fractal for one pixel.
 *
 * The z variables are set to the coordinates of the pixel.
 *
 * The c constants are set to the provided values, as every value produces
 * a different fractal.
 *
 * @param    fractal
 */
void	compute_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "julia";
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}

// user_inputs.c

#include "../fractol.h"

/**
 * @brief    Zooms or dezooms the fractal.
 *
 * @param    fractal
 * @param    x         The x coordinate of the mouse.
 * @param    y         The y coordinate of the mouse.
 * @param    zoom      1 for zoom, -1 for dezoom.
 */
void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

/**
 * @brief    The handler for keyboard events.
 * 				ESC: exit the program.
 * 				LEFT: move the fractal to the left.
 * 				RIGHT: move the fractal to the right.
 * 				UP: move the fractal up.
 * 				DOWN: move the fractal down.
 * 				R: reset the fractal.
 * 				C: change the color scheme.
 * 				J: set the constants of Julia to random values.
 * 				P: increase the max iterations.
 * 				M: reduce the max iterations.
 *
 * @param    key_code
 * @param    fractal
 */
//old working:

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}


//new fancy:
/*
int key_hook(int key_code, t_fractal *fractal)
{
    if (key_code == ESC)
        exit(1);
    else if (key_code == LEFT)
        fractal->offset_x -= 42 / fractal->zoom;
    else if (key_code == RIGHT)
        fractal->offset_x += 42 / fractal->zoom;
    else if (key_code == UP)
        fractal->offset_y -= 42 / fractal->zoom;
    else if (key_code == DOWN)
        fractal->offset_y += 42 / fractal->zoom;
    else if (key_code == R)
        init_fractal(fractal);
    else if (key_code == C)
        fractal->color += (255 * 255 * 255) / 100;
    else if (key_code == J)
        set_random_julia(&fractal->cx, &fractal->cy);
    else if (key_code == M || key_code == P)
        change_iterations(fractal, key_code);

    // Update fractal->name here if cx or cy are modified
    if (key_code == J || key_code == M || key_code == P)
        ft_new_strncpy(fractal->name, argv[1], 5);

    draw_fractal(fractal, fractal->name);
    return (0);
}
*/


/**
 * @brief    The handler for mouse events.
 * 				SCROLL_UP: zoom in.
 * 				SCROLL_DOWN: zoom out.
 *
 * @param    mouse_code The code of the mouse event.
 * @param    x          The x coordinate of the mouse.
 * @param    y          The y coordinate of the mouse.
 * @param    fractal
 */
//old working:

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}


//new fancy:
/*
int mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
    if (mouse_code == SCROLL_UP)
        zoom(fractal, x, y, 1);
    else if (mouse_code == SCROLL_DOWN)
        zoom(fractal, x, y, -1);

    // Update fractal->name here if cx or cy are modified
    ft_new_strncpy(fractal->name, argv[1], 5);

    draw_fractal(fractal, fractal->name);
    return (0);
}
*/


// tools.c

#include "../fractol.h"

/**
 * @brief    Puts the provided color to the pixel at the provided coordinates.
 *
 * @param    fractal
 * @param    x         The graphic x coordinate
 * @param    y         The graphic y coordinate
 * @param    color     The color to put to the pixel.
 */
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

/**
 * @brief    Exits the program.
 *
 * @param    fractal
 */
int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

/**
 * @brief    Generates a random double between -1.5 and 1.5.
 *
 * @return   double    The random double.
 */
double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

/**
 * @brief    Increases or decreases the number of iterations.
 * The lower the number of iterations is, the faster the fractal is generated.
 *
 * @param    fractal
 * @param    key_code
 */
void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}


/**
 * @brief    Sets the constants of Julia to random values.
 *
 * @param    cx        A pointer to the cx constant.
 * @param    cy        A pointer to the cy constant.
 */
void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

double	ft_atod(char *s)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\n'))
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integral = (integral * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fractional = fractional + (*s++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}
/*

#include <stddef.h>

char	*ft_new_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';  // Ensure remaining bytes in dest are null terminated
		i++;
	}
	return (dest);
}
*/






///////////////////////////////////////////////////////////////////

// working code as of 3:56 friday


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_testing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:56:45 by tmoeller          #+#    #+#             */
/*   Updated: 2024/06/14 15:54:01 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



////// bonus: moving with arrow keys, shifting colours.
/* R: reset the fractal.
 * 				C: change the color scheme.
 * 				J: set the constants of Julia to random values.
 * 				P: increase the max iterations.
 * 				M: reduce the max iterations.*/
//mouse target while zooming is also present



// draw.c

#include "../fractol.h"

void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			compute_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}


void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			compute_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}


// init.c

#include "../fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -2.25;
	fractal->offset_y = -1.65;
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
}

// main.c

#include "../fractol.h"

int	draw_fractal(t_fractal *fractal, char *input) // change to user_input? or terminal input?
{
	if (!ft_strncmp(input, "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(input, "julia", 6))
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.70176;
			fractal->cy = -0.3842;
		}
		draw_julia(fractal);
	}
	else
	{
		ft_printf("Please only input mandelbrot or julia for <fractal>\n");
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
	{
		ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia");
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_first_fractal(fractal, argc, argv);
	mlx_loop(fractal->mlx);
	return (0);
}

void	draw_first_julia(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 4) // Check if cx and cy are provided
	{
		fractal->cx = ft_atod(argv[2]);
		fractal->cy = ft_atod(argv[3]);
	}
	else // Default Julia set parameters
	{
		fractal->cx = -0.70176;
		fractal->cy = -0.3842;
	}
	draw_julia(fractal);
	return ;
}


void	draw_first_fractal(t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2 || argc > 4) // Check if the number of arguments is correct
	{
		ft_printf("Usage: ./fractol <fractal> [<cx> <cy>]\n");
		exit_fractal(fractal);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(argv[1], "julia", 6))
		draw_first_julia(fractal, argc, argv);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
	return ;
}


// compute_fractals.c

#include "../fractol.h"

/**
 * @brief    Calculates the Mandelbrot fractal for one pixel.
 *
 * The z variables are set to 0, the beginning of the suite.
 *
 * The c constants are set to the coordinates of the pixel.
 *
 * For performance reasons, we use the (x * x) calculation instead of the
 * pow(x, 2) function.
 *
 * The exit conditions of the loop are the following:
 * - The absolute value of z is greater than the system's max values, then
 *   we can assure that the suite will diverge to infinity.
 * - The number of iterations is too high, then we can assure that
 *   the suite will stay stuck in an infinite loop.
 *
 * If the the suite diverges, we color it and multiply the color by the
 * number of iterations to make the mathematical depths more clear to the
 * eye.
 *
 * @param    fractal
 */
void	compute_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "mandelbrot";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
				* i));
}

/**
 * @brief    Calculates the Julia fractal for one pixel.
 *
 * The z variables are set to the coordinates of the pixel.
 *
 * The c constants are set to the provided values, as every value produces
 * a different fractal.
 *
 * @param    fractal
 */
void	compute_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "julia";
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}

// user_inputs.c

#include "../fractol.h"

/**
 * @brief    Zooms or dezooms the fractal.
 *
 * @param    fractal
 * @param    x         The x coordinate of the mouse.
 * @param    y         The y coordinate of the mouse.
 * @param    zoom      1 for zoom, -1 for dezoom.
 */
void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

/**
 * @brief    The handler for keyboard events.
 * 				ESC: exit the program.
 * 				LEFT: move the fractal to the left.
 * 				RIGHT: move the fractal to the right.
 * 				UP: move the fractal up.
 * 				DOWN: move the fractal down.
 * 				R: reset the fractal.
 * 				C: change the color scheme.
 * 				J: set the constants of Julia to random values.
 * 				P: increase the max iterations.
 * 				M: reduce the max iterations.
 *
 * @param    key_code
 * @param    fractal
 */
//old working:

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}


/**
 * @brief    The handler for mouse events.
 * 				SCROLL_UP: zoom in.
 * 				SCROLL_DOWN: zoom out.
 *
 * @param    mouse_code The code of the mouse event.
 * @param    x          The x coordinate of the mouse.
 * @param    y          The y coordinate of the mouse.
 * @param    fractal
 */

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}


// tools.c

#include "../fractol.h"

/**
 * @brief    Puts the provided color to the pixel at the provided coordinates.
 *
 * @param    fractal
 * @param    x         The graphic x coordinate
 * @param    y         The graphic y coordinate
 * @param    color     The color to put to the pixel.
 */
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

/**
 * @brief    Exits the program.
 *
 * @param    fractal
 */
int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}



///delete this capability from everywhere????? 
//////the generate_random and set_random_julia functions




/**
 * @brief    Generates a random double between -1.5 and 1.5.
 *
 * @return   double    The random double.
 */
double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

/**
 * @brief    Increases or decreases the number of iterations.
 * The lower the number of iterations is, the faster the fractal is generated.
 *
 * @param    fractal
 * @param    key_code
 */
void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}


/**
 * @brief    Sets the constants of Julia to random values.
 *
 * @param    cx        A pointer to the cx constant.
 * @param    cy        A pointer to the cy constant.
 */
void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

double	ft_atod(char *s)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\n'))
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integral = (integral * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fractional = fractional + (*s++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}
