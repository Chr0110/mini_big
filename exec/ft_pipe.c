/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:46 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/24 15:41:18 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void kill_pro(pid_t *child_pro, int len)
{
	int i;
	i = 0;
	while (i < len)
	{
		kill(child_pro[i], SIGKILL);
		i++;
	}
}


void	ft_pipe(t_b_l *big, t_data *data, t_vars *vars, int len)
{
	int		i;
	t_b_l	*lil;

	lil = big;
	if (ft_pipe2(big, data, vars, len))
		return ;
	vars->child_pro = malloc(sizeof(int) * len);
	i = 0;
	while (lil)
	{
		if (lil->str[0])
		{	
			signal(SIGINT, SIG_IGN);
			vars->child_pro[i] = fork();
			if (vars->child_pro[i] < 0)
			{
				ft_putstr("fork: Resource temporarily unavailable\n", 2);
				kill_pro(vars->child_pro, i -1);
				break;
			}
			if (vars->child_pro[i] == 0)
			{
				body_pipe(vars, data, i, len);
				built_inside_pipe(vars, i, lil->str);
				// if (vars->mar && vars->sar)
				// {
				// 	ft_free(vars->mar);
				// 	ft_free(vars->sar);
				// }
			}
		}
		if (lil->str)
			free(lil->str);
		lil->str = NULL;
		psudo_close(vars, i);
		lil = lil->next;
		i++;
	}
	fin_pipe(vars, vars->child_pro, data, len);
}

int	ft_pipe2(t_b_l *big, t_data *data, t_vars *vars, int len)
{
	int		i;
	t_b_l	*lil;

	i = 0;
	lil = big;
	data->flag = -1;
	intial_fd(vars, len);
	while (i < len)
	{
		creat_pipe(len, i, vars);
		i++;
	}
	check_rediraction2(lil, vars, data, len);
	if (vars->sig_on == 2)
		return (1);
	if (one_built(big, vars, data, len))
		return (1);
	return (0);
}

void 	check_rediraction2(t_b_l *lil, t_vars *vars, t_data *data, int len)
{
	int	i;

	len = 0;
	i = 0;
	data->name = NULL;
	if (check_rediraction(lil))
	{
		data->name = creat_name(i);
		ft_rediraction(lil, vars, data);
	}
}

void	  built_inside_pipe(t_vars *vars, int i, char **bar)
{
	if (!is_builtins(bar))
	{	
		vars->index = i;
		vars->infile[i] = 0;
		vars->outfile[i] = 1;
		builtins(vars, bar);
		exit(0);
	}
	ft_execute(bar, vars);
}

void	ft_dup(t_vars *vars, t_data *data, int i)
{
	if (data->flag == 1)
		vars->infile[i] = data->p[0];
	if (dup2(vars->infile[i], STDIN_FILENO) < 0)
	{
		ft_putstr("dup1:\n", 2);
		exit(1);
	}
	if (dup2(vars->outfile[i], STDOUT_FILENO) < 0)
	{
		ft_putstr("dup2:\n", 2);
		exit(1);
	}
}
