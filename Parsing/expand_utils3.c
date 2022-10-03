/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:51:02 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/03 08:20:58 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	send_by_type(t_b_l *t_b, char **env, t_p_l *expand_list)
{
	while (t_b->red)
	{
		if (t_b->red->content.e_type == 4)
			expand_dollar(&t_b->red->content, env, 4, &expand_list);
		else if (t_b->red->content.e_type == 2)
			expand_dollar(&t_b->red->content, env, 2, &expand_list);
		else if (t_b->red->content.e_type == 3)
			expand_dollar(&t_b->red->content, env, 3, &expand_list);
		else if (t_b->red->content.e_type == 5)
			expand_dollar(&t_b->red->content, env, 5, &expand_list);
		t_b->red = t_b->red->next;
	}
}

void	make_list0(t_p_l **t_a, t_p_l *x_l, t_b_l **t_b, t_p_l *nxt)
{
	t_p_l	*temp_ar;

	temp_ar = *t_a;
	if (temp_ar->next)
		nxt = temp_ar->next;
	else
		nxt = NULL;
	temp_ar = x_l;
	while (x_l->next)
		x_l = x_l->next;
	x_l->next = nxt;
	(*t_b)->arg = temp_ar;
	(*t_a) = temp_ar;
}

void	make_list(t_p_l **t_a, t_p_l *x_ls, int i, t_b_l **t_b)
{
	int		j;
	t_p_l	*nexty;
	t_p_l	*temp_ar;

	temp_ar = *t_a;
	j = 0;
	if (i != 0)
	{
		while (j++ < i - 1)
			temp_ar = temp_ar->next;
		if (temp_ar->next)
			nexty = temp_ar->next->next;
		else
			nexty = NULL;
		temp_ar->next = x_ls;
		while (x_ls->next)
			x_ls = x_ls->next;
		x_ls->next = nexty;
		temp_ar = temp_ar->next;
		(*t_b)->arg = temp_ar;
	}
	else
		make_list0(t_a, x_ls, t_b, nexty);
}

void	exp_creat_list(t_b_l *t_big, t_p_l *t_arg, char **env, t_r *t_r)
{
	t_p_l	*expand_list;
	int		i;

	i = 0;
	while (t_big)
	{
		while (t_big->arg)
		{
			expand_dollar(&t_arg->content, env, 0, &expand_list);
			if (ft_lstsize(expand_list) != 0)
				make_list(&t_arg, expand_list, i, &t_big);
			t_big->arg = t_big->arg->next;
			i++;
		}
		t_big->arg = t_arg;
		while (t_big->red)
			send_by_type(t_big, env, expand_list);
		t_big->red = t_r;
		t_big = t_big->next;
	}
}
