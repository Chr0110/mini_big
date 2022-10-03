/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:49:48 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/01 10:21:48 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int check_number(char **bar)
{
	int  i = 1;
	int  j=0;
	int k = 0;
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

int ft_exit(char **bar)
{
	int  i = 0;
	while(bar[++i]);
	if((i == 2 && check_number(bar) == 1) || i == 1)
	{
		printf("exit\n");
		exit(0);
	}
	else if((i == 2 && check_number(bar)  == 1))
	{
		printf("exit\n");
		exit(0);
	}
	else if(check_number(bar) == 0)
	{
		printf("exit\nexit: %s: numeric argument required\n", bar[i - 1]);
		exit(1);
	}
	else if(i > 2)
		printf("exit: too many arguments\n");
	return 0;	
}