/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:00:11 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/15 06:00:42 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_b_l **big_list, char **env)
{
	t_b_l	*temp_big;
	t_r		*temp_red;
	int		i;
	char *s;
	
	temp_big = *big_list;
	exp_creat_list(temp_big, env);
	remove_f_quotes(temp_big);
	//remove_f_quotes(temp_big);
	// t_b_l *btmp = *big_list;
	// t_p_l *tmp;
	// t_r *rtmp;
	// while(btmp)
	// {
	// 	while(btmp->arg)
	// 	{
	// 		tmp = btmp->arg;
	// 		btmp->arg = btmp->arg->next;
	// 		free(tmp);
	// 	}
	// 	while(btmp->red)
	// 	{
	// 		rtmp = btmp->red;
	// 		btmp->red = btmp->red->next;
	// 		free(rtmp);
	// 	}
	// 	btmp = btmp->next;
	// }
	// free(btmp);
}
