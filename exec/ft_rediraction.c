/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:47:53 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/18 18:01:56 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_herdoc(t_b_l * lil)
{
	while (lil)
	{
		if(lil->red && lil->red->content.e_type == 4)
			return 4;
		lil = lil->next;
	}
	return 0;
}


int is_herdoc(t_b_l *lil, t_vars *vars, t_data *data, int len)
{
	t_b_l *lil2;
	pid_t	child;
	char *str;
	int status;
	lil2 = lil;
	data->flag = 1;
	signal(SIGINT, SIG_IGN);
	child = fork();
	if(child == 0)
	{	
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_han);
		while(lil2)
		{
			while(lil2->red)
			{	
				if(lil2->red->content.e_type == 4)
				{
					str = lil2->red->content.value;
					ft_herdoc(vars,lil, str, data);
				}
				lil2->red = lil2->red->next;
			}			
			lil2 = lil2->next;
		}
	}
	else
	{
		waitpid(child, &status, 0);
		data->p[0] = open(data->name, O_RDONLY, 0644);
		if (vars->sig_on == -1 || vars->sig_on == 0)
			return 0;
	}
	return 1;
}

int check_rediraction(t_b_l *lil)
{
	while(lil)
	{ 
		while(lil->red)
		{
			if(lil->red && lil->red->content.e_type == 2)
				return 2;
			if(lil->red && lil->red->content.e_type == 3)
				return 3;
			if(lil->red && lil->red->content.e_type== 5)
				return 5;
			if(lil->red && lil->red->content.e_type == 4)
				return 4;
			lil->red = lil->red->next;
		}	
	
		lil = lil->next;
	}
	return 0;
}


void ft_rediraction(t_b_l *lil, t_vars *vars, int len, t_data * data)
{
	int i = 0;
	t_b_l*lil2;
	lil2 = lil;
	vars->sig_on = 0;
	while(lil)
	{	
		while(lil->red)
		{
			if(lil->red->content.e_type == 4 )
			{
				// printf(CYAN"fFdgfgff\n ");
				// ft_herdoc(vars,lil, data->name, data);
				data->p[0] = -1;
				data->p[1] = -1;
				if (is_herdoc(lil2, vars, data, len) == 1)
					vars->sig_on = 2;
			}
			if(lil->red->content.e_type == 2)
			{
				
				if (vars->infile[i] != -1 && vars->infile[i] != 0)
					close(vars->infile[i]);
				vars->infile[i] = open(lil->red->content.value, O_RDONLY, 0644);
				if(opendir(lil->red->content.value))
				{
					ft_putstr(lil->red->content.value, 2);
					ft_putstr(": Is directory\n", 2);
				}
				else if(vars->infile[i] < 0)
				{
					ft_putstr("No such file or directory\n", 2);
				}
				else if(access(lil->red->content.value, R_OK) == -1)
				{
					ft_putstr(lil->red->content.value, 2);
					ft_putstr(": Permission denied\n", 2);
				}
			}
			
			if(lil->red->content.e_type == 3)
			{	
				
				if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
					close(vars->outfile[i]);
				vars->outfile[i] = open(lil->red->content.value, O_CREAT | O_WRONLY | O_TRUNC, 0644);
				if(opendir(lil->red->content.value))
				{
					ft_putstr(lil->red->content.value, 2);
					ft_putstr(": Is directory\n", 2);
				}
				else if(vars->outfile[i] < 0)
				{
					ft_putstr("No such file or directory\n", 2);
					
				}
				else if(access(lil->red->content.value, W_OK) == -1 )
				{
					ft_putstr(lil->red->content.value, 2);
					ft_putstr(": Permission denied\n", 2);
				}
		
			}
			if(lil->red->content.e_type == 5)
			{
				if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
					close (vars->outfile[i]);
				vars->outfile[i] = open(lil->red->content.value, O_CREAT | O_WRONLY | O_APPEND, 0644);
				if(opendir(lil->red->content.value))
				{
					ft_putstr(lil->red->content.value, 2);
					ft_putstr(": Is directory\n", 2);
				}
				else if(vars->outfile[i] < 0)
				{
					ft_putstr("No such file or directory\n", 2);
				}
				else if(access(lil->red->content.value, W_OK) == -1 )
				{
					ft_putstr(lil->red->content.value, 2);
					ft_putstr(": Permission denied\n", 2);
				}
			}
			lil->red = lil->red->next;
		}
		lil = lil->next;
		i++;
	}
}