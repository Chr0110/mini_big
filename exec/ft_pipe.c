/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:46 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/09 21:16:37 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// int count_pipe(char *ptr)

void	inf(t_vars *vars, int len)
{
	int i = 0;
	while (i < len)
	{
		vars->infile[i] = -1;
		vars->outfile[i] = -1;
		// printf("vars->infile[%d] = %d\n", i, vars->infile[i]);
		// printf("vars->outfile[%d] = %d\n", i, vars->outfile[i]);
		i++;
	}
}
void creat_pipe(int len, int i, t_vars *vars)
{
	int p[2];
	
	if (i < len - 1)
		pipe(p);
	// printf("p[0] = %d\n", p[0]);
	// printf("p[1] = %d\n", p[1]);
	vars->infile[0] = 0;
		
	if (vars->outfile[i] == -1)
		vars->outfile[i] = p[1];
	if (vars->infile[i + 1] == -1)
		vars->infile[i + 1] = p[0];
		
	vars->outfile[len - 1] = 1;
	// printf("vars->infile[%d] = %d\n", i, vars->infile[i]);
	// printf("vars->outfile[%d] = %d\n", i, vars->outfile[i]);
	// vars->s0 = p[0];
	// vars->s1 = p[1];
	
}

void ft_pipe(t_b_l *big, t_vars *vars, int  len)
{
	int i = 0;
	pid_t child_pro;
	t_b_l *lil = big;
	t_b_l *lil2 = big;
	// t_b_l *lil3 = big;
	inf(vars, len);
	while(i < len)
	{
		creat_pipe(len, i, vars);
		i++;
	}
	i = 0;	

	// close(vars->s0);
	// close(vars->s1);

	if(len == 1 && !is_builtins(big, vars, big->str, len))
	{
		vars->index = 0;
		builtins(big, vars, big->str, len);
		if(check_rediraction(lil2))
			ft_rediraction(lil2, vars, i);
		ft_close(len, vars);
		return ;
	}
	
	i = 0;
	while(lil)
	{
		child_pro = fork();
		if(child_pro == 0)
		{
			if(dup2(vars->infile[i], STDIN_FILENO) < 0)
				ft_putstr("dup1:\n", 2);
			if(dup2(vars->outfile[i] , STDOUT_FILENO) < 0)
				ft_putstr("dup2:\n", 2);
			ft_close(len, vars);
			if(!is_builtins(big, vars, lil->str, len))
			{
				vars->index = i;
				vars->infile[i] = 0;
				vars->outfile[i] = 1;		
				builtins(big, vars,lil->str, len);
				exit(0);
			}
			if(check_rediraction(lil2))
				ft_rediraction(lil2, vars, i);
			ft_execute(lil->str, vars);
		}
		psudo_close(vars, i);
		lil = lil->next;
		i++;
	}
	ft_close(len, vars);
	ft_wait(len);
}


void ft_execute(char **cmd, t_vars *vars)
{
	int	i;
	
	i = 0;
	if(access(cmd[0], F_OK) == 0)
		execve(cmd[0], cmd, vars->env);
	if (execve(ft_path(cmd[0], vars->env), cmd, vars->env) < 0 && check_path(vars->env) == 0)
	{
		ft_putstr(cmd[0], 2);
		ft_putstr(":command not found:\n", 2);
		exit(1);
	}
}

void psudo_close(t_vars *vars, int i)
{
	if (vars->infile[i] != 0)
		close(vars->infile[i]);
	if (vars->outfile[i] != 1)
		close(vars->outfile[i]);
}


void ft_close(int len, t_vars *vars)
{
	int k = 0;
	while(k < len)
	{
		if (vars->infile[k] != 0)
			close(vars->infile[k]);
		if (vars->outfile[k] != 1)
			close(vars->outfile[k]);
		k++;
	}
}

void ft_wait(int len)
{
	int i =0;
	while(i < len)
	{	
		waitpid(0, 0, 0);
		i++;
	}
}