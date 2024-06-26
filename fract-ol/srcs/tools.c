/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:32:01 by tmoeller          #+#    #+#             */
/*   Updated: 2024/06/15 13:04:51 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal);
	//ft_printf("got this far\n");
	exit(1);
	return (0);
}
/*
int	exit_fractal(t_fractal *fractal)
{
    if (fractal->pointer_to_image)
        mlx_destroy_image(fractal->mlx, fractal->image);
    if (fractal->window)
        mlx_destroy_window(fractal->mlx, fractal->window);
    if (fractal->mlx)
    {
        // mlx_destroy_display(fractal->mlx); // Uncomment if using X11 and needed
        free(fractal->mlx);
    }
    if (fractal)
        free(fractal);
    exit(1);
    return (0);
}
*/



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
