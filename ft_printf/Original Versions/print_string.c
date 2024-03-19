/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:11:25 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/09 14:11:27 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// can do away with the return 6 and instead just return write
// and the same for print_char
// maybe stay with int though as ssize_t isn't always interpreted as an int
// in all circumstances/systems etc

int	print_string(char *s)
{
	int	i;

	if (!s)
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
