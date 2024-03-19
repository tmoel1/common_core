/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:26 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/08 11:24:28 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" 

static int	format_check(va_list args, const char *format)
{
	if (*format == 'c')
		return (print_char(va_arg(args, int)));
	else if (*format == 's')
		return (print_string(va_arg(args, char *)));
	else if (*format == 'p')
		return (print_pointer(va_arg(args, uintptr_t)));
	else if (*format == 'd' || *format == 'i')
		return (print_number((long)(va_arg(args, int)), 10));
	else if (*format == 'u')
		return (print_number((long)(va_arg(args, unsigned int)), 10));
	else if (*format == 'x' || *format == 'X')
		return (print_hex(va_arg(args, unsigned int), 16, format));
	else if (*format == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += format_check(args, format);
			format++;
		}
		else
		{
			count += print_char(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
