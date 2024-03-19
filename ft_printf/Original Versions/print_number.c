/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:28:56 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/10 14:28:58 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(long long n, int base)
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
