/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:42:29 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/01 11:43:21 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void copie_env(char **hold,int len,t_vars *vars,int index)
{
	
	int i= 0;
	while(i < len - index)
	{
		vars->env[i] = ft_strdup(hold[i]);	
		i++;
	}
	vars->env[i] = NULL;
}


void ft_unset(char **bar ,t_vars *vars)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 0;
	int index = 0;
	char **hold;
	char **take;
	int g = 0;
	char **barr;

	i = 0;
	hold = malloc(sizeof(char *) * 1000);
	check_export(bar, vars);
	bar = vars->bar;
	barr = sort_str(bar);
	while(barr[j])
	{
		i = 0;
		k = 0;
		g = 0;
		len = size_env(vars);
		take = take_variable2(len, vars);
		while(take[i])
		{
			if(ft_strcmp(take[i],barr[j]) == 0)
			{
				i++;
				g++;
			}
			if(k < len - j)
			{
				//printf(GREEN"%s\n",vars->env[i]);
				hold[k] = ft_strdup(vars->env[i]);
				k++;
			}
			if (k == len - (j))
				hold[k] = NULL;
			i++;	
		}
		if(g > 0)
		{
			copie_env(hold,len,vars,(j+1));
			// ft_free(hold);
		}
		j++;
	}

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
		}
		else
			var[i] =ft_strdup(vars->exp[i]);
		i++;
	}
	var[i] = NULL;
	return var;
}


void copie_exp(char **hold, int len, t_vars *vars, int index)
{
	
	int i= 0;
	while(i < len - index)
	{
		vars->exp[i] = ft_strdup(hold[i]);	
		i++;
	}
	vars->exp[i] = NULL;
}

void unset_exp(char **bar ,t_vars *vars)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 0;
	int index = 0;
	char **hold;
	char **take;
	int g = 0;
	char **barr;

	i = 0;
	// if(check_export(bar, vars) == 1)
	// {
		hold = malloc(sizeof(char *) * 1000);
		barr = sort_str(bar);
	
		while(barr[j])
		{
			i = 0;
			k = 0;
			g = 0;
			len = size_exp(vars);
			take = take_variable_exp(len, vars);
			while(take[i])
			{
				if(ft_strcmp(take[i], barr[j]) == 0)
				{
					i++;
					g++;
				}
				if(k < len - (j + 1))
				{
					hold[k] = ft_strdup(vars->exp[i]);
					k++;
				}
				if (k == len - (j + 1))
					hold[k] = NULL;
				i++;	
			}
			if(g > 0)
			{
				copie_exp(hold,len,vars,(j + 1));
			}
			j++;
		}
	// }

}