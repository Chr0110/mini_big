/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:32:50 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/25 15:32:10 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**sort_str(char **ptr)
{
	int		i;
	int		j;
	char	*swap;
	char *test;
	int len = 0;

	i = 0;
	j = 0;
	swap = NULL;
	while(ptr[len])
		len++;
	while (ptr[i] && i < len -1)
	{
		j = i + 1;
		
		while (ptr[j] && j < len)
		{
			test = ptr[j];
			if (ft_strcmp(ptr[i], ptr[j]) < 0)
			{
				swap = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (ptr);
}

void	env_to_exp(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->env[i])
	{
		vars->exp[i] = vars->env[i];
		i++;
	}
	vars->exp[i] = NULL;
}

int	aff_export(char **bar, t_vars *vars)
{
	int len;
	int i = 0;
	len = size_exp(vars);
	if (vars->exp)
		sort_str(vars->exp);
	remove_double(bar, vars);
	aff_export2(vars);
	return (0);
}

void	add_export(char **bar, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->exp[i])
		++i;
	while (bar[j])
	{
		vars->exp[i] = ft_strdup(bar[j]);
		j++;
		i++;
	}
	// vars->exp[i] = NULL;
	remove_double(bar, vars);
}
