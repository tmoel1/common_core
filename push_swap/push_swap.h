/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:31:11 by tmoeller          #+#    #+#             */
/*   Updated: 2024/05/21 15:35:32 by tmoeller         ###   ########.fr       */
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

int		error_syntax(char *s);
int		error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);

// Initialisations

void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	init_stack_a(t_stack_node **a, char **argv);


// Tools

void	current_index(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);
void	prep_for_push(t_stack_node **s, t_stack_node *tn, char sn);
void	smallest_on_top(t_stack_node **a);
char	**split(char *s, char c);
int	stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_biggest(t_stack_node *stack);


// Stack Operations

void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **a, t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

// Algorithms

void	sort_3(t_stack_node **a);
void	turk_algo(t_stack_node **a, t_stack_node **b);


// Main

int	main(int argc, char **argv);

#endif