#include "../include/push_swap.h"

int	main(int ac, char *av[])
{
	t_stack			*stack;

	if (ac == 1)
		exit(EXIT_FAILURE);
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
	if (!is_sorted(stack -> stack_a))
	{
		if (lstsize(stack -> stack_a) == 2)
			sa(&stack -> stack_a, true);
		else if (lstsize(stack -> stack_a) == 3)
			sort_three(&stack -> stack_a);
		else
			sort_stack(&stack, lstsize(stack -> stack_a));
	}
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}
