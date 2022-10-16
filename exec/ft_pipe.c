/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:46 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/15 22:51:12 by eradi-           ###   ########.fr       */
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
	// printf(CYAN"p[0] = %d\n", p[0]);
	// printf(CYAN"p[1] = %d\n", p[1]);
	
	vars->infile[0] = 0;
	
	if (i < len - 1)
	{
		if (vars->outfile[i] == -1)
			vars->outfile[i] = p[1];
	}
	if (vars->infile[i + 1] == -1)
		vars->infile[i + 1] = p[0];
		
	vars->outfile[len - 1] = 1;
	// printf(MAG"vars->infile[%d] = %d\n", i, vars->infile[i]);
	// printf(MAG"vars->outfile[%d] = %d\n", i, vars->outfile[i]);
	// vars->s0 = p[0];
	// vars->s1 = p[1];
	
}

void ft_pipe(t_b_l *big, t_vars *vars, int  len)
{
	int i = 0;
	pid_t child_pro;
	t_b_l *lil = big;
	t_b_l *lil2 = big;
	
	inf(vars, len);
	while(i < len)
	{
		creat_pipe(len, i, vars);
		i++;
	}
	// close(vars->s0);
	// close(vars->s1);
	if(check_rediraction(lil2))
		ft_rediraction(lil2, vars, i);
		
	if(len == 1 && !is_builtins(vars, big->str))
	{
		vars->index = 0;
		builtins(vars, big->str);
		ft_close(len, vars);
		return ;
	}
	
	i = 0;
	
	while(lil)
	{
		
		if (lil->str[0])
		{
			signal(SIGINT, SIG_IGN);
			child_pro = fork();
			
			if(child_pro == 0)
			{
				
				signal(SIGINT, SIG_DFL);
				if(dup2(vars->infile[i], STDIN_FILENO) < 0)
					ft_putstr("dup1:\n", 2);
				if(dup2(vars->outfile[i] , STDOUT_FILENO) < 0)
					ft_putstr("dup2:\n", 2);
				ft_close(len, vars);
				if(!is_builtins(vars, lil->str))
				{	
					vars->index = i;
					vars->infile[i] = 0;
					vars->outfile[i] = 1;		
					builtins(vars, lil->str);
					exit(0);
				}
				ft_execute(lil->str, vars);
			}
		}	
		psudo_close(vars, i);
		lil = lil->next;
		i++;
	}
	
	ft_close(len, vars);
	ft_wait(child_pro,len);
	init_signal();
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

void ft_wait(pid_t child_pro, int len)
{
	int i = 0;
	int *status;
	status = malloc(sizeof(int) + 2);
	while(i < len)
	{	
		waitpid(child_pro, status, 0);
		//printf()
		if(status[i] == 3)
			ft_putstr("^\\Quiet: 3\n", 2);
		i++;
	}
}