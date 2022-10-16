/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:16 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/16 09:59:55 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



void ft_initial_exec(t_vars *vars, char **env)
{
	vars->pwd = ft_strdup("");
	vars->infile = malloc(sizeof(int) * 100);
	vars->outfile = malloc(sizeof(int) * 100);
	initial_env(vars, env);
	initial_exp(vars, env);
	ft_replace_shlvl(vars);
	ft_replace_oldpwd(vars);
	env_to_exp(vars);
	ft_replace(vars);
	ft_append(vars);
}

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
	vars->exp[i] = NULL;
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
	int  len;
	int size;
	char *pwd;
	pwd = ft_getcwd(vars);
	
	j = 0 ;
	i = 0;
	len = 35;
 	len = size_env(vars);
	while(i < len)
	{
		if(ft_strncmp(vars->env[i], "PWD=", 4) == 0 )
		{
			// free(vars->env[i]);
			vars->env[i] = ft_strjoin("PWD=", pwd);
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
	// free(vars->pwd);
	vars->pwd = pwd;
}

void ft_replace_shlvl(t_vars *vars)
{
	int i;
	int len;
	int a;
	char *str;
	char *n;
	i = 0;
	len = size_env(vars);
	while(i < len)
	{
		if(ft_strncmp(vars->env[i], "SHLVL", 5) == 0)
		{
			str = ft_copie_shlvl(vars->env[i]);
			// free(vars->env[i]);
			a = atoi(str) + 1;
			n = ft_itoa(a);
			vars->env[i] = ft_strjoin("SHLVL=", n);
			// free(n);
			// free(str);
		}
		i++;
	}
	// vars->env[i] = NULL;
	env_to_exp(vars);
}
char *ft_copie_shlvl(char *str)
{
	int i;
	int j;
	char *ptr;
	int len;
	
	i = 0;
	j = 0;
	len = ft_strlen(str);
	while(str[i] != '=')
		i++;
	ptr = malloc(sizeof(char)*(len - i + 1));
	while(str[++i])
	{
		ptr[j] = str[i];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
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
		{
			// free(vars->env[i]);
			i++;
		}
		vars->env[j] = vars->env[i];
		j++;
		i++;
	}
	vars->env[j] = NULL;
}

void ft_append(t_vars *vars)
{
	int  i;
	char *pwd;
	
	i  = 0;
	pwd = ft_strdup("OLDPWD");
	while(vars->exp[i])
		i++;
	vars->exp[i] = pwd;
	vars->exp[i + 1] = NULL;
}