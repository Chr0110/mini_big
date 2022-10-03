/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:29:45 by sriyani           #+#    #+#             */
/*   Updated: 2022/09/30 19:46:23 by sriyani          ###   ########.fr       */
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
	while (env[++i])
	{
		envp = ft_strstr(env[i], "PATH");
		if (ft_strnstr(env[i], "PATH=", 5))
			break ;
	}
	path = ft_split(envp + 5, ':');
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
	return (NULL);
}
