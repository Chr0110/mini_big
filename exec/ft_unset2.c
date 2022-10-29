/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:16:59 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 13:29:15 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(char **bar, t_vars *vars)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
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
	ft_unset1(vars, bar);
	return (0);
}

void	ft_unset1(t_vars *vars, char **bar)
{
	char	**barr;
	int		j;

	j = 0;
	barr = sort_str(bar);
	while (barr[j])
	{
		ft_unset2(vars, barr[j]);
		j++;
	}
}

void	ft_unset2(t_vars *vars, char *barr)
{
	int	i;
	int	k;
	int	len;
	char **take;

	i = 0;
	k = 0;
	len = size_env(vars);
	take = take_variable2(len, vars);
	while (i < len)
	{
		if (vars->env[i] && ft_strcmp(take[i], barr) == 0)
		{
			free(vars->env[i]);
			vars->env[i] = NULL;
			i++;
		}
		vars->env[k] = vars->env[i];
		k++;
		i++;
	}
	vars->env[k] = NULL;
	ft_free(take);
}
