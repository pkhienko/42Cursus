#include "../include/push_swap.h"

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, bool checker)
{
	t_stack_node	*tmp;

	if (!*stack_b)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = tmp;
	if (checker)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b, bool checker)
{
	t_stack_node	*tmp;

	if (!*stack_a)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = tmp;
	if (checker)
		ft_putstr_fd("pb\n", 1);
}

void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	shift_to_top(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b, true);
}

void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	if (cheapest_node -> above_median
		&& cheapest_node -> target -> above_median)
	{
		while (*stack_a != cheapest_node && *stack_b != cheapest_node -> target)
			rr(stack_a, stack_b, true);
		set_index(*stack_a, lstsize(*stack_a));
		set_index(*stack_b, lstsize(*stack_b));
	}
	else if (!cheapest_node -> above_median
		&& !cheapest_node -> target -> above_median)
	{
		while (*stack_a != cheapest_node && *stack_b != cheapest_node -> target)
			rrr(stack_a, stack_b, true);
		set_index(*stack_a, lstsize(*stack_a));
		set_index(*stack_b, lstsize(*stack_b));
	}
	shift_to_top(stack_a, cheapest_node, 'a');
	shift_to_top(stack_b, cheapest_node -> target, 'b');
	pb(stack_a, stack_b, true);
}
