/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:51:02 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/15 06:02:34 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	send_by_type(t_b_l *t_b, char **env, t_p_l **expand_list)
{
	t_r *current_red = t_b->red;
	while (current_red)
	{
		if (current_red->content.e_type == 4)
			expand_dollar(&current_red->content, env, 4, expand_list);
		else if (current_red->content.e_type == 2)
			expand_dollar(&current_red->content, env, 2, expand_list);
		else if (current_red->content.e_type == 3)
			expand_dollar(&current_red->content, env, 3, expand_list);
		else if (current_red->content.e_type == 5)
			expand_dollar(&current_red->content, env, 5, expand_list);
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
void	exp_creat_list(t_b_l *t_big, char **env)
{
	t_p_l	*expand_list;
	t_b_l *tmp_big = t_big;
	while (tmp_big)
	{
		t_p_l *current_arg = tmp_big->arg;
		t_r *current_red = tmp_big->red;
		t_p_l *prev_arg = NULL;
		while (current_arg)
		{
			expand_dollar(&current_arg->content, env, 0, &expand_list);
			if (ft_lstsize(expand_list) != 0)
			{
				t_p_l *current_arg_next = current_arg->next;
				t_p_l *tmp_expand_list_last = get_last_node(expand_list);
				make_list(&current_arg, prev_arg, expand_list);
				if (prev_arg == NULL)
				tmp_big->arg = current_arg;
				else
				{
					free(current_arg->content.value);
					free(current_arg);
				}
				prev_arg = tmp_expand_list_last;
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
				send_by_type(tmp_big, env, &expand_list);
			current_red = current_red->next;
		}
		tmp_big = tmp_big->next;
	}
}