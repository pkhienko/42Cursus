/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:42:25 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/15 02:00:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_builtin(t_shell *shell, t_cmds *cmd)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (!ft_strncmp(cmd->cmd, "cd", -1) && ft_strlen(cmd->cmd) == 2)
		ret = ft_cd(shell, cmd->arg);
	else if (!ft_strncmp(cmd->cmd, "echo", -1) && ft_strlen(cmd->cmd) == 4)
		ret = ft_echo(cmd->arg);
	else if (!ft_strncmp(cmd->cmd, "env", -1) && ft_strlen(cmd->cmd) == 3)
		ret = ft_env(shell->env);
	else if (!ft_strncmp(cmd->cmd, "export", -1) && ft_strlen(cmd->cmd) == 6)
		ret = ft_export(shell, cmd->arg);
	else if (!ft_strncmp(cmd->cmd, "pwd", -1) && ft_strlen(cmd->cmd) == 3)
		ret = ft_pwd(shell);
	else if (!ft_strncmp(cmd->cmd, "unset", -1) && ft_strlen(cmd->cmd) == 5)
		ret = ft_unset(shell, cmd->arg);
	else if (!ft_strncmp(cmd->cmd, "exit", -1) && ft_strlen(cmd->cmd) == 4)
	{
		if (!cmd->prev)
			ret = ft_exit(shell, cmd->arg);
		else
			ret = CMD_NOT_FOUND;
	}
	return (ret);
}

static int	run_cmd(t_shell *shell, t_cmds *cmd, char *path, int ret)
{
	if (!cmd->cmd)
		return (EXIT_SUCCESS);
	if (execve(path, cmd->arg, get_envp(shell->env)) == -1 && !ret)
	{
		if (cmd->cmd[0] == '\0')
		{
			if (cmd->cmd[0] == '\0')
				ret = errmsg("''", NULL, "command not found", CMD_NOT_FOUND);
			else if (!cmd->io_fd->heredoc && cmd->cmd)
				ret = EXIT_FAILURE;
		}
		else
			ret = error_message(shell, cmd->cmd, true);
	}
	return (ret);
}

static pid_t	execute_cmd(t_shell *shell, t_cmds *cmd, char *c)
{
	int		ret;

	ret = EXIT_SUCCESS;
	set_sigint(&shell->sigint, SIG_IGN);
	set_sigquit(&shell->sigquit, SIG_IGN);
	shell->pid = fork();
	if (shell->pid == -1)
		exit_error(shell, errmsg("Fork", NULL, strerror(errno), 1));
	if (!shell->pid)
	{
		set_sigint(&shell->sigint, SIG_DFL);
		set_sigquit(&shell->sigquit, SIG_DFL);
		setup_pipe(cmd);
		ret = setup_redirect(cmd->io_fd, 0);
		if (ret)
			exit(ret);
		if (is_builtin(c))
			exit(execute_builtin(shell, cmd));
		else
			exit(run_cmd(shell, cmd, c, ret));
	}
	else
		close_pipe(cmd);
	return (shell->pid);
}

static int	
	get_children(t_shell *shell, pid_t last_pid, int ret, bool is_heredoc)
{
	get_sig_ret(shell, last_pid, &ret);
	is_heredoc = check_heredoc(shell->cmds);
	g_childern_code = 0;
	set_sigint(&shell->sigint, sighandler);
	set_sigquit(&shell->sigquit, SIG_IGN);
	if (shell->exit_code == 130 && is_heredoc)
		return (130);
	return (ret);
}

int	execute(t_shell *shell, t_cmds *cmd, pid_t last_pid)
{
	char	*path;
	int		ret;

	ret = EXIT_SUCCESS;
	g_childern_code = 1;
	while (cmd)
	{
		backup_io(cmd);
		if (is_builtin(cmd->cmd) && !cmd->next && !cmd->prev)
		{
			ret = setup_redirect(cmd->io_fd, 0);
			if (!ret)
				ret = execute_builtin(shell, cmd);
		}
		else
		{
			path = search_cmd(cmd->cmd, shell, &ret);
			if (!ret)
				last_pid = execute_cmd(shell, cmd, path);
		}
		restore_io(cmd->io_fd);
		cmd = cmd->next;
	}
	return (get_children(shell, last_pid, ret, false));
}
