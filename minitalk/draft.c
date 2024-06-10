


/* ************************************************************************** */
// Client:

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (*msg != '\0')
		{
			send_bits(pid, *msg);
			msg++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}

// Server:

void	handle_signal(int sig)
{
	static int	bit;
	static int	char_accum;

	if (sig == SIGUSR1)
		char_accum |= (0x01 << bit);
	if (++bit == 8)
	{
		ft_printf("%c", char_accum);
		bit = 0;
		char_accum = 0;
	}
}

void	send_bits(pid_t pid, char c)
{
	for (int bit = 0; bit < 8; bit++)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf("Error: wrong format\nTry: ./server\n");
		return (1);
	}
	ft_printf("PID: %d\nWaiting for a message...\n", getpid());

	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}





// CLEAR NOMENGLATURE
// -client

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
		usleep(100);
		bit_position++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Error: wrong format\nTry: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_character_bits(server_pid, *message);
		message++;
	}
	send_character_bits(server_pid, '\n');
	return (0);
}


// -server

void	send_bits(pid_t pid, char c)
{
	for (int bit = 0; bit < 8; bit++)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*msg;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error: wrong format\nTry: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];

	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (*msg)
		send_bits(pid, *msg++);
	send_bits(pid, '\n');
	return (0);
}