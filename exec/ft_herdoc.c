/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:25:41 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 07:50:13 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*creat_name(int i)
{
	char		*str;
	char		*ptr;
	static int	k;
	int			j;

	i = 0;
	j = 0;
	ptr = NULL;
	ptr = malloc(sizeof(char) * 6);
	str = "abcdefghijklmnopqrstuvwxyz0123456789";
	while (j < 5)
	{
		if (k % 2 == 0)
		{
			ptr[j] = str[k - j];
			j++;
		}
		if ((k - j) > 36)
			k = 0;
		k += 3;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_expand(t_vars *vars, char *ptr)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = 0;
	j = 0;
	while (vars->env[i])
	{
		if (ft_strncmp(vars->env[i], ptr + 1, ft_strlen(ptr + 1)) == 0)
		{
			while (vars->env[i][j] != '=')
				j++;
			str = ft_expand2(vars, i, j);
			break ;
		}
		i++;
	}
	return (str);
}

char	*ft_expand2(t_vars *vars, int i, int j)
{
	int		k;
	char	*str;

	str = NULL;
	k = 0;
	str = ft_strdup(vars->env[i] + j);
	while (vars->env[i][++j])
	{
		str[k] = vars->env[i][j];
		k++;
	}
	str[k] = '\0';
	return (str);
}
