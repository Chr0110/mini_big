/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:35:49 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/28 20:27:36 by sriyani          ###   ########.fr       */
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
		if (vars->infile)
		{
			free(vars->infile);
			vars->infile = NULL;
		}
		if (vars->outfile)
		{
			free(vars->outfile);
			vars->outfile = NULL;
		}
		if (big->str)
			ft_free(big->str);
		big->str = NULL;
		return (1);
	}
	return (0);
}

void	ft_execute(char **cmd, t_vars *vars)
{
	int	i;
	DIR	*dir;

	i = 0;
	dir = opendir(cmd[0]);
	if (dir)
	{
		ft_putstr(cmd[0], 2);
		ft_putstr(": is a directory\n", 2);
		closedir(dir);
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
		closedir(dir);
	}
	closedir(dir);
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
	if (vars->infile)
	{
		free(vars->infile);
		vars->infile = NULL;
	}
	if (vars->outfile)
	{
		free(vars->outfile);
		vars->outfile = NULL;
	}
	free(vars->child_pro);
	vars->child_pro = NULL;
	init_signal();
}

void	ft_dup(t_vars *vars, t_data *data, int i)
{
	if (data->flag == 1)
		vars->infile[i] = data->p[0];
	if (dup2(vars->infile[i], STDIN_FILENO) < 0)
		exit(1);
	if (dup2(vars->outfile[i], STDOUT_FILENO) < 0)
		exit(1);
}
