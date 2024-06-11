/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:36:49 by tmoeller          #+#    #+#             */
/*   Updated: 2023/11/18 08:36:52 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stock(char *remaining_text, int fd)
{
	char	local_buffer[BUFFER_SIZE + 1];
	ssize_t	nbytes;

	while (!ft_strchr(remaining_text, '\n'))
	{
		nbytes = read(fd, local_buffer, BUFFER_SIZE);
		if (nbytes == 0)
			break ;
		if (nbytes == -1)
		{
			free(remaining_text);
			return (NULL);
		}
		local_buffer[nbytes] = '\0';
		remaining_text = ft_strjoin_gnl(remaining_text, local_buffer);
	}
	return (remaining_text);
}

static char	*save_after_newline(char *current_line)
{
	char	*newline_pos;
	char	*new_remaining;

	newline_pos = ft_strchr(current_line, '\n');
	if (!newline_pos)
		return (NULL);
	newline_pos++;
	new_remaining = ft_strdup(newline_pos);
	*newline_pos = '\0';
	return (new_remaining);
}

char	*get_next_line(int fd)
{
	static char	*remaining_text;
	char		*current_line;

	current_line = read_and_stock(remaining_text, fd);
	remaining_text = save_after_newline(current_line);
	return (current_line);
}
