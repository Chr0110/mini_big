/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:07:45 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/02 20:08:25 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int is_builtins(char *ptr,t_vars *vars,char **env)
{
	char **bar;
	char **exp;
	int i = 0;

	bar = ft_split(ptr, ' ');
	vars->envp = malloc(sizeof(char *)*1000);
	if(bar[0] != NULL)
	{
		if(ft_strcmp(bar[0],"pwd") == 0 || ft_strcmp(bar[0],"PWD") == 0)
			{
					ft_pwd(vars);
					return (1);
			}
		if(ft_strcmp("echo", bar[0]) == 0 || ft_strcmp("ECHO", bar[0]) == 0)
		{
			if(bar[1] ==  NULL)
				printf("\n");
			else
				ft_echo(ptr, vars);
			return (1);
		}
		if(ft_strcmp(bar[0], "cd") == 0 || ft_strcmp(bar[0], "CD") == 0)
		{
			if(bar[1] ==  NULL)
				ft_chdir("/Users/sriyani/", vars);
			else
				ft_cd(bar, vars);
			return (1);
		}
		if(ft_strcmp(bar[0], "env") == 0 || ft_strcmp(bar[0], "ENV") == 0)
		{
			ft_env(bar, vars);
			aff_env(vars->env);
			return (1);
		}
		if(ft_strcmp(bar[0], "exit") == 0)
			ft_exit(bar);
		if(ft_strcmp(bar[0], "unset") == 0)
		{
			ft_unset(bar, vars);
			unset_exp(bar, vars);
			return (1);
		}
		if(ft_strcmp(bar[0], "export") == 0)
		{
			if(bar[1] != NULL)
				check_export2(bar, vars);
			else
				aff_export(bar, vars);
			return (1);
		}		
	}
	return (0);
}
