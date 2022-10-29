/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:47:53 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 19:46:48 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_herdoc(t_b_l *lil)
{
	while (lil)
	{
		if (lil->red && lil->red->content.e_type == 4)
			return (4);
		lil = lil->next;
	}
	return (0);
}

int	is_herdoc(char *lil, t_vars *vars, t_data *data)
{
	pid_t	child;
	int		*status;

	status = NULL;
	data->flag = 1;
	signal(SIGINT, SIG_IGN);
	child = fork();
	if (child == 0)
	{	
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_han);
		ft_herdoc(vars, lil, data);
	}
	else
	{
		waitpid(child, status, 0);
		data->p[0] = open(data->name, O_RDONLY, 0644);
		if (vars->sig_on == -1 || vars->sig_on == 0)
			return (0);
	}
	return (1);
}

int	check_rediraction(t_b_l *lil)
{
	t_r	*tmp;

	while (lil)
	{
		tmp = lil->red;
		while (tmp)
		{
			if (tmp && tmp->content.e_type == 2)
				return (2);
			if (tmp && tmp->content.e_type == 3)
				return (3);
			if (tmp && tmp->content.e_type == 5)
				return (5);
			if (tmp && tmp->content.e_type == 4)
				return (4);
			tmp = tmp->next;
		}	
		lil = lil->next;
	}
	return (0);
}

int	ft_rediraction(t_b_l *lil, t_vars *vars, t_data *data)
{
	int		i;
	t_b_l	*lil2;
	t_r		*ril;

	lil2 = lil;
	i = 0;
	while (lil)
	{	
		ril = lil->red;
		while (ril)
		{
			if (ril->content.e_type == 4)
				g_status = redirect_herd(data, vars, ril->content.value);
			if (ril->content.e_type == 2)
				g_status = redirect_in(vars, i, ril->content.value);
			if (ril->content.e_type == 3)
				g_status = redirect_out(vars, i, ril->content.value);
			if (ril->content.e_type == 5)
				g_status = redirect_app(vars, i, ril->content.value);
			ril = ril->next;
		}
		lil = lil->next;
		i++;
	}
	return (g_status);
}
