/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rediraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:47:53 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 07:51:02 by sriyani          ###   ########.fr       */
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

int	is_herdoc(t_b_l *lil, t_vars *vars, t_data *data)
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
		is_herdoc2(vars, lil, data);
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

void	is_herdoc2(t_vars *vars, t_b_l *lil, t_data *data)
{
	int		i;
	t_b_l	*lil2;
	char	*str;

	i = 0;
	lil2 = lil;
	str = NULL;
	while (lil2)
	{
		while (lil2->red)
		{	
			if (lil2->red->content.e_type == 4)
			{
				str = lil2->red->content.value;
				ft_herdoc(vars, str, data);
			}
			lil2->red = lil2->red->next;
		}			
		lil2 = lil2->next;
	}
}

int	check_rediraction(t_b_l *lil)
{
	while (lil)
	{
		while (lil->red)
		{
			if (lil->red && lil->red->content.e_type == 2)
				return (2);
			if (lil->red && lil->red->content.e_type == 3)
				return (3);
			if (lil->red && lil->red->content.e_type == 5)
				return (5);
			if (lil->red && lil->red->content.e_type == 4)
				return (4);
			lil->red = lil->red->next;
		}	
		lil = lil->next;
	}
	return (0);
}

int	ft_rediraction(t_b_l *lil, t_vars *vars, t_data *data)
{
	int		i;
	t_b_l	*lil2;

	lil2 = lil;
	i = 0;
	while (lil)
	{	
		while (lil->red)
		{
			if (lil->red->content.e_type == 4)
				 g_status = redirect_herd(data, vars, lil2);
			if (lil->red->content.e_type == 2)
				 g_status = redirect_in(vars, i, lil->red->content.value);
			if (lil->red->content.e_type == 3)
				 g_status = redirect_out(vars, i, lil->red->content.value);
			if (lil->red->content.e_type == 5)
				 g_status = redirect_app(vars, i, lil->red->content.value);
			lil->red = lil->red->next;
		}
		lil = lil->next;
		i++;
	}
	return (g_status);
}
