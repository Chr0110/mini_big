/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:51:02 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/29 07:53:18 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	send_by_type(t_b_l *t_b, char **env, t_p_l **ex_ls)
{
	t_r	*current_red;

	current_red = t_b->red;
	while (current_red)
	{
		if (current_red->content.e_type == 4)
			expand_dollar(&current_red->content, env, 4, ex_ls);
		else if (current_red->content.e_type == 2)
			expand_dollar(&current_red->content, env, 2, ex_ls);
		else if (current_red->content.e_type == 3)
			expand_dollar(&current_red->content, env, 3, ex_ls);
		else if (current_red->content.e_type == 5)
			expand_dollar(&current_red->content, env, 5, ex_ls);
		current_red = current_red->next;
	}
}

t_p_l	*get_last_node(t_p_l *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	exp_creat_list(t_b_l *t_big, char **env, t_p_l *ex_ls, t_b_l *tmp_big)
{
	t_for_exp	*exp;

	exp = malloc(sizeof(t_for_exp));
	tmp_big = t_big;
	while (tmp_big)
	{
		expand1(exp, tmp_big);
		while (exp->current_arg)
		{
			expand_dollar(&exp->current_arg->content, env, 0, &ex_ls);
			if (ft_lstsize(ex_ls) != 0)
				expand2(exp, ex_ls, tmp_big);
			else
				expand3(exp);
		}
		while (exp->current_red)
		{
			if (find_dollar(exp->current_red->content.value))
				send_by_type(tmp_big, env, &ex_ls);
			exp->current_red = exp->current_red->next;
		}
		tmp_big = tmp_big->next;
	}
	free(exp);
}
