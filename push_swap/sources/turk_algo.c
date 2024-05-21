/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:50:12 by tmoeller          #+#    #+#             */
/*   Updated: 2024/05/21 17:39:42 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
				t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
				t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	pb(a, b, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	turk_algo(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes_a(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	smallest_on_top(a);
}
// check to see if all of the stack_len, sorted etc have a if !a kinda security