/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:50:03 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/14 22:04:24 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(int index, char *raw, char *value, int type)
{
	t_token	*new;

	new = safealloc(1, sizeof(t_token));
	new->raw = raw;
	new->value = value;
	new->index = index;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	add_token(int index, char **str, short type, t_token **token)
{
	t_token	*new;

	new = new_token(index, str[0], str[1], type);
	ft_lstadd_back((t_list **)token, (t_list *)new);
}

t_token	*tokenizer(t_shell *shell)
{
	int			i;
	int			index;
	t_token		*token;

	i = 0;
	index = 0;
	token = NULL;
	while (shell->input[i])
	{
		i = skip_space(i, shell->input);
		if (!shell->input[i])
			break ;
		if (is_operator(shell->input[i]))
			i = handle_operators(i, shell, index, &token);
		else if (shell->input[i] == '\'' || shell->input[i] == '\"')
			i = handle_quotes(i, shell, index, &token);
		else
			i = handle_unquotes(i, shell, index, &token);
		index = add_subtoken_index(i, shell->input, index);
	}
	token = merge_subtokens(token);
	if (!validate_tokens(shell, token))
		return (NULL);
	return (token);
}
