/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:58:05 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 19:54:54 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_double(t_vars *vars)
{
	char	**test;
	int		len;

	test = NULL;
	len = 0;
	while (vars->exp[len])
		++len;
	test = take_variable(len, vars);
	remove_double2(test, vars, len);
	ft_free(test);
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
			vars->exp[i] = NULL;
			i++;
		}
		vars->exp[j] = vars->exp[i];
		i++;
		j++;
	}
	vars->exp[j] = vars->exp[i];
	vars->exp[j + 1] = NULL;
}

char	**take_variable(int len, t_vars *vars)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = NULL;
	str = ft_calloc(sizeof(char *), (len + 1));
	while (i < len)
	{
		j = 0;
		str[i] = ft_calloc(sizeof(char), (ft_strlen(vars->exp[i]) + 1));
		if (ft_strchr(vars->exp[i], '=') == 0)
			str[i] = takevariable2(vars, str, i, j);
		else
			str[i] = ft_strcpy(str[i], vars->exp[i]);
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

	i = 1;
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
