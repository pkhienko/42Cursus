#include "../include/push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp -> next;
	tmp -> next = (*stack);
	*stack = tmp;
}

void	sa(t_stack_node **stack_a, bool checker)
{
	swap(stack_a);
	if (checker)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **stack_b, bool checker)
{
	swap(stack_b);
	if (checker)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool checker)
{
	swap(stack_a);
	swap(stack_b);
	if (checker)
		ft_putstr_fd("ss\n", 1);
}
