/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:16 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 20:54:02 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_initial_exec(t_vars *vars, char **env)
{	
	initial_env(vars, env);
	initial_exp(vars, env);
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
	vars->env = ft_calloc(sizeof(char *), SIZE_ALL);
	while (env[i])
	{
		vars->env[i] = ft_strdup(env[i]);
		i++;
	}
	vars->env[i] = NULL;
}

void	initial_exp(t_vars *vars, char **env)
{
	int	i;

	i = 0;
	vars->exp = ft_calloc(sizeof(char *), SIZE_ALL);
	while (vars->env[i])
	{
		vars->exp[i] = ft_strdup(env[i]);
		i++;
	}
	vars->exp[i] = NULL;
}
