/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:46:17 by tmoeller          #+#    #+#             */
/*   Updated: 2024/05/21 11:01:00 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a, false);
	else if (biggest == (*a)->next)
		rra(a, false);
	if ((*a)->number > (*a)->next->number)
		sa(a, false);
}
