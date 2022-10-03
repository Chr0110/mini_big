/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:00:11 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/03 12:01:18 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_b_l **big_list, char **env)
{
	t_b_l	*temp_big;
	t_p_l	*expand_list;
	t_p_l	*temp_arg;
	t_r		*temp_red;
	int		j;

	temp_big = *big_list;
	temp_arg = (*big_list)->arg;
	temp_red = (*big_list)->red;
	exp_creat_list(temp_big, env);
	// remove_f_quotes(temp_big, temp_big->arg, temp_big->red, *big_list);
	while (temp_big)
	{
		while (temp_big->arg)
		{
			printf("->%s\n", temp_big->arg->content.value);
			temp_big->arg = temp_big->arg->next;
		}
		while (temp_big->red)
		{
			printf("-->%s\n", temp_big->red->content.value);
			temp_big->red = temp_big->red->next;
		}
		temp_big = temp_big->next;
	}
}
