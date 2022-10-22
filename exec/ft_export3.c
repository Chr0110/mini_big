/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:58:05 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 07:41:38 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_double(char **bar, t_vars *vars)
{
	char	**take;
	char	**test;
	int		len;

	take = NULL;
	test = NULL;
	len = 0;
	while (vars->exp[len])
		++len;
	take = take_bar(bar);
	test = take_variable(len, vars);
	remove_double2(test, vars, len);
}

void	remove_double2(char **test, t_vars *vars, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		if (ft_strcmp(test[i], test[i + 1]) == 0)
		{
			free(vars->exp[i]);
			i++;
		}
		vars->exp[j] = vars->exp[i];
		i++;
		j++;
	}
	vars->exp[j] = vars->exp[i];
	vars->exp[j + 1] = NULL;
	ft_free(test);
}

char	**take_variable(int len, t_vars *vars)
{
	int		i;
	int		j;
	char	**str;

	str = NULL;
	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * SIZE_ALL);
	while (i < len)
	{
		j = 0;
		str[i] = malloc(sizeof(char) * SIZE_ALL);
		if (ft_strchr(vars->exp[i], '=') == 0)
			str[i] = takevariable2(vars, str, i, j);
		else
			str[i] = ft_strdup(vars->exp[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	*takevariable2(t_vars *vars, char **str, int i, int j)
{
	while (vars->exp[i][j] != '=')
	{
		str[i][j] = vars->exp[i][j];
		j++;
	}
	str[i][j] = '\0';
	return (str[i]);
}

void	aff_export2(t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (vars->exp[k])
		++k;
	while (i < k)
	{
		ft_putstr("declare -x ", vars->outfile[vars->index]);
		if (ft_strchr(vars->exp[i], '=') == 0)
			aff_export3(vars, i);
		else
		{
			ft_putstr(vars->exp[i], vars->outfile[vars->index]);
			ft_putchar_fd('\n', vars->outfile[vars->index]);
		}
		i++;
	}
}
