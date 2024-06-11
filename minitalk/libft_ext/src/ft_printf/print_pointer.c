/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:30:05 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/09 14:30:06 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(uintptr_t n)
{
	int		count;
	char	*symbols;
	char	buffer[64];
	int		i;

	count = write(1, "0x", 2);
	symbols = "0123456789abcdef";
	i = 0;
	if (n == 0)
		return (count + print_char('0'));
	while (n > 0)
	{
		buffer[i++] = symbols[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		count += print_char(buffer[i]);
	return (count);
}
