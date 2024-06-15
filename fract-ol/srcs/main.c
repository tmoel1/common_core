/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:20:17 by tmoeller          #+#    #+#             */
/*   Updated: 2024/06/15 12:54:00 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
	{
		ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia\n");
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0, exit_fractal, fractal);
	draw_first_fractal(fractal, argc, argv);
	mlx_loop(fractal->mlx);
	return (0);
}
/*
int	main(int argc, char **argv)
{
    t_fractal	*fractal;

    if (argc < 2)
    {
        ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia\n");
        return (0);
    }
    fractal = malloc(sizeof(t_fractal));
    if (!fractal)
        return (1); // Handle malloc failure
    init_fractal(fractal);
    init_mlx(fractal);
    mlx_key_hook(fractal->window, key_hook, fractal);
    mlx_mouse_hook(fractal->window, mouse_hook, fractal);
    mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
    draw_first_fractal(fractal, argc, argv);
    mlx_loop(fractal->mlx);
    exit_fractal(fractal); // Ensure cleanup
    return (0);
}
*/

