/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:21:56 by tmoeller          #+#    #+#             */
/*   Updated: 2024/06/14 17:03:15 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	draw_fractal(t_fractal *fractal, char *input)
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
	//else
	//{
	//	ft_printf("Please only input mandelbrot or julia for <fractal>\n");
	//	exit_fractal(fractal);
	//}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

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

void	draw_first_fractal(t_fractal *fractal, int argc, char **argv)
{
	// if (argc < 2 || argc > 4)
	if (!argc == 2 || !argc == 4)
	{
		ft_printf("Usage: ./fractol <fractal> [<cx> <cy>]\n");
		exit_fractal(fractal);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		draw_mandelbrot(fractal);
	else if (!ft_strncmp(argv[1], "julia", 6))
		draw_first_julia(fractal, argc, argv);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, \
		0, 0);
	return ;
}

void	draw_first_julia(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 4)
	{
		fractal->cx = ft_atod(argv[2]);
		fractal->cy = ft_atod(argv[3]);
	}
	else
	{
		fractal->cx = -0.70176;
		fractal->cy = -0.3842;
	}
	draw_julia(fractal);
	return ;
}
