#include "../include/push_swap.h"

void	set_index(t_stack_node *stack, int size)
{
	t_stack_node	*tmp;
	int				mid;
	int				i;

	if (!stack)
		return ;
	tmp = stack;
	mid = size / 2;
	i = -1;
	while (++i < size)
	{
		tmp -> idx = i;
		if (i <= mid)
			tmp -> above_median = true;
		else
			tmp -> above_median = false;
		tmp = tmp -> next;
	}
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*lst_max;
	int				max;

	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (tmp -> content > max)
		{
			max = tmp -> content;
			lst_max = tmp;
		}
		tmp = tmp -> next;
	}
	return (lst_max);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*lst_min;
	int				min;

	min = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp -> content < min)
		{
			min = tmp -> content;
			lst_min = tmp;
		}
		tmp = tmp -> next;
	}
	return (lst_min);
}

void	shift_to_top(t_stack_node **stack, t_stack_node *top_node, char to_do)
{
	while (*stack != top_node)
	{
		if (to_do == 'a')
		{
			if (top_node -> above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else
		{
			if (top_node -> above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	min_on_top(t_stack_node **stack)
{
	t_stack_node	*min;

	min = find_min(*stack);
	while (*stack != min)
	{
		if (min -> above_median)
			ra(stack, true);
		else
			rra(stack, true);
	}
}
