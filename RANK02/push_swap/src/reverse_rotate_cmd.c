#include "../include/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*secound_last;

	if (!*stack || !(*stack)->next)
		return ;
	secound_last = *stack;
	while (secound_last -> next -> next)
		secound_last = secound_last -> next;
	last = secound_last -> next;
	secound_last -> next = NULL;
	last -> next = *stack;
	*stack = last;
}

void	rra(t_stack_node **stack_a, bool checker)
{
	reverse_rotate(stack_a);
	if (checker)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **stack_b, bool checker)
{
	reverse_rotate(stack_b);
	if (checker)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool checker)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (checker)
		ft_putstr_fd("rrr\n", 1);
}
