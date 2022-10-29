/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:00:11 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/27 23:04:21 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	expand(t_b_l **big_list, char **env)
{
	t_b_l	*temp_big;
	t_p_l	*ex_list;
	t_b_l	*tmp_big;

	ex_list = NULL;
	temp_big = NULL;
	tmp_big = NULL;
	temp_big = *big_list;
	exp_creat_list(temp_big, env, ex_list, tmp_big);
	remove_f_quotes(temp_big);
}
