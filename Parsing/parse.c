/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:08:19 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/10 03:15:37 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parsing(t_list *s_b, t_token *token, char **env, t_b_l **big_list)
{
	int		i;
	t_p_l	*parse_branch;
	t_r		*red;
	t_list *t;

	i = 0;
	parse_branch = NULL;
	red = NULL;
	(*big_list) = NULL;
	t_list *tmp = s_b;
	while (s_b)
	{
		if (i == 0 && s_b->content.e_type == 1)
			creat_cmd(s_b, token, &parse_branch, &i);
		else if (s_b && s_b->content.e_type == 1)
			creat_arg(s_b, token, &parse_branch);
		else if (s_b && s_b->content.e_type != 1 && s_b->content.e_type != 0)
			red_creat(s_b, token, &red);
		if (s_b && (s_b->content.e_type == 0 || s_b->next == NULL))
			ft_creat_big_list(big_list, &parse_branch, &red, &i);
		s_b = s_b->next;
	}
	//printf("%p\n", (*big_list)->arg->content.value);
	while(tmp)
	{
		t = tmp->next;
		free(tmp);
		tmp = t;
	}
	free(token);
	//expand(big_list, env);
}