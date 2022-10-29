/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:28:00 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 19:44:06 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirect_herd(t_data *data, t_vars *vars, char *lil2)
{
	vars->sig_on = -1;
	if (is_herdoc(lil2, vars, data) == 1)
	{
		vars->sig_on = 2;
		return (0);
	}
	return (1);
}

int	redirect_in(t_vars *vars, int i, char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (vars->infile[i] != -1 && vars->infile[i] != 0)
		close(vars->infile[i]);
	vars->infile[i] = open(str, O_RDONLY, 0644);
	if (dir)
	{
		ft_putstr(str, 2);
		ft_putstr(": Is directory\n", 2);
		closedir(dir);
		return (1);
	}
	else if (access(str, R_OK) == -1 && !(access(str, F_OK)))
	{
		ft_putstr(str, 2);
		ft_putstr(": Permission denied\n", 2);
		return (1);
	}
	else if (vars->infile[i] < 0)
	{
		ft_putstr("No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

int	redirect_out(t_vars *vars, int i, char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
		close(vars->outfile[i]);
	vars->outfile[i] = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (dir)
	{
		ft_putstr(str, 2);
		ft_putstr(": Is directory\n", 2);
		closedir(dir);
		return (1);
	}
	else if (access(str, W_OK) == -1 && !(access(str, F_OK)))
	{
		print_error_red(str);
		return (1);
	}
	else if (vars->outfile[i] < 0)
	{
		ft_putstr(str, 2);
		ft_putstr("No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

int	redirect_app(t_vars *vars, int i, char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (vars->outfile[i] != -1 && vars->outfile[i] != 1)
		close (vars->outfile[i]);
	vars->outfile[i] = open(str, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (dir)
	{
		ft_putstr(str, 2);
		ft_putstr(": Is directory\n", 2);
		closedir(dir);
		return (1);
	}
	else if (access(str, W_OK) == -1 && !(access(str, F_OK)))
	{
		print_error_red(str);
		return (1);
	}
	else if (vars->outfile[i] < 0)
	{
		ft_putstr(str, 2);
		ft_putstr("No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

void	print_error_red(char *str)
{
	ft_putstr(str, 2);
	ft_putstr(": Permission denied\n", 2);
}
