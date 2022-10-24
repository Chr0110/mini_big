/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:21:58 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/24 14:18:09 by sriyani          ###   ########.fr       */
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
			str[i] = NULL;
			i++;
		}
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}

void	ft_replace(t_vars *vars)
{
	int		i;
	int		len;
	char	*pwd;
	// char	*tmp;

	i = 0;
	// tmp = NULL;
	pwd = getcwd(NULL, 0);
	len = size_env(vars);
	while (i < len)
	{
		if (ft_strncmp(vars->env[i], "PWD=", 4) == 0)
		{
			// tmp = ft_strjoin("PWD=", pwd);
			// free(vars->env[i]);
			// vars->env[i] = NULL;
			vars->env[i] = ft_strjoin("PWD=", pwd);
			break ;
		}
		i++;
	}
	// vars->env[i] = NULL;
	ft_replace2(vars);
	free(vars->pwd);
	vars->pwd = NULL;
	vars->pwd = ft_strdup(pwd);
	free(pwd);
}

void	ft_replace2(t_vars *vars)
{
	int	len;
	char *oldpwd;

	len = 0;
	oldpwd = NULL;
	if (vars->pwd[0] != '\0')
	{
		len = size_env(vars);
		oldpwd = ft_strjoin("OLDPWD=", vars->pwd);
		free(vars->env[len]);
		vars->env[len] = NULL;
		vars->env[len] = oldpwd;
		vars->env[len + 1] = NULL;
		env_to_exp(vars);
	}
}
