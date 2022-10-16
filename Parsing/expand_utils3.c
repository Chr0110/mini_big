/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:51:02 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/16 06:55:53 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	send_by_type(t_b_l *t_b, char **env, t_p_l **ex_ls)
{
	t_r *current_red = t_b->red;
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
	if (!list)	return NULL;
	while (list->next)
		list = list->next;
	return list;
}

void	make_list(t_p_l **curr, t_p_l *prev, t_p_l *x_ls)
{
	t_p_l	*nexty;
	t_p_l	*temp_ar;

	temp_ar = *curr;
	get_last_node(x_ls)->next = (*curr)->next;		
	if (prev != NULL)
		prev->next = x_ls;
	else
		*curr = x_ls;
}

int	find_dollar(char *s)
{
	int i = 0;
	while(s[i])
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	exp_creat_list(t_b_l *t_big, char **env, t_p_l *ex_ls, t_b_l *tmp_big)
{
	t_p_l	*prev_arg;
	t_p_l	*current_arg_next;
	t_p_l	*tmp_ex_ls_last;
	t_p_l	*current_arg;
	t_r 	*current_red;

	tmp_big = t_big;
	while (tmp_big)
	{
		current_red = tmp_big->red;
		current_arg = tmp_big->arg;
		prev_arg = NULL;
		while (current_arg)
		{
			expand_dollar(&current_arg->content, env, 0, &ex_ls);
			if (ft_lstsize(ex_ls) != 0)
			{
				current_arg_next = current_arg->next;
				tmp_ex_ls_last = get_last_node(ex_ls);
				make_list(&current_arg, prev_arg, ex_ls);
				if (prev_arg == NULL)
				tmp_big->arg = current_arg;
				else
				{
					free(current_arg->content.value);
					free(current_arg);
				}
				prev_arg = tmp_ex_ls_last;
				current_arg = current_arg_next;
			}
			else
			{
				prev_arg = current_arg;
				current_arg = current_arg->next;
			}
		}
		while (current_red)
		{
			if (find_dollar(current_red->content.value))
				send_by_type(tmp_big, env, &ex_ls);
			current_red = current_red->next;
		}
		tmp_big = tmp_big->next;
	}
}