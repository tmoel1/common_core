#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
#include <unistd.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int						number;
	int						position;
	int						cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

// Error Handling

// Initialisations

// Tools

// Stack Operations

// Algorithms

#endif