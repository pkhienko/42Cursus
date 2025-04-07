#include "../include/push_swap.h"

static long	ft_atol(const char *nptr)
{
	long	result;
	int		mult;

	if (!nptr)
		return (0);
	mult = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			mult *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (result * mult);
}

static int	check_arg(char *s, int n, t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				i;

	i = -1;
	while (s[++i])
		if (!(((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]) && i == 0)
				|| ft_isdigit(s[i])))
			return (0);
	tmp = stack;
	while (tmp)
	{
		if (tmp -> content == n)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

static int	count_word(char *s, char c)
{
	int	sep;

	sep = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			sep++;
		s++;
	}
	return (sep);
}

char	**split_all(int ac, int i, int j, char **av)
{
	char	**words;
	char	**res;
	int		cnt_word;
	int		idx;

	cnt_word = 0;
	while (++i < ac)
		cnt_word += count_word(av[i], ' ');
	res = (char **)malloc(sizeof(char *) * (cnt_word + 1));
	if (!res)
		return (NULL);
	i = 0;
	idx = 0;
	while (++i < ac)
	{
		words = ft_split(av[i], ' ');
		if (!*words)
			free_args(words);
		j = 0;
		while (words[j])
			res[idx++] = words[j++];
		free(words);
	}
	res[idx] = 0;
	return (res);
}

t_stack_node	*init_stack(int i, char **av, t_stack **stack)
{
	t_stack_node	*new_list;
	t_stack_node	*new_node;
	long long		nb;

	new_list = NULL;
	while (av[++i])
	{
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN || !check_arg(av[i], nb, new_list))
		{
			(*stack)->stack_a = new_list;
			free_memory(av);
			detect_error(stack);
		}
		new_node = lstnew(nb);
		lstadd_back(&new_list, new_node);
	}
	free_memory(av);
	return (new_list);
}
