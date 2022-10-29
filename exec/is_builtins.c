/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:07:45 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 18:12:08 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtins(char **bar)
{
	if (bar && bar[0] != NULL)
	{
		if (ft_strcmp(bar[0], "pwd") == 0 || ft_strcmp(bar[0], "PWD") == 0
			|| ft_strcmp("echo", bar[0]) == 0 || ft_strcmp("ECHO", bar[0]) == 0
			|| ft_strcmp(bar[0], "cd") == 0 || ft_strcmp(bar[0], "CD") == 0
			|| ft_strcmp(bar[0], "env") == 0 || ft_strcmp(bar[0], "ENV") == 0
			|| ft_strcmp(bar[0], "exit") == 0
			|| ft_strcmp(bar[0], "unset") == 0
			|| ft_strcmp(bar[0], "export") == 0)
			return (0);
	}
	return (1);
}

int	builtins(t_vars *vars, char **bar)
{
	int		i;
	char	*str;

	i = 0;
	if (bar && bar[0] != NULL)
	{
		if (ft_strcmp(bar[0], "pwd") == 0 || ft_strcmp(bar[0], "PWD") == 0)
			g_status = ft_pwd(vars);
		if (ft_strcmp(bar[0], "cd") == 0 || ft_strcmp(bar[0], "CD") == 0)
		{
			if (bar[1] == NULL)
			{
				str = find_user(vars);
				g_status = ft_chdir(str);
				free(str);
			}
			else
				g_status = ft_cd(bar);
		}
		if (bar && builtins2(vars, bar))
			return (1);
	}
	return (0);
}

int	builtins2(t_vars *vars, char **bar)
{
	if (ft_strcmp("echo", bar[0]) == 0 || ft_strcmp("ECHO", bar[0]) == 0)
	{
		if (bar[1] == NULL)
			ft_putchar_fd('\n', vars->outfile[vars->index]);
		else
			g_status = ft_echo(bar + 1, vars);
	}
	if (ft_strcmp(bar[0], "env") == 0 || ft_strcmp(bar[0], "ENV") == 0)
		g_status = ft_env(bar, vars);
	if (ft_strcmp(bar[0], "exit") == 0)
		g_status = ft_exit(bar);
	if (bar && ft_strcmp(bar[0], "export") == 0)
	{
		if (bar[1] != NULL)
				g_status = check_export5(bar, vars);
		else
			g_status = aff_export(vars);
	}
	if (ft_strcmp(bar[0], "unset") == 0)
	{
		g_status = ft_unset(bar, vars);
		g_status = unset_exp(bar, vars);
	}
	return (g_status);
}
