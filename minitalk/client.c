/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:33:59 by tmoeller          #+#    #+#             */
/*   Updated: 2024/06/11 11:20:25 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	send_character_bits(pid_t server_pid, char character)
{
	int	bit_position;

	bit_position = 0;
	while (bit_position < 8)
	{
		if (character & (0x01 << bit_position))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(84);
		bit_position++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	if (ac != 3)
	{
		ft_printf("User Error");
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	message = av[2];
	while (*message)
	{
		send_character_bits(server_pid, *message);
		message++;
	}
	send_character_bits(server_pid, '\n');
	return (0);
}
