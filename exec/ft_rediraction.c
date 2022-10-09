/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:47:53 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/09 21:16:46 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	ft_red_out(int len,t_vars *vars)
// {
// 	int i = len - 1;
// 	int j = 0;
	
// 	while(i >= 0)
// 	{					
// 		if(ft_strcmp(vars->cmd[i], ">") == 0 && ft_strcmp(vars->cmd[i + 1], ">") != 0)
// 		{		
// 			vars->outfile[i]= open(vars->cmd[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 			if(vars->outfile[i] < 0)
// 				perror("error");
// 			dup2(vars->outfile[i], STDOUT_FILENO);
// 			close(vars->outfile[i]);
// 		}
// 		if(ft_strcmp(vars->cmd[i], ">>") == 0 && ft_strcmp(vars->cmd[i + 1], ">>") != 0)
// 		{
// 			// if (vars->outfile[i] != 1 && vars->outfile[i] != -1)
// 			// 	close (vars->outfile[i]);
// 			vars->outfile[i] = open(vars->cmd[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
// 			if(vars->outfile[i] < 0)
// 				perror("error");
// 			dup2(vars->outfile[i], STDOUT_FILENO);
// 			close(vars->outfile[i]);
// 		}
// 		i--;
// 		j++;
// 	}
// }

// void	ft_red_in(int len, t_vars *vars)
// {
// 	int  i = len - 1;
// 	int j = 0;
// 	while(i >= 0)
// 	{
// 		if(ft_strcmp(vars->cmd[i], "<") == 0)
// 		{
			
// 			vars->infile[i] = open(vars->cmd[i + 1], O_RDONLY, 0644);
// 			if(vars->infile[i] < 0)
// 			{
// 				perror("error fd out");
// 				exit(1);
// 			}  
// 			dup2(vars->infile[i], STDIN_FILENO);
// 			close(vars->infile[i]);
// 		}
// 		i--;
// 		j++;
// 	}
// }

int check_rediraction(t_b_l *lil)
{
	
	//  = -1;
		
	if( lil->red->content.e_type == 2)
		return 2;
	if( lil->red->content.e_type == 3)
		return 3;
	if(lil->red->content.e_type== 5)
		return 5;
	if(lil->red->content.e_type == 4)
		return 4;
	return 0;	
}


int ft_rediraction(t_b_l *lil,t_vars *vars,int  i)
{
	int len = 0;
	
	if(lil->red->content.e_type == 2)
	{
		if (vars->infile[i] != -1 && vars->infile[i] != 0)
			close(vars->infile[i]);
		vars->infile[i] = open(lil->red->content.value, O_RDONLY, 0644);
		if(vars->infile[i] < 0)
			ft_putstr_fd("No such file or directory\n", 2);
		// dup2(vars->infile[i], STDIN_FILENO);
		// close(vars->infile[i]);
		return 0;
	}
	if(lil->red->content.e_type == 3)
	{	
		if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
			close(vars->outfile[i]);
		vars->outfile[i]= open(lil->red->content.value, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if(vars->outfile[i] < 0)
			ft_putstr_fd("error from output_redirect\n", 2);
		// dup2(vars->outfile[i], STDOUT_FILENO);
		// close(vars->outfile[i]);
		return 0;
	}
	if(lil->red->content.e_type == 5)
	{
		
		if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
			close (vars->outfile[i]);
		vars->outfile[i] = open(lil->red->content.value, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if(vars->outfile[i] < 0)
			ft_putstr_fd("error from appenduk , \n", 2);
		// dup2(vars->outfile[i], STDOUT_FILENO);
		// close(vars->outfile[i]);
		return 0;
	}
	// if(lil->red->content.e_type == 4)
	// {
	// 	// if (vars->outfile[i] != 1 && vars->outfile[i] != -1)
	// 	// 	close (vars->outfile[i]);
	// 	vars->outfile[i] = open(lil->red->content.value, O_CREAT | O_WRONLY | O_APPEND, 0644);
	// 	if(vars->outfile[i] < 0)
	// 		ft_putstr_fd("error from appenduk , \n", 2);
	// 	dup2(vars->outfile[i], STDOUT_FILENO);
	// 	close(vars->outfile[i]);
	// 	return 0;
	// }
	// 
	return 1;
}