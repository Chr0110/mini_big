/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:29:45 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 07:45:35 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	path_error(char *cmd)
{
	ft_putstr(cmd, 2);
	ft_putstr(": No such file or directoryyyy\n", 2);
	exit(127);
}

char	*ft_path(char *av, char **env)
{
	char	*envp;
	char	**path;
	char	*cmdpath;
	int		i;

	i = -1;
	cmdpath = NULL;
	envp = NULL;
	if (check_path(env) == 1)
		path_error(av);
	else
	{
		path = find_path(env, i, envp);
		i = -1;
		while (path[++i])
		{
			cmdpath = ft_strjoin(path[i], "/");
			cmdpath = ft_strjoin(cmdpath, av);
			if (access(cmdpath, F_OK) == 0)
			{
				ft_free(path);
				return (cmdpath);
			}
		}
		ft_free(path);
		free (cmdpath);
	}
	return (NULL);
}

int	check_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**find_path(char **env, int i, char *envp)
{
	char	**path;

	path = NULL;
	while (env[++i])
	{
		envp = ft_strstr(env[i], "PATH");
		if (ft_strnstr(env[i], "PATH=", 5))
			break ;
	}
	path = ft_split(envp + 5, ':');
	return (path);
}
