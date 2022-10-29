/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:37:47 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 11:04:04 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_eq(char **bar)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (bar && bar[i])
	{
		if (ft_strchr(bar[i], '=') == 0)
			k++;
		i++;
	}
	return (k);
}

void	ft_free_(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
}

int	check_export5(char **bar, t_vars *vars)
{
	int	i;

	i = 0;
	vars->n_sar = 0;
	vars->n_mar = 0;
	vars->sar = NULL;
	vars->mar = NULL;
	check_export(bar, vars);
	if (!vars->bar)
		return (1);
	if (vars->bar)
	{
		ft_free_(bar);
		while (vars->bar[i])
		{
			bar[i] = ft_strdup(vars->bar[i]);
				i++;
		}
	}
	ft_free(vars->bar);
	vars->bar = NULL;
	check_export5_2(bar, vars, i);
	return (g_status);
}

void	check_export5_2(char **bar, t_vars *vars, int i)
{
	int	k;

	k = count_eq(bar);
	if (i)
	{
		if (k)
			vars->sar = ft_calloc(sizeof(char *), (k + 1));
		if (i - k)
			vars->mar = ft_calloc(sizeof(char *), (i - k + 1));
	}
	k = 0;
	check_export6(bar, vars, k);
	if (vars->n_sar > 0)
	{
		add_env(vars->sar, vars);
		remove_double(vars);
		add_export(vars->sar, vars);
	}
	if (vars->n_mar > 0)
	{
		remove_double(vars);
		add_export(vars->mar, vars);
	}
}

void	check_export6(char **bar, t_vars *vars, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (bar && bar[i])
	{
		if (ft_strchr(bar[i], '=') == 0)
		{
			vars->sar[j] = ft_strdup(bar[i]);
			j++;
		}
		else
		{
			vars->mar[k] = ft_strdup(bar[i]);
			k++;
		}
		i++;
	}
	vars->n_sar = j;
	vars->n_mar = k;
}
