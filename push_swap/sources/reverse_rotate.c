/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:43:00 by tmoeller          #+#    #+#             */
/*   Updated: 2024/05/22 18:55:38 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	/*
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	//if (last->prev)
	PL;
	last->prev->next = NULL; // seems to be a problem here, beofore there wasn't the if check
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	*/
	t_stack_node *last;
    t_stack_node *second_last;

    if (!*stack || !(*stack)->next)
        return;

    last = *stack;

    // Traverse to find the last and second last nodes
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    // second_last is now the node before last
    // Disconnect last node from second_last
    second_last->next = NULL;

    // Move last node to the front
    last->next = *stack;
    last->prev = NULL;

    // Update the previous head node to point back to the new head
    (*stack)->prev = last;

    // Update stack to point to the new head
    *stack = last;
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
