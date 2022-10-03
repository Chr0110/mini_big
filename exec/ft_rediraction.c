/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:47:53 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/02 17:55:04 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_red_in(int *fd, int len, char **cmd, char **env)
{
	int i = len - 1;
	int j = 0;
	char **comd;
	int  flag = 0;
	int flag_app = 0;
	
	while(i >= 0)
	{
		if(ft_strcmp(cmd[i], ">") == 0 && ft_strcmp(cmd[i + 1], ">") != 0)
		{
			fd[j] = open(cmd[i + 1], O_CREAT | O_TRUNC, 0644);
			if(fd[j] < 0)
			{
				perror("error");
				exit(1);
			}
		}
		if(ft_strcmp(cmd[i], ">>") == 0 && ft_strcmp(cmd[i + 1], ">>") != 0)
		{
			fd[j] = open(cmd[i + 1], O_CREAT, 0666);
			if(fd[j] < 0)
			{
				perror("error");
				exit(1);
			}
		}
		i--;
		j++;
	}
	i = len - 1;
	while(i >= 0)
	{			
				
		if(ft_strcmp(cmd[i], ">") == 0 && ft_strcmp(cmd[i + 1], ">") != 0)
		{
				
			if( i <= len - 1)
			{
				printf("%s\n",cmd[i]);
				fd[j] = open(cmd[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
				if(fd[j] < 0)
					perror("error");
				dup2(fd[j], STDOUT_FILENO);
				//close(fd[j]);
				// comd = ft_split(cmd[0], ' ');
				// execve(ft_path(comd[0], env), comd, env);
				// perror("error execve");
				// exit(1);
			}
		}
		if(ft_strcmp(cmd[i], ">>") == 0 && ft_strcmp(cmd[i + 1], ">>") != 0)
		{
			fd[j] = open(cmd[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
			if(fd[j] < 0)
				perror("error");
			dup2(fd[j], STDOUT_FILENO);
			//close(fd[j]);
			// comd = ft_split(cmd[0], ' ');
			// if(access(cmd[0], F_OK) == 0)
			// 	execve(cmd[0], comd, env);
			// else
			// {
			// 	execve(ft_path(comd[0], env), comd, env);
			// 	perror("error execve");
			// 	exit(1);
			// }
		}
		i--;
		j++;
	}
}

void	ft_red_out(int *fd, int len, char ** cmd, char **env)
{
	int  i = len - 1;
	char **comd;
	int j=0;
	int flag = 0;
	
	while(i >= 0)
	{
		if(ft_strcmp(cmd[i], ">") == 0)
		{
			fd[j] = open(cmd[i + 1], O_CREAT | O_WRONLY ,0644);
			if(fd[j] < 0)
			{
				perror("error fd out");
				exit(1);
			}
		}
		if(ft_strcmp(cmd[i], "<") == 0)
		{
			
			fd[j] = open(cmd[i + 1], O_RDONLY, 0644);
			if(fd[j] < 0)
			{
				perror("error fd out");
				//exit(1);
			}
			
			if(flag > 0)
			{
				dup2(fd[j], STDIN_FILENO);
				//close(fd[j]);
			}
			dup2(fd[j], STDIN_FILENO);
			//close(fd[j]);
			// comd = ft_split(cmd[0], ' ');
			// execve(ft_path(comd[0], env), comd, env);
			// perror("error execve");
			// exit(1);
		}
		i--;
		j++;
	}
}

void ft_rediraction(char *ptr, char **env)
{
	int  i = 0;
	int len = 0;
	int count_in = 0;
	int count_out = 0;
	int *fd;
	int count =0;
	char **cmd = ft_split(ptr, ' ');
	while(cmd[++len]);
	while(i < len)
	{
		if(ft_strcmp(cmd[i], ">") == 0 || ft_strcmp(cmd[i], ">>") == 0)
			count_in++;
		if(ft_strcmp(cmd[i], "<") == 0)
			count_out++;
		i++;
	}
	
	fd = malloc(sizeof(int *) * count + 1);
	i = 0;
	while(i < len)
	{
		if((ft_strcmp(cmd[i], ">") == 0 && ft_strcmp(cmd[i + 1],">")== 0) || ft_strcmp(cmd[len - 1], ">") == 0)
		{
			printf(" syntax error near unexpected token `>'\n");
			exit(1);
		}
		if((ft_strcmp(cmd[i], ">>")==0 && ft_strcmp(cmd[i + 1], ">>")==0) || ft_strcmp(cmd[len - 1], ">>")== 0)
		{
			printf(" syntax error near unexpected token `>'\n");
			exit(1);
		}
		if(ft_strcmp(cmd[len -1], "<")== 0)
		{
			printf(" syntax error near unexpected token `>'\n");
			exit(1);
		}
		i++;
	}
	if(count_in >= 1)
		ft_red_in(fd, len, cmd, env);
	if(count_out >= 1)
		ft_red_out(fd, len, cmd, env);
}