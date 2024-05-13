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