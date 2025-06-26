/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:49:04 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/14 22:27:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*get_token_end(t_token *token)
{
	t_token	*cur;

	cur = token;
	while (cur)
	{
		if (cur->type == TK_PIPE)
			break ;
		if (!cur->next)
			break ;
		cur = cur->next;
	}
	return (cur);
}

void	handle_redirection(t_shell *shell, t_token *redir,
							t_token *file, t_io_fd *io_fd)
{
	if (!file || file->type != TK_WORD)
	{
		errmsg(redir->value, NULL, "missing file for redirection", 1);
		return ;
	}
	if (redir->type == TK_REDIRECT_IN && !io_fd->err_redir)
		redir_in(file, io_fd);
	else if (redir->type == TK_REDIRECT_OUT && !io_fd->err_redir)
		redir_out(file, io_fd);
	else if (redir->type == TK_APPEND && !io_fd->err_redir)
		redir_append(file, io_fd);
	else if (redir->type == TK_HEREDOC)
		io_fd->heredoc = handle_heredoc(shell, file, io_fd);
}

inline bool	is_valid_pipe(t_token *s, t_token *e)
{
	return (s && (s != e || s->type != TK_PIPE));
}
