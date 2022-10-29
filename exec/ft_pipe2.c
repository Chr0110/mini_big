/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:35:18 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 19:44:57 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	intial_fd(t_vars *vars, int len)
{
	int	i;

	i = 0;
	vars->infile = ft_calloc(sizeof(int), (len + 1));
	vars->outfile = ft_calloc(sizeof(int), len);
	while (i < len)
	{
		vars->infile[i] = -1;
		vars->outfile[i] = -1;
		i++;
	}
}

void	creat_pipe(int len, int i, t_vars *vars)
{
	int	p[2];

	if (i < len - 1)
		pipe(p);
	vars->infile[0] = 0;
	if (len > 1 && vars->outfile[i] == -1)
		vars->outfile[i] = p[1];
	if (len > 1 && vars->infile[i + 1] == -1)
		vars->infile[i + 1] = p[0];
	vars->outfile[len - 1] = 1;
}

void	ft_wait(pid_t *child_pro, int len)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < len)
	{
		waitpid(child_pro[i], &status, 0);
		if (WIFEXITED(status))
			g_status = WEXITSTATUS(status);
		if (status == 2)
			g_status = status + 128;
		else if (status == 3)
		{
			ft_putstr("^\\Quiet: 3\n", 2);
			g_status = status + 128;
		}
		i++;
	}
}

void	ft_close(int len, t_vars *vars, char *ptr)
{
	int	k;

	k = 0;
	while (k < len)
	{
		if (vars->infile[k] != 0)
			close(vars->infile[k]);
		if (vars->outfile[k] != 1)
			close(vars->outfile[k]);
		k++;
	}
	free(ptr);
	unlink (ptr);
}

void	psudo_close(t_vars *vars, int i)
{
	if (vars->infile[i] != 0)
		close(vars->infile[i]);
	if (vars->outfile[i] != 1)
		close(vars->outfile[i]);
}
