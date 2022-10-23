/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:50:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/23 09:41:10 by sriyani          ###   ########.fr       */
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

int	check_export(char **bar, t_vars *vars)
{
	int	i;
	int	o;

	i = 1;
	o = 0;
	vars->bar = NULL;
	vars->bar = malloc(sizeof(char *) * SIZE_ALL);
	vars->bar[o] = "export";
	o = 1;
	while (bar[i])
	{
		check_export4(bar, vars, o, i);
		i++;
	}
	return (g_status);
}

int	check_export2(char **bar, int i, int j, int k)
{
	int	l;

	l = 0;
	while (bar[i][j])
	{
		if (ft_isalpha(bar[i][0]) == 0)
		{
			if (bar[i][0] != '_')
				k++;
				l++;
		}	
		else
		{
			if (ft_isalnum(bar[i][j]) == 0)
			{
				if (bar[i][j] != '=')
					k++;
					l++;
			}
		}
		j++;
	}
	print_export_error(l, bar, i);
	return (k);
}
void print_export_error(int l, char **bar, int i)
{
	if (l > 0)
	{
		ft_putstr(bar[i], 2);
		ft_putstr(": not a valid identifier\n", 2);
	}
}



int	check_export3(char **bar, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (bar[i][j])
	{
		if (ft_isalpha(bar[i][0]) == 0)
		{
			if (bar[i][0] != '_')
				k++;
		}
		j++;
	}
	return (k);
}

void	check_export4(char **bar, t_vars *vars, int o, int i)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	if (ft_strchr(bar[i], '=') != 0)
	{
		k = check_export2(bar, i, j, k);
		if (k == 0)
		{
			vars->bar[o] = bar[i];
			o++;
		}
	}
	else
	{
		k = check_export3(bar, i);
		if (k == 0)
		{
			vars->bar[o] = bar[i];
				o++;
		}
	}
	if (k > 0)
		g_status = 1;
	vars->bar[o] = NULL;
}
