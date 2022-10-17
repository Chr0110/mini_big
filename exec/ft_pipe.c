/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:46 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/17 11:59:44 by sriyani          ###   ########.fr       */
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
	pid_t child_pro[len];
	t_b_l *lil = big;
	t_b_l *lil2 = big;
	t_b_l *lil3 = big;
	t_data *data;
	char	*ptr;
	
	data = malloc(sizeof(t_data));
	data->count = 0;
	data->flag = -1;
	ptr = NULL;
	// if(check_herdoc(lil))
	// 	is_herdoc(lil, vars, data, len);
	inf(vars, len);
	while(i < len)
	{
		creat_pipe(len, i, vars);
		i++;
	}
	i = 0;	

	// close(vars->s0);
	// close(vars->s1);
	vars->sig_on = -1;
	if(check_rediraction(lil))
	{
		ptr = creat_name();
		ft_rediraction(lil, vars, len, data, ptr);
	}
	if (vars->sig_on == 2)
		return ;
	// printf("%d  %d \n",data->p[0],data->p[1]);
	if(len == 1 && !is_builtins(vars, big->str))
	{
		vars->index = 0;
		builtins(vars, big->str);
		ft_close(len, vars, ptr);
		return ;
	}
	i = 0;
	while(lil)
	{ 
		if (lil->str[0])
		{
			signal(SIGINT, SIG_IGN);
			child_pro[i] = fork();
			if(child_pro[i] == 0)
			{
				signal(SIGINT, SIG_DFL);
				printf ("data->flag = |%d|\tdata->p[0] = |%d|\n", data->flag, data->p[0]);
				if (data->flag == 1)
				{
					vars->infile[i] = data->p[0];
					
				}
				if(dup2(vars->infile[i], STDIN_FILENO) < 0)
				{
					ft_putstr("dup1:\n", 2);
					exit(0);
				}
				if(dup2(vars->outfile[i] , STDOUT_FILENO) < 0)
				{
					ft_putstr("dup2:\n", 2);
					
					exit(0);
				}
				if(!is_builtins(vars, lil->str))
				{	
					vars->index = i;
					vars->infile[i] = 0;
					vars->outfile[i] = 1;		
					builtins(vars, lil->str);
					exit(0);
				}
				ft_execute(lil->str, vars);
				ft_close(len, vars, ptr);
			}
		}
		psudo_close(vars, i);
		lil = lil->next;
		i++;
	}
	ft_close(len, vars, ptr);
	ft_wait(child_pro, len);
	init_signal();
	free (ptr);
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


void ft_close(int len, t_vars *vars, char *ptr)
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
	unlink (ptr);
}

void ft_wait(pid_t *child_pro, int len)
{
	int i = 0;
	int *status;
	status = malloc(sizeof(int) * len + 2);
	while(i < len)
	{	
		waitpid(child_pro[i], status, 0);
		if(status[i] == 3)
			ft_putstr("^\\Quiet: 3\n", 2);
		i++;
	}
}