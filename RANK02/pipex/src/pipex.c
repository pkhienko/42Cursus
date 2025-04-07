/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:23 by pkhienko          #+#    #+#             */
/*   Updated: 2024/10/07 22:33:21 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_command(char *cmd, char **env)
{
	char	**all_cmd;
	char	**path;
	char	*cmd_path;

	all_cmd = ft_split(cmd, ' ');
	cmd_path = search_cmd(env, cmd);
	path = ft_split(cmd_path, ' ');
	if (execve(path[0], all_cmd, env) == -1)
	{
		ft_putstr_fd("\033[1;31mExecve failed : command not found -> ", 2);
		ft_putstr_fd(all_cmd[0], 2);
		ft_putstr_fd("\n\033[0m", 2);
		free_memory(all_cmd);
		free_memory(path);
		exit(EXIT_FAILURE);
	}
}

void	child_process(int *end, char **av, char **env)
{
	int	fd;

	fd = open_fd_file(av[1], 0);
	close(end[0]);
	dup2(fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	execve_command(av[2], env);
	close(fd);
	close(end[1]);
}

void	parent_process(int *end, char **av, char **env)
{
	int	fd;

	fd = open_fd_file(av[4], 1);
	close(end[1]);
	wait(NULL);
	dup2(fd, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	execve_command(av[3], env);
	close(fd);
	close(end[0]);
}

int	main(int ac, char **av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (ac != 5)
		ft_putstr_fd("Run as follows -> ./pipex file1 cmd1 cmd2 file2\n", 2);
	else
	{
		if (pipe(end) == -1)
		{
			perror("Error creating pipe");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error forking");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			child_process(end, av, env);
		parent_process(end, av, env);
	}
	exit(EXIT_SUCCESS);
}
