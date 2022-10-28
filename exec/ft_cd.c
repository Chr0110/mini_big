/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:18:41 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 20:28:19 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_user(t_vars *vars)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (vars->env[i])
	{
		if (ft_strncmp(vars->env[i], "HOME", 4) == 0)
		{
			while (vars->env[i][j] != '=')
				j++;
			str = ft_strdup(vars->env[i] + j);
			while (vars->env[i][++j])
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

int	ft_chdir(char *ptr)
{
	if (chdir(ptr) == 0)
		return (0);
	else
	{
		ft_putstr(ptr, 2);
		ft_putstr(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

int	ft_cd(char **ptr)
{
	int	i;
	DIR	*dir;

	i = 0;
	dir = opendir(ptr[1]);
	if (!dir && !access(ptr[1], F_OK))
	{
		ft_putstr(ptr[1], 2);
		ft_putstr(": Not a directory\n", 2);
		ft_free(ptr);
		ptr = NULL;
	}
	else
	{
		if (ft_chdir(ptr[1]) == 1)
			return (1);
	}
	closedir(dir);
	return (0);
}
