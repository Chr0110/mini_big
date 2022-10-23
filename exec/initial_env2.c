/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:20:21 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/23 09:48:27 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_replace_shlvl(t_vars *vars)
{
	int		i;
	int		len;

	i = 0;
	len = size_env(vars);
	while (i < len)
	{
		if (ft_strncmp(vars->env[i], "SHLVL", 5) == 0)
			ft_replace_shlvl2(vars, i);
		i++;
	}
	vars->env[i] = NULL;
	env_to_exp(vars);
}

void	ft_replace_shlvl2(t_vars *vars, int i)
{
	int		a;
	char	*n;
	char	*str;

	a = 0;
	str = NULL;
	n = NULL;
	str = ft_copie_shlvl(vars->env[i]);
	a = atoi(str) + 1;
	n = ft_itoa(a);
	free(vars->env[i]);
	vars->env[i] =  NULL;
	vars->env[i] = ft_strjoin("SHLVL=", n);
	free(n);
	free(str);
}

char	*ft_copie_shlvl(char *str)
{
	int		i;
	int		j;
	char	*ptr;
	int		len;

	i = 0;
	j = 0;
	ptr = NULL;
	len = ft_strlen(str);
	while (str[i] != '=')
		i++;
	ptr = malloc(sizeof(char) * (len - i + 1));
	while (str[++i])
	{
		ptr[j] = str[i];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

void	ft_replace_oldpwd(t_vars *vars)
{
	int	i;
	int	j;
	int	len;

	len = size_env(vars);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_strncmp(vars->env[i], "OLDPWD", 6) == 0)
		{
			free(vars->env[i]);
			vars->env[i] = NULL;
			i++;
		}
		vars->env[j] = vars->env[i];
		j++;
		i++;
	}
	vars->env[j] = NULL;
}


void	ft_append(t_vars *vars)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = NULL;
	pwd = ft_strdup("OLDPWD");
	while (vars->exp[i])
		i++;
	free(vars->exp[i]);
	vars->exp[i] = NULL;
	vars->exp[i] = pwd;
	vars->exp[i + 1] = NULL;
}

