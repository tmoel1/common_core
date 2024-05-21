/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:31:11 by tmoeller          #+#    #+#             */
/*   Updated: 2024/05/21 13:14:31 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int						number;
	int						index;
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

t_stack_node	*find_smallest(t_stack_node *stack)

// Stack Operations

// Algorithms

#endif