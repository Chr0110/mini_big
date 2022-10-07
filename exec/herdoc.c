/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:30:06 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/07 17:14:54 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_multiple_heredoc(int count, int ac, char **av, char **env)
{
	int i =0;
	int j =0;
	char *str;
	char **ptr = malloc(sizeof(char**)*count);
	char*buffer;
	char **cmd;
	int len =0;
	while(i < ac - 1)
	{
		
		if(ft_strcmp(av[i], "heredoc")==0)
			{
				ptr[j] = av[i+1];
				j++;
			}
		i++;
		
	}
	ptr[j] = NULL;
	i = 0;
	j=0;
	while(i < ac)
	{
		if(ft_strcmp(av[i], "heredoc")==0)
		{
			write(1,"> ",1);
			while (1)
			{
				str = readline(buffer);
			
					if(ft_strcmp(ptr[j],str) == 0)
						j++;
					if(j == count)
					{
						if(ft_strcmp(av[1],"heredoc") == 0)
							exit(1);
						cmd = ft_split(av[1], ' ');
						execve(ft_path(cmd[0], env), cmd, env);
						perror("Error:");
						exit(1);
					}		
					 write(1,"> ",1);
			}
		}
		i++;
	}
}

// int main(int ac, char **av,char **env)
// {
// 	int i=0;
// 	int count =0;
// 	while(i < ac)
// 	{
// 		if(ft_strcmp(av[i], "heredoc")==0)
// 			count++;
// 		i++;
// 	}
// 	ft_multiple_heredoc(count, ac, av, env);
	
// }