/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:47:53 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/07 17:14:54 by sriyani          ###   ########.fr       */
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

// int ft_rediraction(char *ptr, t_vars *vars, t_data *data)
// {
// 	int  i = 0;
// 	int len = 0;


// 	if(data->id == 2)
// 	{
// 		vars->infile[i] = open(data->type, O_RDONLY, 0644);
// 		if(vars->infile[i] < 0)
// 			ft_putstr_fd("No such file or directory\n", 2);
// 		dup2(vars->infile[i], STDIN_FILENO);
// 		close(vars->infile[i]);
// 	}
	
// 	if(data->id == 3)
// 	{		
// 		vars->outfile[i]= open(data->type, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 		if(vars->outfile[i] < 0)
// 			ft_putstr_fd("error from output_redirect\n", 2);
// 		dup2(vars->outfile[i], STDOUT_FILENO);
// 		close(vars->outfile[i]);
// 	}
	
// 	if(data->id == 5)
// 	{
// 		// if (vars->outfile[i] != 1 && vars->outfile[i] != -1)
// 		// 	close (vars->outfile[i]);
// 		vars->outfile[i] = open(data->type, O_CREAT | O_WRONLY | O_APPEND, 0644);
// 		if(vars->outfile[i] < 0)
// 			ft_putstr_fd("error from appenduk , \n", 2);
// 		dup2(vars->outfile[i], STDOUT_FILENO);
// 		close(vars->outfile[i]);
// 	}
// 	if(data->id == 4)
// 	{
// 		// if (vars->outfile[i] != 1 && vars->outfile[i] != -1)
// 		// 	close (vars->outfile[i]);
// 		vars->outfile[i] = open(data->type, O_CREAT | O_WRONLY | O_APPEND, 0644);
// 		if(vars->outfile[i] < 0)
// 			ft_putstr_fd("error from appenduk , \n", 2);
// 		dup2(vars->outfile[i], STDOUT_FILENO);
// 		close(vars->outfile[i]);
// 	}
	
// 	return 1;
// }