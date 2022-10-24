/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:35:49 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/24 08:05:47 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	one_built(t_b_l *big, t_vars *vars, t_data *data, int len)
{
	if (len == 1 && !is_builtins(big->str))
	{
		vars->index = 0;
		builtins(vars, big->str);
		ft_close(len, vars, data->name);
		if(vars->infile)
		{
			free(vars->infile);
			vars->infile = NULL;
		}
		if(vars->outfile)
		{
			free(vars->outfile);
			vars->outfile = NULL;
		}
		if (vars->mar[0] && vars->sar[0])
		{
			free(vars->mar);
			free(vars->sar);
		}
		return (1);
	}
	return (0);
}

void	ft_execute(char **cmd, t_vars *vars)
{
	int	i;

	i = 0;
	if (opendir(cmd[0]))
	{
		ft_putstr(cmd[0], 2);
		ft_putstr(": is a directory\n", 2);
		exit(126);
	}
	if (access(cmd[0], F_OK) == 0)
		execve(cmd[0], cmd, vars->env);
	if (execve(ft_path(cmd[0], vars->env), cmd, vars->env) < 0
		&& check_path(vars->env) == 0)
	{
		ft_putstr(cmd[0], 2);
		ft_putstr(": command not found\n", 2);
		exit(127);
	}
}

void	body_pipe(t_vars *vars, t_data *data, int i, int len)
{
	signal(SIGINT, SIG_DFL);
	ft_dup(vars, data, i);
	ft_close(len, vars, data->name);
}

void	fin_pipe(t_vars *vars, pid_t *child_pro, t_data *data, int len)
{
	ft_close(len, vars, data->name);
	ft_wait(child_pro, len);
	if(vars->infile)
	{
		free(vars->infile);
		vars->infile = NULL;
	}
	if(vars->outfile)
	{
		free(vars->outfile);
		vars->outfile = NULL;
	}
	free(vars->child_pro);
	vars->child_pro = NULL;
	init_signal();
}