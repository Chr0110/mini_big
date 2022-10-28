/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:03:54 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 23:32:48 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_inside_main(t_vars *vars, t_b_l *big, char **av)
{
	t_p_l	*tmp;
	t_b_l	*btmp;

	tmp = NULL;
	btmp = NULL;
	(void) av;
	if (big)
		free_big(big, tmp, btmp);
	if (vars->n_mar)
		ft_free(vars->mar);
	vars->mar = NULL;
	if (vars->n_sar)
		ft_free(vars->sar);
	vars->sar = NULL;
}

void	free_big(t_b_l *big_list, t_p_l *tmp, t_b_l *btmp)
{
	t_r		*rtmp;
	t_b_l	*btmp1;

	btmp = big_list;
	while (btmp)
	{
		while (btmp->arg)
		{
			tmp = btmp->arg;
			btmp->arg = btmp->arg->next;
			free(tmp->content.value);
			free(tmp);
		}
		while (btmp->red)
		{
			rtmp = btmp->red;
			btmp->red = btmp->red->next;
			free(rtmp->content.value);
			free(rtmp);
		}
		btmp1 = btmp;
		btmp = btmp->next;
		free(btmp1);
	}
	free(btmp);
}

int	main(int ac, char **av, char **env)
{
	char	*ptr;
	t_vars	*vars;
	t_b_l	*big;
	t_data	*data;

	vars = ft_calloc(sizeof(t_vars), 1);
	data = ft_calloc(sizeof(t_data), 1);
	ft_initial(vars, env, ac);
	while (1)
	{
		ptr = readline(YELLOW"minishell$> "NOR);
		init_signal();
		if (! ptr)
			print_prompt();
		else if (!ft_strlen(ptr))
			free(ptr);
		else if (ft_strlen(ptr) != 0)
		{
			add_history(ptr);
			big = ft_parsing(ptr, vars->env, big);
			ptr = NULL;
			ft_execution(big, data, vars);
			free_inside_main(vars, big, av);
		}
	}
}
