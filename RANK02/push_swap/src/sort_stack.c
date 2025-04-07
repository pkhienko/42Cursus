#include "../include/push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*tmp;

	tmp = stack;
	while (tmp -> next)
	{
		if (tmp -> content > tmp -> next -> content)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

void	sort_three(t_stack_node	**stack)
{
	t_stack_node	*max;

	max = find_max(*stack);
	if ((*stack)->content == max -> content)
		ra(stack, true);
	else if ((*stack)->next -> content == max -> content)
		rra(stack, true);
	if ((*stack)->content > (*stack)->next -> content)
		sa(stack, true);
}

void	sort_stack(t_stack **stack, int size)
{
	if (size-- > 3 && !is_sorted((*stack)->stack_a))
		pb(&(*stack)->stack_a, &(*stack)->stack_b, true);
	if (size-- > 3 && !is_sorted((*stack)->stack_a))
		pb(&(*stack)->stack_a, &(*stack)->stack_b, true);
	while (size-- > 3 && !is_sorted((*stack)->stack_a))
	{
		init_a((*stack)->stack_a, (*stack)->stack_b);
		push_to_b(&(*stack)->stack_a, &(*stack)->stack_b);
	}
	sort_three(&(*stack)->stack_a);
	while ((*stack)->stack_b)
	{
		init_b((*stack)->stack_a, (*stack)->stack_b);
		push_to_a(&(*stack)->stack_a, &(*stack)->stack_b);
	}
	set_index((*stack)->stack_a, lstsize((*stack)->stack_a));
	min_on_top(&(*stack)->stack_a);
}
