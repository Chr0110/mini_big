/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:42:29 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 13:40:19 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**take_variable_exp(int len, t_vars *vars)
{
	int		i;
	char	**var;

	i = 0;
	var = ft_calloc(sizeof(char *), (len + 1));
	while (i < len)
	{
		
		if (ft_strchr(vars->exp[i], '=') == 0)
		{
			var[i] = ft_calloc(sizeof(char), (ft_strlen(vars->exp[i]) + 1));
			var[i] = take_variable_exp2(var, vars, i);
		}
		else
			var[i] = ft_strdup(vars->exp[i]);
		i++;
	}
	var[i] = NULL;
	return (var);
}

char	*take_variable_exp2(char **var, t_vars *vars, int i)
{
	int	j;

	j = 0;
	while (vars->exp[i][j] != '=')
	{
		var[i][j] = vars->exp[i][j];
		j++;
	}
	var[i][j] = '\0';
	return (var[i]);
}
// int	unset_exp1(char **bar, t_vars *vars)
// {
// 	int		j;
// 	int		i;

// 	i = 0;
// 	j = 0;
// 	check_export(bar, vars);
// 	if (!vars->bar)
// 		return (1);
// 	if (vars->bar)
// 	{
// 		ft_free_(bar);
// 		while (vars->bar[i])
// 		{
// 			bar[i] = ft_strdup(vars->bar[i]);
// 				i++;
// 		}
// 	}
// 	ft_free(vars->bar);
// 	vars->bar = NULL;
// 	unset_exp(bar, vars);
// 	return (0);
// }

int	unset_exp(char **bar, t_vars *vars)
{
	int		j;
	char	**barr;
	int		len;

	j = 0;
	barr = sort_str(bar);
	while (barr[j])
	{
		ft_unset_exp2(vars, barr[j]);
		j++;
	}
	return (0);
}

void	ft_unset_exp2(t_vars *vars, char *barr)
{
	int		i;
	int		len;
	int		k;
	char	**take;

	i = 0;
	k = 0;
	len = size_exp(vars);
	take = take_variable_exp(len, vars);
	while (i < len)
	{
		if (vars->exp[i] && ft_strcmp(take[i], barr) == 0)
		{	
			free(vars->exp[i]);
			vars->exp[i] = NULL;
			i++;
		}
		vars->exp[k] = vars->exp[i];
		k++;
		i++;
	}
	ft_free(take);
	vars->exp[k] = NULL;
}
