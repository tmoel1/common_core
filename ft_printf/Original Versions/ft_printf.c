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
// standard .h or a filepath??
// and should it be c += functin or  return (function), like directly?

// should probably optimise and use some more direct returns both here and in 
// the sub-functions

// problem here arppears to be someting with sending *format for the print_hex??
/*
int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_hex(long n, int base, const char *format)
{
	int		count;
	char	*symbols;
	char	buffer[64];
	int		i;

	if (*format == 'x')
		symbols = "0123456789abcdef";
	else if (*format == 'X')
		symbols = "0123456789ABCDEF";
	count = 0;
	i = 0;
	if (n == 0)
		return (print_char('0'));
	while (n > 0)
	{
		buffer[i++] = symbols[n % base];
		n /= base;
	}
	while (--i >= 0)
		count += print_char(buffer[i]);
	return (count);
}

int	print_number(long n, int base)
{
	int		count;
	char	*symbols;
	char	buffer[64];
	int		i;

	symbols = "0123456789abcdef";
	count = 0;
	i = 0;
	if (n == 0)
		return (print_char('0'));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		buffer[i++] = symbols[n % base];
		n /= base;
	}
	while (--i >= 0)
		count += print_char(buffer[i]);
	return (count);
}

int	print_pointer(unsigned int n)
{
	int	count;

	count = write(1, "0x", 2);
	count += print_number((long)n, 16);
	return (count);
}

int	print_string(char *s)
{
	int	i;

	if (!(*s))
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		print_char(s[i]);
		i++;
	}
	return (i);
}
*/
static int	format_check(va_list args, const char *format)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += print_char(va_arg(args, int));
	else if (*format == 's')
		count += print_string(va_arg(args, char *));
	else if (*format == 'p')
		count += print_pointer(va_arg(args, uintptr_t));
	else if (*format == 'd' || *format == 'i')
		count += print_number((long)(va_arg(args, int)), 10);
	else if (*format == 'u')
		count += print_number((long)(va_arg(args, unsigned int)), 10);
	else if (*format == 'x' || *format == 'X')
		count += print_hex(va_arg(args, unsigned int), 16, format);
	else if (*format == '%')
		count += print_char('%');
	return (count);
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

/* 

Below is cooler, but will require a bit of trickery to pass and then deref
the string, or an interator.

static void	format_check(const char *format, va_list args, int *count)
{
	if (*format == 's')
		print_string(va_arg(args, char *), count);
	else
		format--;
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
			format_check(&format, &args, &count);
			format++;
		}
		else
		{
			print_chars(*format, &count);
			format++;
		}
	}
	va_end(args);
	return (count);
}

// going to use passing by reference, not passing by copy/value
// not sure if args and count have be passed with a "&"" or not??
pasqual x oceano

// need to replace the *i-- line with something for format? so it doesnt 
// skip over a character if the format specifier doesn't match the 8 options
// i think we can just *format-- in this case to achieve the same goal!
// NO! we need to send &format
// better to pass only addresses and liberally use the * to dereferce them 
// in the format check function
&format, &args, &count 
*/