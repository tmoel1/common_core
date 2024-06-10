//changed to use sigaction

#include "../inc/minitalk.h"
#include <signal.h>

// Define a signal handler function
void	handle_signal(int signum)
{
	// Custom signal handling logic can be placed here if needed
	// Currently, it is a placeholder that does nothing
}

void	send_bits(pid_t pid, char c)
{
	int	bit; // Counter to iterate through the individual bits of the character 'c'

	bit = 0;
	while (bit < 8) // Iterate through each of the 8 bits in the character 'c'
	{
		if ((c & (0x01 << bit)) != 0) // Check if the current bit of the character is '1'
			kill(pid, SIGUSR1); // If the bit is '1', send the SIGUSR1 signal to the server
		else
			kill(pid, SIGUSR2); // If the bit is '0', send the SIGUSR2 signal to the server
		usleep(100); // Sleep for 100 microseconds to ensure the server has time to handle the signal
		bit++; // Move to the next bit for processing
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid; // Variable to store the server's process ID
	char	*msg; // Pointer to the message string
	struct sigaction sa; // Structure to specify the signal handling behavior

	// Initialize the sigaction struct
	sa.sa_handler = handle_signal; // Set the signal handler function
	sa.sa_flags = 0; // No special flags
	sigemptyset(&sa.sa_mask); // Initialize the signal mask to block no additional signals during execution of the handler

	// Set up the signal handlers for SIGUSR1 and SIGUSR2 using the sigaction struct
	sigaction(SIGUSR1, &sa, NULL); // Set up the handler for SIGUSR1
	sigaction(SIGUSR2, &sa, NULL); // Set up the handler for SIGUSR2

	if (argc == 3) // Check if the correct number of arguments is provided (program name, PID, and message)
	{
		pid = ft_atoi(argv[1]); // Convert the first argument to an integer to get the server's PID
		msg = argv[2]; // Assign the second argument to the message pointer
		while (*msg != '\0') // Iterate over each character of the message string
		{
			send_bits(pid, *msg); // Send the current character's bits to the server
			msg++; // Move to the next character in the message string
		}
		send_bits(pid, '\n'); // Send a newline character to signify the end of the message
	}
	else // If the wrong number of arguments is provided
	{
		ft_printf("Error: wrong format\n"); // Print an error message
		ft_printf("Try: ./client <PID> <MESSAGE>\n"); // Provide the correct usage format
		return (1); // Return an error code
	}
	return (0); // Return success
}

Detailed Explanation
Include Headers:

#include "../inc/minitalk.h": Includes the header file containing necessary declarations and definitions.
#include <signal.h>: Includes the header file for signal handling.
Signal Handler Function:

void handle_signal(int signum): Defines a function to handle signals. This function currently does nothing but can be customized.
send_bits Function:

void send_bits(pid_t pid, char c): Defines a function to send each bit of a character c to a server with process ID pid.
int bit: Declares a counter for iterating through the bits of c.
while (bit < 8): Loops through each bit of the character.
if ((c & (0x01 << bit)) != 0): Checks if the current bit is 1 using bitwise operations.
kill(pid, SIGUSR1): Sends a SIGUSR1 signal if the bit is 1.
kill(pid, SIGUSR2): Sends a SIGUSR2 signal if the bit is 0.
usleep(100): Pauses for 100 microseconds to allow the server to process the signal.
main Function:

int main(int argc, char **argv): Entry point of the program.
pid_t pid: Declares a variable to store the server's process ID.
char *msg: Declares a pointer to the message string.
struct sigaction sa: Declares a sigaction struct to specify signal handling.
Initialize sigaction Struct:

sa.sa_handler = handle_signal: Sets the signal handler function.
sa.sa_flags = 0: No special flags.
sigemptyset(&sa.sa_mask): Initializes the signal mask to block no additional signals during execution of the handler.
Set up Signal Handlers:

sigaction(SIGUSR1, &sa, NULL): Sets up the handler for SIGUSR1.
sigaction(SIGUSR2, &sa, NULL): Sets up the handler for SIGUSR2.
Argument Checking and Message Sending:

if (argc == 3): Checks if exactly three arguments are provided (program name, PID, and message).
pid = ft_atoi(argv[1]): Converts the first argument to an integer to get the server's PID.
msg = argv[2]: Assigns the second argument to the message pointer.
while (*msg != '\0'): Loops through each character of the message string.
send_bits(pid, *msg): Sends each character's bits to the server.
send_bits(pid, '\n'): Sends a newline character to signify the end of the message.
Error Handling:

else: If the wrong number of arguments is provided.
ft_printf("Error: wrong format\n"): Prints an error message.
ft_printf("Try: ./client <PID> <MESSAGE>\n"): Provides the correct usage format.
return (1): Returns an error code.
Successful Execution:

return (0): Returns success if the program completes without errors.






#include "../inc/minitalk.h"
#include <signal.h>

// Signal handler function to accumulate bits from received signals
void	sig_handler(int sig)
{
	static int	bit; // Counter to keep track of the current bit position
	static int	i; // Accumulator to build the character from received bits

	if (sig == SIGUSR1) // If the signal is SIGUSR1, set the corresponding bit in 'i'
		i |= (0x01 << bit);
	bit++; // Move to the next bit position
	if (bit == 8) // If 8 bits have been processed, a full character has been built
	{
		ft_printf("%c", i); // Print the constructed character
		bit = 0; // Reset bit counter for the next character
		i = 0; // Reset the accumulator for the next character
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid; // Variable to store the process ID of the server
	struct sigaction sa; // Structure to specify the signal handling behavior

	(void)argv; // Suppress unused parameter warning for 'argv'
	if (argc != 1) // Check if the correct number of command-line arguments is provided
	{
		ft_printf("Error: wrong format\n"); // Print error message if wrong number of arguments
		ft_printf("Try: ./server\n"); // Provide correct usage instruction
		return (1); // Return an error code
	}
	pid = getpid(); // Get the process ID of the server
	ft_printf("PID: %d\n", pid); // Print the process ID
	ft_printf("Waiting for a message...\n"); // Indicate the server is ready to receive messages

	// Initialize the sigaction struct
	sa.sa_handler = sig_handler; // Set the signal handler function
	sa.sa_flags = 0; // No special flags
	sigemptyset(&sa.sa_mask); // Initialize the signal mask to block no additional signals

	// Set up signal handlers using sigaction
	sigaction(SIGUSR1, &sa, NULL); // Set up handler for SIGUSR1
	sigaction(SIGUSR2, &sa, NULL); // Set up handler for SIGUSR2

	// Infinite loop to wait for signals
	while (1)
	{
		pause(); // Suspend execution until a signal is received
	}

	return (0); // Return success (this line is never reached due to the infinite loop)
}


Detailed Explanation
Include Headers:

#include "../inc/minitalk.h": Includes the header file containing necessary declarations and definitions.
#include <signal.h>: Includes the header file for signal handling.
Signal Handler Function:

void sig_handler(int sig): Defines a function to handle signals.
static int bit: Declares a static variable to keep track of the current bit position. It retains its value across function calls.
static int i: Declares a static variable to accumulate the bits received from signals to construct a character.
if (sig == SIGUSR1) i |= (0x01 << bit): Checks if the signal is SIGUSR1. If so, sets the corresponding bit in i to 1.
bit++: Increments the bit counter to move to the next bit position.
if (bit == 8): Checks if 8 bits have been processed, indicating a full character has been built.
ft_printf("%c", i): Prints the constructed character.
bit = 0: Resets the bit counter for the next character.
i = 0: Resets the accumulator for the next character.
Main Function:

int main(int argc, char **argv): Entry point of the program.
pid_t pid: Declares a variable to store the process ID of the server.
struct sigaction sa: Declares a sigaction struct to specify signal handling behavior.
(void)argv: Suppresses unused parameter warning for argv.
if (argc != 1): Checks if the correct number of command-line arguments is provided.
ft_printf("Error: wrong format\n"): Prints an error message if the wrong number of arguments is provided.
ft_printf("Try: ./server\n"): Provides correct usage instruction.
return (1): Returns an error code if the wrong number of arguments is provided.
Get and Print PID:

pid = getpid(): Gets the process ID of the server.
ft_printf("PID: %d\n", pid): Prints the process ID.
ft_printf("Waiting for a message...\n"): Indicates the server is ready to receive messages.
Initialize sigaction Struct:

sa.sa_handler = sig_handler: Sets the signal handler function.
sa.sa_flags = 0: No special flags.
sigemptyset(&sa.sa_mask): Initializes the signal mask to block no additional signals.
Set Up Signal Handlers:

sigaction(SIGUSR1, &sa, NULL): Sets up the handler for SIGUSR1.
sigaction(SIGUSR2, &sa, NULL): Sets up the handler for SIGUSR2.
Infinite Loop to Wait for Signals:

while (1): Enters an infinite loop to wait for signals.
pause(): Suspends execution until a signal is received.
Return Statement:

return (0): Returns success. This line is never reached due to the infinite loop.










#include "../inc/minitalk.h"
#include <signal.h>

void	sig_handler(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	struct sigaction sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message...\n");

	// Initialize sigaction struct
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	// Set up signal handlers using sigaction
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	// Wait for signals in an infinite loop
	while (1)
	{
		pause();
	}

	return (0);
}

#include "../inc/minitalk.h"
#include <signal.h>

void	handle_signal(int signum)
{
	// Custom signal handling logic can be placed here if needed
}

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
	struct sigaction sa;

	// Initialize sigaction struct
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	// Set up signal handlers
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

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











// öptimised" version

#include "../inc/minitalk.h"
#include <signal.h>

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

AND 


#include "../inc/minitalk.h"
#include <signal.h>

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



Explanation:
Signal Handler:

handle_signal(int sig): Consolidates the signal handling logic for both SIGUSR1 and SIGUSR2 signals, ensuring readability and maintainability.
static int bit: Tracks the current bit position.
static int char_accum: Accumulates the bits received to form a character.
When 8 bits are received, it prints the character and resets the counters.
Send Bits:

send_bits(pid_t pid, char c): Sends each bit of the character c to the server using kill to send SIGUSR1 or SIGUSR2 signals.
Simplified loop using for for better readability.
Server Main Function:

Checks for correct argument count.
Prints PID and waits for signals in an infinite loop using pause.
Initializes sigaction for signal handling.
Client Main Function:

Checks for correct argument count.
Converts the first argument to a PID and assigns the second argument to msg.
Sends each character of the message to the server using send_bits.
Initializes sigaction to ignore signals received during message sending to prevent interruptions.
These changes improve readability, maintainability, and conciseness while adhering to norminette rules.



// original thug code comment free

#include "../inc/minitalk.h"

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


#include "../inc/minitalk.h"

void	sig_handler(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server\n");
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}


// mix wihh zelhajou's one? find the simplest route or make the code above more readable in his style?

// optimised client version below:

#include "../inc/minitalk.h"
#include <signal.h>
#include <unistd.h>

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
