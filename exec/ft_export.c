/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:50:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/03 09:11:16 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **sort_str(char **ptr)
{
	int  i=0;
	int  j=0;
	char *swap;
	
	while(ptr[i])
	{
		j = i + 1;
		while(ptr[j])
		{
			if(ft_strcmp(ptr[i],ptr[j]) < 0)
			{
				swap = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = swap;
			}
			j++;
		}
		i++;
	}
	return ptr;
}

void env_to_exp(t_vars *vars)
{
	int i = 0;
	while(vars->env[i])
	{
		vars->exp[i] = ft_strdup(vars->env[i]);
		i++;
	}
	vars->exp[i] = NULL;
}

void remove_double(char **bar, t_vars *vars)
{
	int i = 0;
	int j = 0;
	int len = 0;
	char **take = take_bar(bar,vars);
	char **test;
	while(vars->exp[++len]);
	test = take_variable(len, vars);
	while(i < len - 1)
	{
		if(ft_strcmp(test[i], test[i + 1]) == 0)
		{
			
			i++;
		}
		vars->exp[j] = vars->exp[i];
		i++;
		j++;
	}
	vars->exp[j] = vars->exp[i];
	vars->exp[j + 1] = NULL;
	// j++;
	
}

char **take_variable(int len, t_vars *vars)
{
	int i = 0;
	int j = 0;
	char **str;
	str = malloc(sizeof(char *) * 10000);
	while(i < len)
	{
		j = 0;
		str[i] = malloc(sizeof(char) * 1000);
		if(ft_strchr(vars->exp[i], '=') == 0)
		{
			while(vars->exp[i][j] != '=')
			{
				str[i][j] = vars->exp[i][j];
				j++;
			}
			str[i][j] = '\0';
		}
		else
			str[i] = ft_strdup(vars->exp[i]);
		i++;
	}
	str[i] = NULL;
	return str;
}

void aff_export2(char **bar, t_vars *vars)
{
	int i = 0;
	int  j =0;
	int len=0;
	int k = 0;
	while(vars->exp[++k]);
	while(i < k )
	{
		ft_putstr_fd("declare -x ", vars->outfile[1]);
		if(ft_strchr(vars->exp[i], '=') == 0)
		{
			j = 0;
			len = ft_strlen(vars->exp[i]) - 1;
			while(vars->exp[i][j])
			{
				if(vars->exp[i][j]== '=')
				{
					ft_putchar_fd(vars->exp[i][j], vars->outfile[1]);
					ft_putchar_fd('\"', vars->outfile[1]);
					j++;
				}
				if(j == len)
					{
						ft_putchar_fd(vars->exp[i][j], vars->outfile[1]);
						ft_putchar_fd('\"', vars->outfile[1]);
					}
				else
					{
						ft_putchar_fd(vars->exp[i][j], vars->outfile[1]);
					}
			j++;
			}
			ft_putchar_fd('\n', vars->outfile[1]);
		}
		else
			ft_putstr_fd(vars->exp[i], vars->outfile[1]);
		i++;
	}
}
void aff_export(char **bar, t_vars *vars)
{
	sort_str(vars->exp);
	aff_export2(bar,vars);
}

void add_export(char **bar, t_vars *vars)
{
	int i = 0;
	int j = 1;
	while(vars->exp[++i]);
	while(bar[j])
	{
		vars->exp[i] = ft_strdup(bar[j]);
		
		i++;
		j++;
	}
	vars->exp[i] = NULL;
	remove_double(bar, vars);
}

void check_export(char **bar, t_vars *vars)
{
	
	int i = 1;
	int j = 0;
	int k = 0;
	int  o=0;
	int l = 0;
	vars->bar= malloc(sizeof(char*)*1000);
	vars->bar[o] = "export";
	o++;
	while(bar[i])
	{
		
		if(ft_strchr(bar[i], '=') != 0)
		{
			j = 0;
			k = 0;
			while(bar[i][j])
			{
				if(ft_isalpha(bar[i][0]) == 0)
				{
					if(bar[i][0] != '_')
						k++;
						l++;
				}	
				else
				{
					if(ft_isalnum(bar[i][j]) == 0)
					{
						if(bar[i][j] != '=')
							k++;
							l++;
					}
				}
				j++;	
			}
			if(k == 0)
			{
				vars->bar[o] = ft_strdup(bar[i]);
				o++;
			}
		}
		else
		{
			j = 0;
			k = 0;
			while(bar[i][j])
			{
				if(ft_isalpha(bar[i][0]) == 0)
				{
					if(bar[i][0] != '_')
						k++;
				}
				j++;
			}
			if(k == 0)
			{
				vars->bar[o] = ft_strdup(bar[i]);
					o++;
			}
		}
		
		i++;
	}
	if(l > 0)
		ft_putstr_fd("export: not a valid identifier\n",vars->outfile[2]);

}
void check_export2(char **bar, t_vars *vars)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	
	while(bar[i++]);
	check_export(bar, vars);
	bar = vars->bar;
	char **str = malloc(sizeof(char *) * i);
	char **ptr = malloc(sizeof(char *) * i);
	i = 0;
	str[j] = bar[0];
	j++;
	while(bar[i])
	{
		if(ft_strchr(bar[i], '=') == 0)
		{
			str[j] = ft_strdup(bar[i]);
			j++;
		}
		if(ft_strchr(bar[i], '=') != 0)
		{
			ptr[k] = ft_strdup(bar[i]);
			
			k++;
		}
		i++;	
	}
	str[j] = NULL;
	ptr[k] = NULL;
	if(j > 1)
	{
		add_env(str, vars);
		remove_double(bar, vars);
		add_export(bar, vars);
	}
	if(k > 1)
	{
		remove_double(bar, vars);
		add_export(ptr, vars);
	}
}