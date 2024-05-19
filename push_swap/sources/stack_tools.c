#include "../includes/push_swap.h"

int stack_len(t_stack_node *stack)
{
	int count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node *find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node *find_min(t_stack_node *stack)
{
	long min;
	t_stack_node *min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node *find_biggest(t_stack_node *stack)
{
	long biggest;
	t_stack_node *biggest_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->number > biggest)
		{
			biggest = stack->number;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}
