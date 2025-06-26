/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:23 by pkhienko          #+#    #+#             */
/*   Updated: 2024/10/07 22:33:21 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execve_command(char *cmd, char **env)
{
	char	**all_cmd;
	char	**path;
	char	*cmd_path;

	all_cmd = ft_split(cmd, ' ');
	cmd_path = search_cmd(env, cmd);
	path = ft_split(cmd_path, ' ');
	if (!all_cmd || !path[0] || execve(path[0], all_cmd, env) == -1)
	{
		ft_putstr_fd("\033[1;31mExecve failed : command not found -> ", 2);
		ft_putstr_fd(all_cmd[0], 2);
		ft_putstr_fd("\n\033[0m", 2);
		free_memory(all_cmd);
		free_memory(path);
		if (access(cmd_path, F_OK | X_OK) == 0)
			free(cmd_path);
		exit(EXIT_FAILURE);
	}
}

void	put_here_doc(char *limit, int *end)
{
	char	*buffer;

	close(end[0]);
	while (1)
	{
		buffer = get_next_line(0);
		if (strncmp(buffer, limit, ft_strlen(limit)) == 0)
		{
			free(buffer);
			close(end[1]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(buffer, end[1]);
		free(buffer);
	}
}

void	here_doc_process(int ac, char *limit)
{
	int		end[2];
	pid_t	pid;

	if (ac < 6)
		handle_error();
	if (pipe(end) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		put_here_doc(limit, end);
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
		wait(NULL);
	}
}

void	child_process(char *cmd, char **env)
{
	int		end[2];
	pid_t	pid;

	search_env(env, "PATH");
	if (pipe(end) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		execve_command(cmd, env);
		close(end[1]);
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		wait(NULL);
		close(end[0]);
	}
}

int	main(int ac, char **av, char **env)
{
	int	cnt;
	int	infile;
	int	outfile;

	if (ac >= 5)
	{
		if (strncmp(av[1], "here_doc", 8) == 0)
		{
			cnt = 3;
			outfile = open_fd_file(av[ac - 1], 2);
			here_doc_process(ac, av[2]);
		}
		else
		{
			cnt = 2;
			infile = open_fd_file(av[1], 0);
			outfile = open_fd_file(av[ac - 1], 1);
			dup2(infile, STDIN_FILENO);
		}
		while (cnt < ac - 2)
			child_process(av[cnt++], env);
		dup2(outfile, STDOUT_FILENO);
		execve_command(av[ac - 2], env);
	}
	handle_error();
}
