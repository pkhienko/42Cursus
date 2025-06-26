#include "../include/push_swap.h"

t_stack_node	*lstnew(int content)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	node -> target = NULL;
	node -> cheapest = false;
	return (node);
}

int	lstsize(t_stack_node *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

t_stack_node	*lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*lastnode;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lastnode = lstlast(*lst);
	lastnode -> next = new;
}
