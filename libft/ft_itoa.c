/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:32:29 by tmoeller          #+#    #+#             */
/*   Updated: 2023/10/31 18:32:31 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*tab;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		nb = -nb;
	i = numlen(n);
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = '\0';
	while (--i >= 0)
	{
		tab[i] = (nb % 10) + '0';
		nb = (nb / 10);
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}

/*
static int	numlen(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*tab;
	int		sign;

	nb = n;
	sign = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	i = numlen(n);
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = '\0';
	while (--i >= 0)
	{
		tab[i] = (nb % 10) + '0';
		nb = (nb / 10);
	}
	if (sign)
		tab[0] = '-';
	return (tab);
}
*/
/*
char	*ft_itoa(int nb)
{
	long n;
	int	i;
	char temp[12] = {0};
	char *tab;
	int	sign;
	int	j;

	n = nb;
	i = 0;
	sign = 0;
	j = 0;
	if (n == 0)
	{
		tab = (char *)malloc(sizeof(char) * 2);
		if (!tab)
			return (NULL);
		tab[i] = '0';
		i++;
		tab[i] = '\0';
		return (tab);
	}
	if (n < 0)
	{
		sign = 1;
		n = (n * -1);
	}
	i = 0;
	
	while (n > 0)
	{
		temp[i] = (n % 10) + '0';
		n = (n / 10);
		i++;
	}
	if (sign)
		temp[i++] = '-';
	i--;
	tab = (char *)malloc(sizeof(char) * i + 1);
	if (!tab)
		return (NULL);
	while (i >= 0)
	{
		tab[j] = temp[i];
		j++;
		i--;
	}
	return (tab);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	printf("%s", ft_itoa(atoi(av[1])));
	return (0);	
}
*/