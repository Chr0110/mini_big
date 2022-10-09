/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:18:41 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/09 14:44:12 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *find_user(t_vars *vars)
{
	int i;
	int  j;
	int k;
	char *str;
	j = 0;
	i = 0;
	k = 0;
	str = ft_strdup("");
	while(vars->env[i])
	{
		if(ft_strncmp(vars->env[i],"HOME", 4) == 0)
		{
			while(vars->env[i][j] != '=')
				j++;
			while(vars->env[i][++j])
			{
				str[k] = vars->env[i][j];
				k++;
			}
			str[k] = '\0';
		}
		i++;
	}
	return (str);
}

void	ft_chdir(char *ptr, t_vars *vars)
{
	if(chdir(ptr) == 0)
		ft_replace(vars); 
	else
	{
		ft_putstr(ptr, 2);
		ft_putstr(": No such file or directory\n", 2);
	}
	
}

void ft_cd(char **ptr, t_vars *vars)
{
	int i;
	
	i = 0;
	ft_chdir(ptr[1], vars);
}