/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:14:16 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/27 15:57:50 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand1(t_for_exp *exp, t_b_l *tmp_big)
{
	exp->current_red = tmp_big->red;
	exp->current_arg = tmp_big->arg;
	exp->prev_arg = NULL;
}

void	expand2(t_for_exp *exp, t_p_l *ex_ls, t_b_l *tmp_big)
{
	t_p_l	*tmp;

	exp->current_arg_next = exp->current_arg->next;
	exp->tmp_ex_ls_last = get_last_node(ex_ls);
	make_list(&exp->current_arg, exp->prev_arg, ex_ls);
	if (exp->prev_arg == NULL)
	{
		tmp = tmp_big->arg;
		tmp_big->arg = exp->current_arg;
		free(tmp->content.value);
		free(tmp);
	}
	else
	{
		free(exp->current_arg->content.value);
		free(exp->current_arg);
	}
	exp->prev_arg = exp->tmp_ex_ls_last;
	exp->current_arg = exp->current_arg_next;
}

void	expand3(t_for_exp *exp)
{
	exp->prev_arg = exp->current_arg;
	exp->current_arg = exp->current_arg->next;
}
