/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko <pkhienko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:01:48 by pkhienko          #+#    #+#             */
/*   Updated: 2024/10/07 21:29:16 by pkhienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

# ifndef RW
#  define RW 0644
# endif

void	execve_command(char *cmd, char **env);
void	here_doc_process(int ac, char *limit);
void	child_process(char *cmd, char **env);
void	put_here_doc(char *limit, int *end);
void	free_memory(char **str);
void	handle_error(void);

char	*search_env(char **env, char *toFind);
char	*search_cmd(char **env, char *cmd);

int		open_fd_file(char *av, int id);

#endif