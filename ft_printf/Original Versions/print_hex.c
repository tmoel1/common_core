/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:27:11 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/10 14:27:24 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
