/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:16 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/24 11:38:31 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_initial_exec(t_vars *vars, char **env)
{	
	vars->pwd = ft_strdup("");
	initial_env(vars, env);
	initial_exp(vars);
	ft_replace_shlvl(vars);
	ft_replace_oldpwd(vars);
	env_to_exp(vars);
	ft_replace(vars);
	ft_append(vars);
}

int	len_env(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}

void	initial_env(t_vars *vars, char **env)
{
	int	i;

	i = 0;

	if (!env)
		return ;
	vars->env = NULL;
	vars->env = malloc(sizeof(char *) * SIZE_ALL);
	while (env[i])
	{
		vars->env[i] = ft_strdup(env[i]);
		i++;
	}
	vars->env[i] = NULL;
}

void	initial_exp(t_vars *vars)
{
	int	i;

	i = 0;
	vars->exp = NULL;
	vars->exp = malloc(sizeof(char *) * SIZE_ALL);
	while (vars->env[i])
	{
		vars->exp[i] = vars->env[i];
		i++;
	}
	vars->exp[i] = NULL;
}

int	size_env(t_vars *vars)
{
	int	len;

	len = 0;
	while (vars->env[len])
		++len;
	return (len);
}

int	size_exp(t_vars *vars)
{
	int	len;

	len = 0;
	while (vars->exp[len])
		len++;
	return (len);
}
