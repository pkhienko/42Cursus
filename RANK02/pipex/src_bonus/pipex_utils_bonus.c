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

void	handle_error(void)
{
	ft_putstr_fd("\033[1;32mRun as follows -> ", 2);
	ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
	ft_putstr_fd("Run as follows -> ", 2);
	ft_putstr_fd("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 2);
	ft_putstr_fd("Run as follows -> ", 2);
	ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 file\n\033[0m", 2);
	exit(EXIT_SUCCESS);
}

void	free_memory(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	open_fd_file(char *av, int id)
{
	int	newfd;

	if (id == 0)
		newfd = open(av, O_RDONLY, RW);
	else if (id == 1)
		newfd = open(av, O_WRONLY | O_CREAT | O_TRUNC, RW);
	else if (id == 2)
		newfd = open(av, O_WRONLY | O_CREAT | O_APPEND, RW);
	if (newfd == -1)
	{
		perror("Error opening file for reading");
		exit(EXIT_FAILURE);
	}
	return (newfd);
}

char	*search_env(char **env, char *toFind)
{
	char	*path;
	int		i;
	int		j;

	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		path = ft_substr(env[i], 0, j);
		if (ft_strncmp(toFind, path, 4) == 0)
		{
			free(path);
			return (&env[i][j + 1]);
		}
		free(path);
	}
	ft_putstr_fd("\033[1;31mError: Path environment not found.\n\033[0m", 2);
	exit(EXIT_FAILURE);
}

char	*search_cmd(char **env, char *cmd)
{
	char	**all_path;
	char	**all_cmd;
	char	*select_path;
	char	*select_cmd;
	int		i;

	all_path = ft_split(search_env(env, "PATH"), ':');
	all_cmd = ft_split(cmd, ' ');
	i = -1;
	while (all_path[++i])
	{
		select_path = ft_strjoin(all_path[i], "/");
		select_cmd = ft_strjoin(select_path, all_cmd[0]);
		free(select_path);
		if (select_cmd && access(select_cmd, F_OK | X_OK) == 0)
		{
			free_memory(all_path);
			free_memory(all_cmd);
			return (select_cmd);
		}
		free(select_cmd);
	}
	free_memory(all_path);
	free_memory(all_cmd);
	return (cmd);
}
