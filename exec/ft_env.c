/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:17:32 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/18 17:09:05 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	aff_env(char **ptr, t_vars *vars)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		ft_putstr(ptr[i], vars->outfile[vars->index]);
		ft_putchar_fd('\n', vars->outfile[vars->index]);
		i++;
	}
}

void	add_env(char **bar, t_vars *vars)
{
	int		j;
	char	**test;
	char	**barr;
	int		len;

	len = 0;
	j = 1;
	while (vars->env[len])
		++len;
	if (bar[1] != NULL)
		barr = take_bar(bar, vars);
	while (bar[j])
	{	
		test = take_variable2(len, vars);
		if (check_isdouble(test, len, barr[j]) == 0)
		{
			remove_str(test, barr[j], vars, bar[j]);
			j = 1;
			len--;
		}
		j++;
		ft_free(test);
	}
	add_bar_to_env(len, barr, bar, vars);
}

void	add_bar_to_env(int len, char **barr, char **bar, t_vars *vars)
{
	char	**test;
	int		j;

	j = 1;
	while (bar[j])
	{	
		test = take_variable2(len, vars);
		if (check_isdouble(test, len, barr[j]) == 1)
		{
			vars->env[len] = ft_strdup(bar[j]);
			len++;
		}
		j++;
	}
	vars->env[len] = NULL;
}

void	ft_env(char **bar, t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (bar[j])
		++j;
	while (i < j)
	{
		if (ft_strcmp(bar[i], "env") == 0 || ft_strcmp(bar[i], "ENV") == 0)
			k++;
		i++;
	}
	if (k != j)
		ft_putstr("env: No such file or directory\n", 2);
	else
	{
		add_env(bar, vars);
		aff_env(vars->env, vars);
	}
}
