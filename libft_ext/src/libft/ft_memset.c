/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:31:20 by tmoeller          #+#    #+#             */
/*   Updated: 2023/10/25 12:48:32 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
// is it better to use pointer arithmetic for later on (2d+ arrays etc)

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// now this ^^ works thanks to double brackets making sure the casting happens 
// before the ith element in accessed

// cannot directly index a void pointer si jamais
// have to typcast into another pointer before using it, like above the loop
// or use pointer arithmetic instead like the first example here
//
//
// 		TRY THE TYPCASTING BEFORE VERSION HERE TOO!

void	*ft_memset(void *b, int c, size_t len)
{
	void	*ptr;

	ptr = b;
	while (len > 0)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
		len--;
	}
	return (ptr);
}

// 4th varient is create a unsigned char pointer and give it the address of b
// then work the whole time with that so 
// there's no need to typcast or anything weird
// in this case you can use the indexing normally cp[i]
*/