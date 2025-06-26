#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					content;
	int					idx;
	int					shift_cost;
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
}	t_stack;

//init_stack
char			**split_all(int ac, int i, int j, char **av);
t_stack_node	*init_stack(int i, char **av, t_stack **stack);

//init_a
t_stack_node	*find_cheapest(t_stack_node *stack);
void			init_a(t_stack_node *stack_a, t_stack_node *stack_b);

//init_b
void			init_b(t_stack_node *stack_a, t_stack_node *stack_b);

//sort_stack
int				is_sorted(t_stack_node *stack);
void			sort_three(t_stack_node	**stack);
void			sort_stack(t_stack **stack, int size);

//handle_error
void			free_args(char **str);
void			free_memory(char **str);
void			free_stack(t_stack	**stack);
void			detect_error(t_stack **stack);

//stack_utils
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			min_on_top(t_stack_node **stack);
void			set_index(t_stack_node *stack, int size);
void			shift_to_top(t_stack_node **stack,
					t_stack_node *top_node,
					char to_do);

//list_utils
t_stack_node	*lstnew(int content);
t_stack_node	*lstlast(t_stack_node *stack);
int				lstsize(t_stack_node *stack);
void			lstadd_back(t_stack_node **lst, t_stack_node *new);

//push_cmd
void			pa(t_stack_node **stack_a, t_stack_node **stack_b,
					bool checker);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b,
					bool checker);
void			push_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			push_to_b(t_stack_node **stack_a, t_stack_node **stack_b);

//swap_cmd
void			sa(t_stack_node **stack_a, bool checker);
void			sb(t_stack_node **stack_b, bool checker);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b,
					bool checker);

//rotate_cmd
void			ra(t_stack_node **stack_a, bool checker);
void			rb(t_stack_node **stack_b, bool checker);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b,
					bool checker);

//reverse_rotate
void			rra(t_stack_node **stack_a, bool checker);
void			rrb(t_stack_node **stack_b, bool checker);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b,
					bool checker);

#endif
