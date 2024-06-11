/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:40:35 by tmoeller          #+#    #+#             */
/*   Updated: 2024/06/11 15:43:53 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	signal_handler(int sig)
{
	static int	bit;
	static int	character;

	if (sig == SIGUSR1)
		character |= (0x01 << bit);
	if (++bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("User Error\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
