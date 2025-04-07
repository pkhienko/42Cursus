/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:48 by pkhienko          #+#    #+#             */
/*   Updated: 2024/10/07 21:29:16 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

void	parent_process(int *end, char **av, char **env);
void	child_process(int *end, char **av, char **env);
void	execve_command(char *cmd, char **env);
void	free_memory(char **str);

char	*search_env(char **env, char *toFind);
char	*search_cmd(char **env, char *cmd);

int		open_fd_file(char *av, int id);

#endif