/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:17:32 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/08 16:08:40 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char **new_barr(char **bar, t_vars *vars)
// {
// 	int i = 0;
// 	int j = 1;
// 	int k = 0;
// 	char  **barr;
// 	char **str = malloc(sizeof(char*)*1000);
// 	// sort_str(bar);
// 	if(bar[1] != NULL)
// 		barr = take_bar(bar,vars);
// 	while(bar[++i]);
// 	while(j < i - 1)
// 	{
// 		if(ft_strcmp(barr[j],barr[j + 1])==0)
// 			j++;
// 		str[k] = bar[j];
// 		printf("%s\n",str[k]);
// 		k++;
// 		j++;
// 	}
// 	// str[k] = bar[j];
// 	str[k + 1]= NULL;
// 	return str;
// }

// char **take_variable(int len, t_vars *vars)
// {
// 	int i = 0;
// 	int j = 0;
	
// 	vars->var = malloc(sizeof(char *) * 1000);
// 	while(i < len)
// 	{
// 		j = 0;
// 		vars->var[i] = malloc(sizeof(char)*1000);
// 		while(vars->env[i][j] != '=')
// 		{
// 			vars->var[i][j] = vars->env[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return vars->var;
// }

int check_isdouble(char  **test, int len,char *str)
{
	int i = 0;
	int j = 0;
	while(i < len - 1)
	{
		if(ft_strcmp(test[i], str) == 0)
			return 0;
		i++;	
	}
	return 1;
}

char **take_variable2(int len, t_vars *vars)
{
	int i = 0;
	int j = 0;
	char **var;
	var = malloc(sizeof(char *) * 1000);
	while(i < len)
	{
		j = 0;
		var[i] = malloc(sizeof(char) * 1000);
		while(vars->env[i][j] != '=')
		{
			var[i][j] = vars->env[i][j];
			j++;
		}
		var[i][j] = '\0';
		i++;
	}
	var[i] = NULL;
	return var;
}


void aff_env(char **ptr, t_vars *vars)
{
	int i = 0;
	while(ptr[i])
	{
		ft_putstr_fd(ptr[i], vars->outfile[vars->index]);
		ft_putchar_fd('\n', vars->outfile[vars->index]);
		i++;
	}
}

void remove_str(char **test, char *str, t_vars *vars, char *bar)
{
	int i = 0;
	int j = 0;
	int len = 0;
	while(test[++len]);
	while(i < len)
	{
		if(ft_strcmp(test[i], str) == 0)
			i++;
		vars->env[j] = vars->env[i];
		i++;
		j++;
	}
	vars->env[j] = bar;
	vars->env[j] = NULL;
}

void add_env(char **bar, t_vars *vars)
{
	int i = 0;
	int j = 1;
	int len =0;
	char **test;
	char **barr;
	while(vars->env[++i]);
	len = i;
	if(bar[1] != NULL)
		barr = take_bar(bar,vars);
	while(bar[j])
	{	
		test = take_variable2(i, vars);
		if(check_isdouble(test, len,barr[j]) == 0)
			remove_str(test, barr[j], vars, bar[j]);
		if(check_isdouble(test, len,barr[j]) == 1)
				vars->env[i] = ft_strdup(bar[j]);	
		j++;
		i++;
	}
	// ft_free(test);
	if(bar[1] != NULL)
		ft_free(barr);
}

void ft_env(char **bar,t_vars *vars)
{
	int i =0;
	int j = 0;
	int  k =0;
	
	while(bar[++j]);
	i = 0;
	while(i < j)
	{
		if(ft_strcmp(bar[i], "env") == 0 || ft_strcmp(bar[i], "ENV") == 0)
			k++;
		i++;
	}
	if(k != j)
		ft_putstr_fd("env: No such file or directory\n", 2);
	else
		add_env(bar, vars);
}

char **take_bar(char **bar, t_vars *vars)
{
	int i = 0;
	int j = 0;
	char **barr;
	barr = malloc(sizeof(char*) * 1000);
	while(bar[i])
	{
		j =  0;
		if(ft_strchr(bar[i], '=') == 0)
		{
			barr[i] = malloc(sizeof(char *) * 1000);
			while(bar[i][j] != '=')
			{
				
				barr[i][j] = bar[i][j];
				j++;
			}
			barr[i][j] = '\0';
		}
		else
			barr[i] = ft_strdup(bar[i]);
		i++;
	}
	barr[i] = NULL;
	return barr;
}

// void ft_copie(t_vars *vars)
// {
// 	int i =0;
// 	while(vars->env[i])
// 	{
// 		vars->envp[i] = ft_strdup(vars->env[i]);
// 		i++;
// 	}
// }

// void rev_copie(t_vars *vars)
// {
// 	int i = 0;
// 	while(vars->envp[i])
// 	{
// 		vars->env[i] = ft_strdup(vars->envp[i]);
// 		printf("%s      \n",vars->envp[i]);
// 		i++;
// 	}
// }







// char **check_bar(char **bar,char **barr)
// {
// 	int i = 1;
// 	int len = 0;
// 	int j =1;
// 	int k=0;
// 	char **str = malloc(sizeof(char *) * 1000);
// 	while(bar[++len]);
// 	while(j < len)
// 	{
// 		if(check_isdouble(bar, barr[j]) == 0)
// 		{
// 			printf("%s\n",str[0]);
// 			str[i] =ft_strdup(bar[j]);
// 			i++;
// 		}
// 		j++;
// 	}
	
// 	aff_env(str);
// 	return str;
// }






















// void ft_env(char **env)
// {
// 	t_env *ptr;
// 	ptr = malloc(sizeof(t_env));
// 	while(*env)
// 	{
// 		ptr->content = ft_strdup(*env);
// 		printf("%s\n",ptr->content);
// 		ptr->next = malloc(sizeof(t_env));
// 		ptr->next->next = NULL;
// 		ptr = ptr->next;
// 		env++;
// 	}
// }
