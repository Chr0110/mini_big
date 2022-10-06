/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:18:41 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/03 15:27:56 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chdir(char *ptr, t_vars *vars)
{
	if(chdir(ptr) == 0)
	{
		ft_replace(vars);
	}
	else
	{
		ft_putstr_fd(ptr, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	
}

void ft_cd(char **ptr, t_vars *vars)
{
	int i;
	
	i = 0;
	ft_chdir(ptr[1], vars);
}