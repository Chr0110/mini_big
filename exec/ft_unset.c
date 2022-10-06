/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:42:29 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/06 09:55:52 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// void copie_env(char **hold,int len,t_vars *vars,int index)
// {
	
// 	int i= 0;
// 	while(i < len - index)
// 	{
// 		vars->env[i] = ft_strdup(hold[i]);	
// 		i++;
// 	}
// 	vars->env[i] = NULL;
// }


void ft_unset(char **bar ,t_vars *vars)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 0;
	int index = 0;
	char **take;
	char **barr;

	i = 0;
	check_export(bar, vars);
	bar = vars->bar;
	barr = sort_str(bar);
	
	while(barr[j])
	{
		i = 0;
		k = 0;
		len = size_env(vars);
		take = take_variable2(len, vars);
		while(i < len)
		{
			if(ft_strcmp(take[i], barr[j]) == 0)
			{	free(vars->env[i]);
				i++;
			}
			vars->env[k] = vars->env[i];
			k++;
			i++;	
		}
		ft_free(take);
		vars->env[k]=  NULL;
		j++;
	}
	// ft_free(barr);
}

char **take_variable_exp(int len, t_vars *vars)
{
	int i = 0;
	int j = 0;
	char **var;
	var = malloc(sizeof(char *) * 1000);
	while(i < len)
	{
		j = 0;
		
		if(ft_strchr(vars->exp[i], '=') == 0)
		{
			var[i] = malloc(sizeof(char) * 1000);
			while(vars->exp[i][j] != '=')
			{
				var[i][j] = vars->exp[i][j];
				j++;
			}
			var[i][j] = '\0';
		}
		else
			var[i] =ft_strdup(vars->exp[i]);
		i++;
	}
	var[i] = NULL;
	return var;
}

void unset_exp(char **bar ,t_vars *vars)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 0;
	char **take;
	char **barr;

	i = 0;
	barr = sort_str(bar);
	while(barr[j])
	{
		i = 0;
		k = 0;
		len = size_exp(vars);
		take = take_variable_exp(len, vars);
		while(i < len)
		{
			if(ft_strcmp(take[i], barr[j]) == 0)
			{	
				free(vars->exp[i]);
				i++;
			}
			vars->exp[k] = vars->exp[i];
			k++;
			i++;	
		}
		ft_free(take);
		vars->exp[k]=  NULL;
		j++;
	}
	

}