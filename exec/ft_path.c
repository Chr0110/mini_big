/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:29:45 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/04 15:56:45 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path(char *av, char **env)
{
	char	*envp;
	char	**path;
	char	*cmdpath;
	int		i;

	i = -1;
	cmdpath = NULL;
	if(check_path(env) == 1)
		ft_putstr_fd("No such file or directory\n", 2);
	else
	{
		path = find_path(env, i, envp);
		i = -1;
		while (path[++i])
		{
			cmdpath = ft_strjoin(path[i], "/");
			cmdpath = ft_strjoin(cmdpath, av);
			if (access(cmdpath, F_OK) == 0)
				return (cmdpath);
		}
		ft_free(path);
		free (cmdpath);
	}
	return (NULL);
}

int check_path(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (0);
		i++;
	}
	return (1);
}

char **find_path(char **env, int i, char *envp)
{
	char **path;
	
	while (env[++i])
	{
		envp = ft_strstr(env[i], "PATH");
		if (ft_strnstr(env[i], "PATH=", 5))
			break ;
	}
	path = ft_split(envp + 5, ':');
	return (path);
}