/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:13:01 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 14:17:22 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_echo(char *str)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (str[0] == '-' && str[i] == 'n')
			j++;
		i++;
	}
	if (j == ft_strlen(str) - 1 && j >= 1)
		return (1);
	return (2);
}

int	ft_echo(char **bar, t_vars *vars)
{
	int	j;
	int	y;

	j = 0;
	y = 0;
	while (bar[j])
		j++;
	if (option_echo(vars, bar, j, y) == 1)
		return (1);
	if (ft_check_echo(bar[0]) == 2)
	{
		if (normal_echo(vars, bar, j) == 1)
			return (1);
	}
	return (0);
}

int	option_echo(t_vars *vars, char **bar, int j, int y)
{
	int	o;
	int	k;

	o = 0;
	k = 0;
	while (o < j)
	{
		if (bar[o][0] == '-')
		{
			if (ft_check_echo(bar[o]) == 1 && o == y)
			{
				k++;
				y++;
			}
		}
		o++;
	}
	if (k > 0)
	{
		o = k;
		if (print_echo(bar, vars, o, j) == 1)
			return (1);
	}
	return (0);
}

int	print_echo(char **bar, t_vars *vars, int o, int j)
{
	while (o < j)
	{
		ft_putstr(bar[o], vars->outfile[vars->index]);
		if (o < j - 1)
			ft_putstr(" ", vars->outfile[vars->index]);
		o++;
	}
	if (o == j)
		return (0);
	return (1);
}

int	normal_echo(t_vars *vars, char **bar, int j)
{
	int	o;

	o = 0;
	while (o < j)
	{
		ft_putstr(bar[o], vars->outfile[vars->index]);
		if (o < j - 1)
			ft_putstr(" ", vars->outfile[vars->index]);
		if (o == j - 1)
			ft_putchar_fd('\n', vars->outfile[vars->index]);
		o++;
	}
	if (o == j)
		return (1);
	return (0);
}
