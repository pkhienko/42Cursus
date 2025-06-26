#include "pipex.h"

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
		newfd = open(av, O_RDONLY, 0777);
	else if (id == 1)
		newfd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
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
	return (NULL);
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
		if (access(select_cmd, F_OK | X_OK) == 0)
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
