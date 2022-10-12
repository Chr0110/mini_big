/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:47:53 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/11 11:06:38 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



int check_rediraction(t_b_l *lil)
{
	// printf(MAG"%d\n",lil->red->content.e_type );
	while(lil)
	{
		if(lil->red && lil->red->content.e_type == 2)
			return 2;
		if(lil->red && lil->red->content.e_type == 3)
			return 3;
		if(lil->red && lil->red->content.e_type== 5)
			return 5;
		if(lil->red && lil->red->content.e_type == 4)
			return 4;
		lil = lil->next;
	}
	return 0;
}


void ft_rediraction(t_b_l *lil, t_vars *vars, int il)
{
	int i = 0;
	while(lil)
	{	
		while(lil->red)
		{
			if(lil->red->content.e_type == 2)
			{
				
				if (vars->infile[i] != -1 && vars->infile[i] != 0)
					close(vars->infile[i]);
				vars->infile[i] = open(lil->red->content.value, O_RDONLY, 0644);
				if(vars->infile[i] < 0)
					{
						ft_putstr("No such file or directory\n", 2);
					}
			}
			
			else if(lil->red->content.e_type == 3)
			{	
				
				if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
					close(vars->outfile[i]);
				vars->outfile[i] = open(lil->red->content.value, O_CREAT | O_WRONLY | O_TRUNC, 0644);
				if(vars->outfile[i] < 0)
					{
						ft_putstr("No such file or directory\n", 2);
						
					}
			}
			else if(lil->red->content.e_type == 5)
			{
				if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
					close (vars->outfile[i]);
				vars->outfile[i] = open(lil->red->content.value, O_CREAT | O_WRONLY | O_APPEND, 0644);
				if(vars->outfile[i] < 0)
					{
						ft_putstr("No such file or directory\n", 2);
					}
			}
			// if(lil->red->content.e_type == 4)
			// {
			// 	// if (vars->outfile[i] != 1 && vars->outfile[i] != -1)
			// 	// 	close (vars->outfile[vars->outfile[i]]);
			// 	vars->outfile[i] = open(lil->red->content.value, O_CREAT | O_WRONLY | O_APPEND, 0644);
			// 	if(vars->outfile[i] < 0)
			// 		ft_putstr_fd("error from appenduk , \n", 2);
			// 	dup2(vars->outfile[vars->outfile[i]], STDOUT_FILENO);
			// 	close(vars->outfile[vars->outfile[i]]);
			// 	return 0;
			// }
			lil->red = lil->red->next;
		}
		lil = lil->next;
		i++;
	}
}