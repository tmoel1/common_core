/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:36:48 by tmoeller          #+#    #+#             */
/*   Updated: 2023/10/31 09:36:51 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// change names and styles a bit here

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}

/*
static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = ft_substr(s, 0, len);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c)
			j++;
		split[i] = get_word(s + j, c);
		if (!split[i])
			return (NULL);
		i++;
		j += ft_strlen(split[i - 1]);
	}
	split[i] = NULL;
	return (split);
}
*/
/*
char	**free_strings(char **strings, size_t len);

static size_t	wordcount(const char *s1, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s1[i])
	{
		while (s1[i] && s1[i] == c)
			i++;
		if (s1[i])
			wc++;
		while (s1[i] && s1[i] != c)
			i++;
	}
	return (wc);
}

static void	copy_words(char const *s, char c, char **strings)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			strings[k] = ft_substr(s, j, (i - j));
			if (!strings[k])
			{
				free_strings(strings, k);
				return ;
			}
			k++;
		}
	}
}

static char	**wordalloc(char const *s, char c, char **strings, size_t slen)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	k = 0;
	while (i < slen + 1 && slen)
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] != c)
			i++;
		if (i > j)
		{
			strings[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (strings[k] != NULL)
				ft_strlcpy(strings[k], &s[i - (i - j)], (i - j) + 1);
			k++;
		}
	i++;
	}
	return (strings);
}
*/
/*
char	**free_strings(char **strings, size_t len)
{
	while (len > 0)
	{
		free(strings[len - 1]);
		len--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	wc;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (!slen)
	{
		strings = malloc(sizeof(char *) * (wordcount(s, c) + 1));
		if (!strings)
			return (NULL);
		strings[0] = NULL;
		return (strings);
	}	
	wc = wordcount(s, c);
	strings = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!strings)
		return (free_strings(strings, wc));
	copy_words(s, c, strings);
	strings[wc] = NULL;
	return (strings);
}
*/
//comment the bellow paragraph
// strings = wordalloc(s, c, strings, slen);
/*
this unfortuntely doesn't pass norm and will be a huge pain to fix

char static	*strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t static	wordcount(const char *s1, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s1[i])
	{
		while (s1[i] && s1[i] == c)
			i++;
		if (s1[i])
			wc++;
		while (s1[i] && s1[i] != c)
			i++;
	}
	return (wc);
}

void static	a_and_c(char **set, char const *s, size_t k, size_t l)
{
	set[k] = (char *)malloc(sizeof(char) * ((l) + 1));
	if (!set[k])
		return (NULL);
	strncpy(set[k], &s[j], (l));
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	wc;
	char	**set;

	i = 0;
	k = 0;
	wc = wordcount(s, c);
	set = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!set)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] != c)
			i++;
		if (i > j)
			a_and_c(set, s, k++, (i - j));
	}
	set[k] = NULL;
	return (set);
}
*/