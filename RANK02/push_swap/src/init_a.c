#include "../include/push_swap.h"

static void	set_target_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;
	long			min;

	a = stack_a;
	while (a)
	{
		min = LONG_MIN;
		b = stack_b;
		while (b)
		{
			if (a -> content > b -> content && b -> content > min)
			{
				min = b -> content;
				a -> target = b;
			}
			b = b -> next;
		}
		if (min == LONG_MIN)
			a -> target = find_max(stack_b);
		a = a -> next;
	}
}

static void	set_shift_cost(t_stack_node	*stack_a, t_stack_node *stack_b)
{
	t_stack_node	*a;
	int				size_a;
	int				size_b;

	a = stack_a;
	size_a = lstsize(stack_a);
	size_b = lstsize(stack_b);
	while (a)
	{
		a -> shift_cost = a -> idx;
		if (!a -> above_median)
			a -> shift_cost = size_a - a -> idx;
		if (a -> target -> above_median)
			a -> shift_cost += a -> target -> idx;
		else
			a -> shift_cost += size_b - a -> target -> idx;
		a = a -> next;
	}
}

static void	set_cheapest_node(t_stack_node *stack_a)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*a;
	long			min;

	a = stack_a;
	min = LONG_MAX;
	while (a)
	{
		if (a -> shift_cost < min)
		{
			min = a -> shift_cost;
			cheapest_node = a;
		}
		a = a -> next;
	}
	cheapest_node -> cheapest = true;
}

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack -> cheapest)
			return (stack);
		stack = stack -> next;
	}
	return (NULL);
}

void	init_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_index(stack_a, lstsize(stack_a));
	set_index(stack_b, lstsize(stack_b));
	set_target_a(stack_a, stack_b);
	set_shift_cost(stack_a, stack_b);
	set_cheapest_node(stack_a);
}
