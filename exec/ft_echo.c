/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:13:01 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/18 11:17:37 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_echo(char *str)
{
	int	i;
	int	j;

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

void	ft_echo(char **bar, t_vars *vars)
{
	int	j;
	int	y;

	j = 0;
	y = 0;
	while (bar[j])
		j++;
	option_echo(vars, bar, j, y);
	if (ft_check_echo(bar[0]) == 2)
		normal_echo(vars, bar, j);
}

void	option_echo(t_vars *vars, char **bar, int j, int y)
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
		print_echo(bar, vars, o, j);
	}
}

void	print_echo(char **bar, t_vars *vars, int o, int j)
{
	while (o < j)
	{
		ft_putstr(bar[o], vars->outfile[vars->index]);
		if (o < j - 1)
			ft_putstr(" ", vars->outfile[vars->index]);
		o++;
	}
}

void	normal_echo(t_vars *vars, char **bar, int j)
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
}
