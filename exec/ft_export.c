/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:50:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 10:57:33 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	aff_export3(t_vars *vars, int i)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen(vars->exp[i]) - 1;
	while (vars->exp[i][j])
	{
		if (vars->exp[i][j] == '=')
		{
			ft_putchar_fd(vars->exp[i][j], vars->outfile[vars->index]);
			ft_putchar_fd('\"', vars->outfile[vars->index]);
			if (vars->exp[i][j + 1] == '\0')
				ft_putchar_fd('\"', vars->outfile[vars->index]);
			j++;
		}
		if (j == len)
		{
			ft_putchar_fd(vars->exp[i][j], vars->outfile[vars->index]);
			ft_putchar_fd('\"', vars->outfile[vars->index]);
		}
		else
			ft_putchar_fd(vars->exp[i][j], vars->outfile[vars->index]);
	j++;
	}
	ft_putchar_fd('\n', vars->outfile[vars->index]);
}

int	lent_bar(char **bar)
{
	int	i;

	i = 1;
	while (bar && bar[i])
		i++;
	return (i);
}

int	check_export(char **bar, t_vars *vars)
{
	int	i;
	int	k;
	int	j;

	k = 0;
	j = 0;
	i = lent_bar(bar);
	vars->bar = ft_calloc(sizeof(char *), i);
	i = 1;
	check_export1(bar, vars, i, j);
	return (g_status);
}

void	check_export1(char **bar, t_vars *vars, int i, int j)
{
	int	k;

	k = 0;
	while (bar && bar[i])
	{
		if (ft_isalpha(bar[i][0]) == 0 && bar[i][0] != '_')
			k++;
		k += check_export2(bar, i);
		if (k == 0)
		{
			vars->bar[j] = ft_strdup(bar[i]);
			j++;
		}
		if (k > 0 || !ft_strcmp(bar[i], ""))
		{
			ft_putstr(bar[i], 2);
			ft_putstr(": not a valid identifier\n", 2);
				k = 0;
			g_status = 1;
		}
		i++;
	}
	vars->bar[j] = NULL;
}

int	check_export2(char **bar, int i)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (bar[i][j])
	{
		if (bar[i][j] == '=')
			break ;
		if (!ft_isalnum(bar[i][j]) && bar[i][j] != '_')
				k++;
		j++;
	}
	if (k > 0)
		return (k);
	if (bar[i][j] == '=' || !bar[i][j])
		return (0);
	return (k);
}
