/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:20:21 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/25 11:20:12 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_replace_shlvl(t_vars *vars)
{
	int		i;
	int		len;

	i = 0;
	len = size_env(vars);
	while (vars->env[i] && i < len - 1)
	{
		if (ft_strncmp(vars->env[i], "SHLVL", 5) == 0)
		{
			ft_replace_shlvl2(vars, i);
			break ;
		}
		i++;
	}
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
	vars->env[i] = ft_strjoin("SHLVL=", n);
	free(str);
	free(n);
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
	ptr = ft_calloc(sizeof(char) , (len - i + 1));
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

	i = 0;
	j = 0;
	len = size_env(vars);
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

int	ft_replace_oldpwd2(t_vars *vars, char *oldpwd)
{
	int	i;
	int	len;

	i = 0;
	len = size_env(vars);
	while (i < len)
	{
		if (ft_strncmp(vars->env[i], "OLDPWD", 6) == 0)
		{
			free(vars->env[i]);
			vars->env[i] = oldpwd;
			vars->exp[i] = vars->env[i];
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_append(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->exp[i])
		i++;
	free(vars->exp[i]);
	vars->exp[i] = ft_strdup("OLDPWD");
	vars->exp[i + 1] = NULL;
}
