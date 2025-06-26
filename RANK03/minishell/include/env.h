/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhienko42 <pkhienko42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:42:35 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/13 23:20:39 by pkhienko42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_shell	t_shell;

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			equal;
	char			*value;
}	t_env;

void	del_env(t_env **env, char *key);
void	set_env(t_env **env, char *key, char *value);

char	*dup_var(char *str, char c);
char	*get_value(t_env *env, char *key);

t_env	*dup_env(char **env);
t_env	*search_env(t_env *env, char *key);
t_env	*new_env(char *key, char equal, char *value);

#endif