/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:03:17 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/18 17:11:01 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_isdouble(char **test, int len, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_strcmp(test[i], str) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**take_variable2(int len, t_vars *vars)
{
	char	**var;
	int		i;
	int		j;

	i = 0;
	j = 0;
	var = NULL;
	var = malloc(sizeof(char *) * size_all);
	while (i < len)
	{
		j = 0;
		var[i] = malloc(sizeof(char) * size_all);
		while (vars->env[i][j] != '=')
		{
			var[i][j] = vars->env[i][j];
			j++;
		}
		var[i][j] = '\0';
		i++;
	}
	var[i] = NULL;
	return (var);
}

void	remove_str(char **test, char *str, t_vars *vars, char *bar)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (test[len])
		++len;
	while (i < len)
	{
		if (ft_strcmp(test[i], str) == 0)
			i++;
		vars->env[j] = vars->env[i];
		i++;
		j++;
	}
	vars->env[j] = NULL;
}

char	**take_bar(char **bar, t_vars *vars)
{
	int		i;
	char	**barr;

	i = 0;
	barr = NULL;
	barr = malloc(sizeof(char *) * size_all);
	while (bar[i])
	{
		barr[i] = malloc(sizeof(char *) * size_all);
		if (ft_strchr(bar[i], '=') == 0)
			take_bar2(barr, bar, i);
		else
			barr[i] = ft_strdup(bar[i]);
		i++;
	}
	barr[i] = NULL;
	return (barr);
}

void	take_bar2(char **barr, char **bar, int i)
{
	int	j;

	j = 0;
	while (bar[i][j] != '=')
	{
		barr[i][j] = bar[i][j];
		j++;
	}
	barr[i][j] = '\0';
}
