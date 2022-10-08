/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:13:01 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/08 18:00:58 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

// char *copie_echo(char *ptr)
// {
// 	int i;
// 	int len;
// 	char *cmd;
// 	i = 0;
// 	len = ft_strlen(ptr);
// 	cmd = ft_strdup("");
// 	while(i < len - 2)
// 	{
// 		cmd[i] = ptr[i];
// 		i++;
// 	}
// 	cmd[i] = '\0';
// 	return(cmd);	
// }


void ft_echo(char **bar, t_vars *vars)
{
	int i = -1;
	// char **bar;
	int j = 0;
	int o = 0;
	int k = 0;
	int y = 0;
	char *str;

	// bar = copie_echo(ptr);
	while(bar[++i])
		j++;
	while(o < j)
	{
		if(bar[o][0] == '-')
		{
			if(ft_check_echo(bar[o]) == 1 && o == y)
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
			
			ft_putstr(bar[o], vars->outfile[vars->index]);
			if(o < j - 1)
				ft_putstr(" ", vars->outfile[vars->index]);
			o++;
		}	
	}
	 i = 0;
	 if(ft_check_echo(bar[i]) == 2)
	 {
		while(i < j)
		{
			ft_putstr(bar[i], vars->outfile[vars->index]);
			if(i < j - 1)
				ft_putstr(" ", vars->outfile[vars->index]);
			if(i == j - 1)
				ft_putchar_fd('\n', vars->outfile[vars->index]);
			i++;
		}
	 }
	
}






































	// 		if(ft_check_echo(bar[o]) == 2)
	// 			y++;
				
	// 	}
	// 	o++;
	// }
	// if(bar[0][0] != '-' || bar[0][1] == '-' )
	// {
	// 	i = 0;
	// 	while(i < j)
	// 	{
	// 		printf("%s", bar[i]);
	// 		if(i < j - 1)
	// 			printf(" ");
	// 		if(i == j - 1)
	// 			printf("\n");
	// 		i++;
	// 	}
	// }
	// else if(k == 1 && bar[0][0] == '-')
	// {
	// 	o = 1;
	// 	while(o < j)
	// 	{
	// 		printf("%s", bar[o]);
	// 		if(o < j - 1)
	// 			printf(" ");
	// 		o++;
	// 	}
		
	// }
	// else if(y > 0 && bar[0][0] == '-')
	// {
	// 	o = z - 1;
	// 	while(o < j)
	// 	{
	// 		printf("%s", bar[o]);
	// 		if(o < j - 1)
	// 			printf(" ");
	// 		if(o == j - 1)
	// 			printf("\n");
	// 		o++;
	// 	}
		
	// }
	
