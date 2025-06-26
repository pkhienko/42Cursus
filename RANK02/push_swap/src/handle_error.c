#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*cur;

	if (!*stack)
		return ;
	tmp = (*stack)->stack_a;
	while (tmp)
	{
		cur = tmp -> next;
		free(tmp);
		tmp = cur;
	}
	free(*stack);
}

void	free_memory(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_args(char **str)
{
	ft_putstr_fd("Error\n", 2);
	free_memory(str);
	exit(EXIT_FAILURE);
}

void	detect_error(t_stack **stack)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
