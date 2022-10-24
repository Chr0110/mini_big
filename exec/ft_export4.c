/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:37:47 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/24 13:30:13 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_export5(char **bar, t_vars *vars)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	vars->sar = NULL;
	vars->mar = NULL;
	check_export(bar, vars);
	while (bar[i])
		i++;
	vars->sar = malloc(sizeof(char *) * (i + 1));
	vars->mar = malloc(sizeof(char *) * (i + 1));
	check_export6(bar, vars, k);
	if (vars->n_sar > 1)
	{
		add_env(vars->sar, vars);
		remove_double(vars->sar, vars);
		add_export(vars->sar, vars);
	}
	else if (vars->n_mar > 1)
	{
		remove_double(vars->mar, vars);
		add_export(vars->mar, vars);
	}
	return (g_status);
}

void	check_export6(char **bar, t_vars *vars, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->sar[j] = ft_strdup(bar[0]);
	j = 1;
	while (bar[i])
	{
		if (ft_strchr(bar[i], '=') == 0)
		{
			vars->sar[j] =  ft_strdup(bar[i]);
			j++;
		}
		else
		{
			vars->mar[k] = ft_strdup(bar[i]);
			k++;
		}
		i++;
	}
	vars->sar[j] = NULL;
	vars->mar[k] = NULL;
	vars->n_sar = j;
	vars->n_mar = k;
}
