/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:13:01 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/05 09:34:34 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_check_echo(char *str)
{
	int i  = 1;
	int j = 0;
	while(str[i])
	{
		if(str[0] == '-' && str[i] == 'n')
			j++;
		i++;		
	}
	if(j == ft_strlen(str) - 1 && j >= 1)
			return 1;
	return 2;
}

char **copie_echo(char *ptr)
{
	int i;
	char **cmd;
	i = 0;
	cmd = ft_split(ptr,' ');
	return(cmd + 1);	
}


void ft_echo(char *ptr, t_vars *vars)
{
	int i = -1;
	char **car;
	int j = 0;
	int o = 0;
	int k = 0;
	int y=0;
	char *str;

	car = copie_echo(ptr);
	while(car[++i])
		j++;
	while(o < j)
	{
		if(car[o][0] == '-')
		{
			if(ft_check_echo(car[o]) == 1 && o == y)
			{
				k++;
				y++;
			}
		}
		o++;
	 }
	 if(k > 0)
	 {
		o = k;
		while(o < j)
		{
			ft_putstr_fd(car[o], vars->outfile[vars->index]);
			if(o < j - 1)
				ft_putstr_fd(" ", vars->outfile[vars->index]);
			o++;
		}	
	}
	 i = 0;
	 if(ft_check_echo(car[i]) == 2)
	 {
		while(i < j)
		{
			ft_putstr_fd(car[i], vars->outfile[vars->index]);
			if(i < j - 1)
				ft_putstr_fd(" ", vars->outfile[vars->index]);
			if(i == j - 1)
				ft_putstr_fd("\n", vars->outfile[vars->index]);
			i++;
		}
	 }
	
}






































	// 		if(ft_check_echo(car[o]) == 2)
	// 			y++;
				
	// 	}
	// 	o++;
	// }
	// if(car[0][0] != '-' || car[0][1] == '-' )
	// {
	// 	i = 0;
	// 	while(i < j)
	// 	{
	// 		printf("%s", car[i]);
	// 		if(i < j - 1)
	// 			printf(" ");
	// 		if(i == j - 1)
	// 			printf("\n");
	// 		i++;
	// 	}
	// }
	// else if(k == 1 && car[0][0] == '-')
	// {
	// 	o = 1;
	// 	while(o < j)
	// 	{
	// 		printf("%s", car[o]);
	// 		if(o < j - 1)
	// 			printf(" ");
	// 		o++;
	// 	}
		
	// }
	// else if(y > 0 && car[0][0] == '-')
	// {
	// 	o = z - 1;
	// 	while(o < j)
	// 	{
	// 		printf("%s", car[o]);
	// 		if(o < j - 1)
	// 			printf(" ");
	// 		if(o == j - 1)
	// 			printf("\n");
	// 		o++;
	// 	}
		
	// }
	
