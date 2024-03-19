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
//make a mix there

/*
int	print_pointer(unsigned int p)
{
	// watch oceano vid again and see what he does from 26min mark - with his
	// print digit accepting also a base into it.
}
*/
/* #include "ft_printf.h"

int	ft_putnbr_base(long long n, const char *base)
{
	unsigned long long	nb;
	unsigned long long	len;
	int			count;
	char			result[64];
	int			i;

	count = 0;
	len = ft_strlen(base);
	i = 0;
	if (n < 0)
	{
		nb = (unsigned long long)(-n);
		count += ft_putchar('-');
	}
	else
		nb = (unsigned long long)n;
	while (nb >= len)
	{
		result[i++] = base[nb % len];
		nb /= len;
	}
	result[i] = base[nb % len];
	while (i >= 0)
		count += ft_putchar(result[i--]);
	return (count);
} */

/* int	ft_putnbr_base(long long n, const char *base)
{
	unsigned long long	nb;
	unsigned long long	len;
	int			count;
	char			result[64];
	int			i;

	count = 0;
	len = ft_strlen(base);
	i = 0;
	if (n < 0)
	{
		nb = (unsigned long long)(-n);
		count += ft_putchar('-');
	}
	else
		nb = (unsigned long long)n;
	while (nb >= len)
	{
		result[i++] = base[nb % len];
		nb /= len;
	}
	result[i] = base[nb % len];
	while (i >= 0)
		count += ft_putchar(result[i--]);
	return (count);
} */

/*
int print_digit(long n, int base)
{
    int count = 0;
    char *symbols = "0123456789abcdef";
    char buffer[50];
    int i = 0;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
        count++;
    }

    do
    {
        buffer[i++] = symbols[n % base];
        n /= base;
    } while (n > 0);

    while (--i >= 0)
    {
        count += print_char(buffer[i]);
    }

    return count;
}
*/

/* int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;
	char	buffer[50];
	int		i;

	symbols = "0123456789abcdef";
	count = 0;
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	while (n > 0)
	{
		buffer[i++] = symbols[n % base];
		n /= base;
	}
	while (--i >= 0)
		count += print_char(buffer[i]);
	return (count);
}*/

/*version of above that handles 0's
int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;
	char	buffer[50];
	int		i;

	symbols = "0123456789abcdef";
	count = 0;
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		return 1;
	}
	while (n > 0)
	{
		buffer[i++] = symbols[n % base];
		n /= base;
	}
	while (--i >= 0)
		count += print_char(buffer[i]);
	return (count);
}*/

/*shortened:
this seems to be the be the best for now?
only problem is the upper and lower hex, maybe i should also send the
symbols string each time? so send the number, base, and initialise, define
and send the 1-10 or 1-F or 1-f etc

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;
	char	buffer[50];
	int		i;

	symbols = "0123456789abcdef";
	count = 0;
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
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
	*/