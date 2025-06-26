#include "../include/push_swap.h"

static void	set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;
	long			max;

	b = stack_b;
	while (b)
	{
		max = LONG_MAX;
		a = stack_a;
		while (a)
		{
			if (b -> content < a -> content && a -> content < max)
			{
				max = a -> content;
				b -> target = a;
			}
			a = a -> next;
		}
		if (max == LONG_MAX)
			b -> target = find_min(stack_a);
		b = b -> next;
	}
}

void	init_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_index(stack_a, lstsize(stack_a));
	set_index(stack_b, lstsize(stack_b));
	set_target_b(stack_a, stack_b);
}
