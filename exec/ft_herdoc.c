/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:25:41 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/18 07:15:10 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
char *creat_name(void)
{
	int i = 0;
	static int k;
	int j= 0;
	char *str;
	char *ptr;
	ptr = malloc(sizeof(char) * 6);
	str = "abcdefghijklmnopqrstuvwxyz0123456789";
	while(j < 5)
	{
		if(i % 2 == 0)
			ptr[j] = str[i];
		if((i+k) >= 37)
			k = 0;
		j++;
		i=+k;
		k++;
	}
	ptr[j] = '\0';
	return ptr;
}

char *ft_expand(t_vars *vars,char *ptr)
{
	int	i;
	int	j;
	int	k;
	char *str = NULL;
	 i = 0;
	 j = 0;
	k = 0;
	 while(vars->env[i])
	 {
		if(ft_strncmp(vars->env[i], ptr + 1, ft_strlen(ptr + 1)) == 0)
		{
			while(vars->env[i][j] != '=')
				j++;
			str = ft_strdup(vars->env[i] + j);
			while(vars->env[i][++j])
			{
				str[k] = vars->env[i][j];
				
				k++;
			}
			str[k] = '\0';
			break;
		}
		i++;
	}
	free(ptr);
	return str;
}
void sig_han(int signum)
{
	if(signum == SIGINT)
	{
		exit(2);
	}
}

void ft_herdoc(t_vars *vars, t_b_l *lil, char *dil, t_data *data)
{
	char *str;
	char *buffer;
	char *tmp;
	char *expand;
	int i = 0;
	data->har = ft_strdup("");
	
	while(1)
	{
		str = readline("> ");
		if(!str || ft_strcmp(str, dil) == 0)
		{
			data->p[1] = open(data->name, O_TRUNC | O_WRONLY | O_CREAT ,0644);
			ft_putstr(data->har, data->p[1]);
			close(data->p[1]);
			// data->p[0] = open(ptr, O_RDONLY, 0644);
			// unlink(ptr);
			exit(0);
		}
		
		if(str)
		{
			tmp = data->har;
			if(ft_strchr(str, '$') == 0)
				str = ft_expand(vars, str);
			data->har = ft_strjoin(data->har, str);
			free(tmp);
			tmp = data->har;
			data->har = ft_strjoin(data->har, "\n");
			free(tmp);
		}
		free(str);
	}
	
}