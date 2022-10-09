/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:49:48 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/09 04:24:23 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_number(char **bar)
{
	int  i = 1;
	int  j = 0;
	
	while(bar[i])
	{
		j = 0;
		while(bar[i][j])
		{
			if(ft_isdigit(bar[i][j]) == 0 )
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int next_exit(char **bar,int len)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while(bar[i])
	{
		if(strcmp(bar[i], "exit")== 0)
		{
			while(bar[i + 1][j])
			{
				if(!ft_isdigit(bar[i + 1][j]))
					return 0;
				j++;
			}
		}
		i++;
	}
	return 1;
}


void	ft_exit(char **bar, t_vars *vars)
{
	int  i = 0;
	while(bar[++i]);
	if((i == 2 && check_number(bar) == 1) || i == 1)
	{
		ft_putstr("exit", 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}

	if(next_exit(bar, i) == 0)
	{
		ft_putstr("exit\nexit: ", 2);
		ft_putstr(bar[i - 1], 2);
		ft_putstr(": numeric argument required", 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	else 
		{
			ft_putstr("exit: too many arguments", 2);
			ft_putchar_fd('\n', 2);
		}
}