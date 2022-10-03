/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:46 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/02 18:48:12 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int count_pipe(char *ptr)
{
	int  i = 0;
	int j = 0;
	while(ptr[i])
	{
		if(ptr[i] == '|')
			j++;
		i++;	
	}
	return j;
}



void ft_pipe(char *ptr, t_vars *vars)
{
	char **cmd;
	int count = count_pipe(ptr) * 2;
	int i = 0;
	int j = 0;
	int len = 0;
	pid_t child_pro;
	int p[count];
	int o=0;
	int k;
	char **cmmd;
	cmd = ft_split(ptr, '|');
	
	while(cmd[++len])

	while(i < count)
	{
		if(pipe(p + i) < 0)
			exit(1);
		vars->infile[i] = p[i];
		vars->outfile[i + 1] = p[i + 1];
		i+= 2;
	}
	if(len == 1 && is_builtins(ptr, vars, vars->env))
	{
		k=0;
		while(k < count)
		{
			close(p[k]);
			k++;
		}
		return ;
	}
	i = 0;
	while( i < len)
	{
		child_pro = fork();
		if(child_pro == 0)
		{
			k = 0;
			if(j != 0)
			{
				if(dup2(p[(j - 1) * 2], STDIN_FILENO) < 0)
					perror("DUP1");
			}
			if(j < len - 1)
			{
				if(dup2(p[(j * 2) + 1], STDOUT_FILENO) < 0)
					perror("DUP2");
			}
			while(k < count)
			{
				close(p[k]);
				k++;
			}
			cmmd = ft_split(cmd[i], ' ');
			if(is_builtins(ptr, vars, vars->env))
				exit(0);
			if(access(cmmd[0], F_OK) == 0)
				execve(cmmd[0], cmmd, vars->env);
			execve(ft_path(cmmd[0], vars->env), cmmd, vars->env);
			perror("error execve");
			exit(1);
			break;
		}
		i++;
		j++;
	}
	k = 0;
	while(k < count)
	{
		close(p[k]);
		k++;
	}
	while(o < len)
	{	
		waitpid(0, 0, 0);
		o++;
	}
}