#include "../include/push_swap.h"

static void	check_command(t_stack **stack, char *cmd, int size_cmd)
{
	if (!ft_strncmp("pa\n", cmd, size_cmd))
		pa(&(*stack)->stack_a, &(*stack)->stack_b, false);
	else if (!ft_strncmp("pb\n", cmd, size_cmd))
		pb(&(*stack)->stack_a, &(*stack)->stack_b, false);
	else if (!ft_strncmp("sa\n", cmd, size_cmd))
		sa(&(*stack)->stack_a, false);
	else if (!ft_strncmp("sb\n", cmd, size_cmd))
		sb(&(*stack)->stack_b, false);
	else if (!ft_strncmp("ss\n", cmd, size_cmd))
		ss(&(*stack)->stack_a, &(*stack)->stack_b, false);
	else if (!ft_strncmp("ra\n", cmd, size_cmd))
		ra(&(*stack)->stack_a, false);
	else if (!ft_strncmp("rb\n", cmd, size_cmd))
		rb(&(*stack)->stack_b, false);
	else if (!ft_strncmp("rr\n", cmd, size_cmd))
		rr(&(*stack)->stack_a, &(*stack)->stack_b, false);
	else if (!ft_strncmp("rra\n", cmd, size_cmd))
		rra(&(*stack)->stack_a, false);
	else if (!ft_strncmp("rrb\n", cmd, size_cmd))
		rrb(&(*stack)->stack_b, false);
	else if (!ft_strncmp("rrr\n", cmd, size_cmd))
		rrr(&(*stack)->stack_a, &(*stack)->stack_b, false);
	else
		detect_error(stack);
}

static void	check_sorted(t_stack **stack, int size)
{
	char	*buffer;

	buffer = get_next_line(0);
	while (buffer)
	{
		check_command(stack, buffer, ft_strlen(buffer));
		free(buffer);
		buffer = get_next_line(0);
	}
	free(buffer);
	if (is_sorted((*stack)->stack_a) && lstsize((*stack)->stack_a) == size)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char *av[])
{
	t_stack	*stack;
	int		size_a;

	if (ac == 1)
		exit(EXIT_SUCCESS);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	stack -> stack_b = NULL;
	if (ac == 2)
		stack -> stack_a = init_stack(-1, ft_split(av[1], ' '), &stack);
	else if (ac > 2)
		stack -> stack_a = init_stack(-1, split_all(ac, 0, 0, av), &stack);
	if (!stack -> stack_a)
		detect_error(&stack);
	size_a = lstsize(stack -> stack_a);
	check_sorted(&stack, size_a);
	free_stack(&stack);
	exit(EXIT_FAILURE);
}
