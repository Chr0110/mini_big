/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:21:58 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:47:28 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_remove(char **str, char *ptr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_strcmp(str[i], ptr) == 0)
		{
			free(str[i]);
			i++;
		}
		str[j] = str[i];
		i++;
		j++;
	}
	return (str);
}

void	ft_replace(t_vars *vars)
{
	int		i;
	int		len;
	char	*pwd;
	char	*tmp;

	i = 0;
	tmp = NULL;
	pwd = getcwd(NULL, 0);
	len = size_env(vars);
	while (i < len)
	{
		if (ft_strncmp(vars->env[i], "PWD=", 4) == 0)
		{
			tmp = ft_strjoin("PWD=", pwd);
			free(vars->env[i]);
			vars->env[i] = tmp;
		}
		i++;
	}
	vars->env[i] = NULL;
	ft_replace2(vars);
	vars->pwd = ft_strdup(pwd);
}

void	ft_replace2(t_vars *vars)
{
	int	len;
	char *oldpwd;

	len = 0;
	oldpwd = NULL;
	if (ft_strcmp(vars->pwd, "\0") != 0)
	{
		len = size_env(vars);
		oldpwd = ft_strjoin("OLDPWD=", vars->pwd);
		free(vars->env[len]);
		vars->env[len] = oldpwd;
	}
	env_to_exp(vars);
	free(oldpwd);
}
