/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:21:54 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/07 17:21:59 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// Main
int	ft_printf(const char *format, ...);

// Text
int	print_char(int c);
int	print_string( char *s);

// Numbers
int	print_number(long long n);

// Hexadecimals
int	print_hex(long n, const char *format);

// Pointers
int	print_pointer(uintptr_t n);

#endif
