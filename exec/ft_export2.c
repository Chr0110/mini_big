/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:32:50 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 11:00:25 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**sort_str(char **ptr)
{
	int		i;
	int		j;
	char	*swap;
	int		len;

	i = 0;
	swap = NULL;
	len = lent(ptr);
	while (ptr[i] && i < len - 1)
	{
		j = i + 1;
		while (ptr[j] && j < len)
		{
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

int	lent(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
		len++;
	return (len);
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

int	aff_export(t_vars *vars)
{
	int	len;

	len = size_exp(vars);
	if (vars->exp)
		sort_str(vars->exp);
	remove_double(vars);
	aff_export2(vars);
	return (0);
}

void	add_export(char **bar, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->exp && vars->exp[i])
		++i;
	while (bar && bar[j])
	{
		vars->exp[i] = ft_strdup(bar[j]);
		j++;
		i++;
	}
	vars->exp[i] = NULL;
}
