/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:00:11 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/16 06:50:31 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_b_l **big_list, char **env)
{
	t_b_l	*temp_big;
	t_r		*temp_red;
	t_p_l	*ex_list;
	t_b_l	*tmp_big;
	
	temp_big = *big_list;
	exp_creat_list(temp_big, env, ex_list, tmp_big);
	remove_f_quotes(temp_big);
}
