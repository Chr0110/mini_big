/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:16:59 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 07:43:19 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(char **bar, t_vars *vars)
{
	int		j;
	char	**take;
	char	**barr;

	take = NULL;
	j = 0;
	check_export(bar, vars);
	bar = vars->bar;
	barr = sort_str(bar);
	while (barr[j])
	{
		ft_unset2(vars, barr[j], take);
		j++;
	}
	// ft_free(barr);
	return (0);
}

void	ft_unset2(t_vars *vars, char *barr, char **take)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	k = 0;
	len = size_env(vars);
	take = take_variable2(len, vars);
	while (i < len)
	{
		if (ft_strcmp(take[i], barr) == 0)
		{
			free(vars->env[i]);
			i++;
		}
		vars->env[k] = vars->env[i];
		k++;
		i++;
	}
	ft_free(take);
	vars->env[k] = NULL;
}
