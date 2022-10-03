/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:16 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/02 14:07:37 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void initial_env(t_vars *vars, char **env)
{

	int i = 0;
	vars->env = malloc(sizeof(char *) * 1000);
	while(env[i])
	{
		vars->env[i] = ft_strdup(env[i]);
		i++;
	}
	vars->env[i] = NULL;
}

void initial_exp(t_vars *vars, char **env)
{
	int  i = 0;
	vars->exp = malloc(sizeof(char *)*1000);
	while(env[i])
	{
		vars->exp[i] = ft_strdup(env[i]);
		i++;
	}
}

int size_env(t_vars *vars)
{
	int len;
	
	len = 0;
	while(vars->env[++len]);
	return (len);
}

int size_exp(t_vars *vars)
{
	int len;
	
	len = 0;
	while(vars->exp[++len]);
	return (len);
}
char **ft_remove(char **str, char *ptr, int len)
{
	int  i = 0;
	int  j = 0;
	while(i < len)
	{
		if(ft_strcmp(str[i], ptr) == 0)
			i++;
		str[j] = str[i];
		i++;
		j++;
	}
	return str;
}

void ft_replace(t_vars *vars)
{
	int  i;
	int  j;
	int a;
	int  len;
	int size;
	char **str;
	char *pwd;
	
	j = 0 ;
	i = 0;
	
 	len = size_env(vars);
	while(i < len)
	{
		if(ft_strncmp(vars->env[i], "PWD=", 4) == 0 )
		{
			vars->env[i] = ft_strjoin("PWD=", getcwd(NULL, 0));
		}
		i++;
	}
	vars->env[i] = NULL;
	if(ft_strcmp(vars->pwd, "\0") != 0)	
	{
		len = size_env(vars);
		vars->env[--len] = ft_strjoin("OLDPWD=", vars->pwd);
	}
	env_to_exp(vars);
	size = size_exp(vars);
	vars->pwd = getcwd(NULL, 0);
	
}

void ft_replace_shlvl(t_vars *vars)
{
	int i;
	int  len;
	int a;
	char **str;
	i = 0;
	len = size_env(vars);
	while(i < len)
	{
		if(ft_strncmp(vars->env[i], "SHLVL", 5) == 0)
		{
			str = ft_split(vars->env[i], '=');
			a = atoi(str[1]) + 1;
			vars->env[i] = ft_strjoin("SHLVL=",ft_itoa(a));
		}
		i++;
	}
	env_to_exp(vars);
	vars->env[i] = NULL;
}

void ft_replace_oldpwd(t_vars *vars)
{
	int i;
	int j;
	int len;
	len = size_env(vars);
	i = 0;
	j = 0;
	
	while (i < len)
	{
		if (ft_strncmp(vars->env[i], "OLDPWD", 6) == 0)
			i++;
		vars->env[j] = vars->env[i];
		j++;
		i++;
	}
	vars->env[j]= NULL;
}

void ft_append(t_vars *vars)
{
	int  i = 0;
	while(vars->exp[i])
		i++;
	vars->exp[i] = ft_strdup("OLDPWD");
	vars->exp[i+1] = NULL;
}