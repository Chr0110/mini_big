/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:46 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/08 16:04:37 by sriyani          ###   ########.fr       */
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
char **to_bar(t_b_l *big)
{
	char **bar;
	int i = 0;
	int len;
	
	t_p_l *lil;
	
	
	while(big)
	{
	 	lil = big->arg;
		len = ft_lstsize(lil);
		bar = malloc(sizeof(char *) * len + 1);
		while (lil)
		{
			bar[i] = ft_strdup(lil->content.value);
			// printf(BLUE"%s\n", bar[i]);
			i++;
			lil = lil->next;
		}
		
		big = big->next; 
	}
	// printf("%d\n",len);
	bar[i] = NULL;
	return bar;
}



void ft_pipe(t_b_l *big, t_vars *vars, int  len)
{
	int i = 0;
	pid_t child_pro;
	char **bar;
	// cmd = ft_split(ptr, '|');
	// while(cmd[++len]);
	inf(vars, len);
	while(i < len)
	{
		creat_pipe(len, i, vars);
		i++;
	}
	// close(vars->s0);
	// close(vars->s1);
	bar = to_bar(big);
	if(len == 1 && !is_builtins(big, vars, bar, len))
	{
		vars->index = 0;
		// printf("gdgfdgreg\n");
		builtins(big, vars, bar, len);
		// ft_close(len, vars);
		return ;
	}
}
// 	i = 0;
// 	while(i < len)
// 	{
// 		child_pro = fork();
// 		if(child_pro == 0)
// 		{
// 			if(dup2(vars->infile[i], STDIN_FILENO) < 0)
// 				perror("DUP1");
// 			if(dup2(vars->outfile[i] , STDOUT_FILENO) < 0)
// 				perror("DUP2");
// 			ft_close(len, vars);
// 			// if(!is_builtins(cmd[i], vars))
// 			// {
// 			// 	vars->index = i;
// 			// 	vars->infile[i] = 0;
// 			// 	vars->outfile[i] = 1;		
// 			// 	builtins(cmd[i], vars, vars->env);
// 			// 	exit(0);
// 			// }
// 			// ft_execute(cmd[i], vars);
// 			break;
			
// 		}
// 		psudo_close(vars, i);
// 		i++;
// 	}
// 	// ft_free(cmd);
// 	ft_close(len, vars);
// 	ft_wait(len);
// }



// void ft_execute(char *cmd,t_vars *vars)
// {
// 	char **cmmd;
	
// 	cmmd = ft_split(cmd, ' ');
// 	free(cmd);
// 	if(access(cmmd[0], F_OK) == 0)
// 		execve(cmmd[0], cmmd, vars->env);
// 	execve(ft_path(cmmd[0], vars->env), cmmd, vars->env);
// 	ft_free(cmmd);
// 	perror("command not found:");
// 	exit(1);
// }

// void psudo_close(t_vars *vars, int i)
// {
// 	if (vars->infile[i] != 0)
// 		close(vars->infile[i]);
// 	if (vars->outfile[i] != 1)
// 		close(vars->outfile[i]);
// }


// void ft_close(int len, t_vars *vars)
// {
// 	int k = 0;
// 	while(k < len)
// 	{
		
// 		if (vars->infile[k] != 0)
// 			close(vars->infile[k]);
// 		if (vars->outfile[k] != 1)
// 			close(vars->outfile[k]);
// 		k++;
// 	}
// }
// void ft_wait(int len)
// {
// 	int i =0;
// 	while(i < len)
// 	{	
// 		waitpid(0, 0, 0);
// 		i++;
// 	}
// }