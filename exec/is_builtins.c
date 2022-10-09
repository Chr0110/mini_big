/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:07:45 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/09 16:00:26 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int is_builtins(t_b_l *big, t_vars *vars, char **bar,int len)
{
	// t_p_l *lil;
	
	int i = 0;

	// if(bar[0] != NULL)
	// {
		if(ft_strcmp(bar[0],"pwd") == 0 || ft_strcmp(bar[0],"PWD") == 0
				|| ft_strcmp("echo", bar[0]) == 0 || ft_strcmp("ECHO", bar[0]) == 0
				|| ft_strcmp(bar[0], "cd") == 0 || ft_strcmp(bar[0], "CD") == 0
				|| ft_strcmp(bar[0], "env") == 0 || ft_strcmp(bar[0], "ENV") == 0
				|| ft_strcmp(bar[0], "exit") == 0
				|| ft_strcmp(bar[0], "unset") == 0
				|| ft_strcmp(bar[0], "export") == 0)
				return 0;
	// }
	return (1);
}

void	builtins(t_b_l *big, t_vars *vars, char **bar, int len)
{

	char **exp;
	t_p_l *lil;
	int i = 0;
	// bar = ft_split(ptr, ' ');
	if(ft_strcmp(bar[0],"pwd") == 0 || ft_strcmp(bar[0],"PWD") == 0)
	{
			ft_pwd(vars);
	}
	if(ft_strcmp("echo", bar[0]) == 0 || ft_strcmp("ECHO", bar[0]) == 0)
	{
		if(bar[1] ==  NULL)
			ft_putchar_fd('\n', vars->outfile[1]);
		else
			ft_echo(bar + 1, vars);
	}
	if(ft_strcmp(bar[0], "cd") == 0 || ft_strcmp(bar[0], "CD") == 0)
	{
		if(bar[1] ==  NULL)
			ft_chdir(find_user(vars), vars);
		else
			ft_cd(bar, vars);
	}
	if(ft_strcmp(bar[0], "env") == 0 || ft_strcmp(bar[0], "ENV") == 0)
	{
		ft_env(bar, vars);
	}
	if(ft_strcmp(bar[0], "exit") == 0)
		ft_exit(bar, vars);
	if(ft_strcmp(bar[0], "unset") == 0)
	{
		ft_unset(bar, vars);
		unset_exp(bar, vars);
	}
	if(ft_strcmp(bar[0], "export") == 0)
	{
		if(bar[1] != NULL)
			check_export2(bar, vars);
		else
			aff_export(bar, vars);
	}
}
