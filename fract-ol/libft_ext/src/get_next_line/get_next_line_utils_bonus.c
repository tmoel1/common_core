/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:36:23 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/18 08:36:26 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		len;
	int		i;

	if (!s1 || !*s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}	

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*s3;
	size_t	slen1;
	size_t	slen2;

	if (!s1 && !s2)
		return (NULL);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!s3)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	s3[slen1 + slen2] = '\0';
	while (slen2--)
		s3[slen1 + slen2] = s2[slen2];
	while (slen1--)
		s3[slen1] = s1[slen1];
	if (s1)
		free(s1);
	return (s3);
}
