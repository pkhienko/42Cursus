#include "../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp -> next;
	tmp -> next = NULL;
	lstlast(*stack)->next = tmp;
}

void	ra(t_stack_node **stack_a, bool checker)
{
	rotate(stack_a);
	if (checker)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **stack_b, bool checker)
{
	rotate(stack_b);
	if (checker)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool checker)
{
	rotate(stack_a);
	rotate(stack_b);
	if (checker)
		ft_putstr_fd("rr\n", 1);
}
