/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:08:19 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/14 00:14:49 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing(t_list *s_b, char **env, t_b_l **big_list, t_lx *lx)
{
	int		i;
	t_p_l	*parse_branch;
	t_r		*red;
	t_token	*token; 
	t_list *t;
	i = 0;
	int j = 0;
	*big_list = NULL;
	parse_branch = NULL;
	red = NULL;
	t_list *tmp1 = s_b;
	token = malloc(1 * sizeof(t_token));
	while (s_b)
	{
		if (i == 0 && s_b->content.e_type == 1)
			creat_cmd(s_b, token, &parse_branch, &i);
		else if (s_b && s_b->content.e_type == 1)
			creat_arg(s_b, token, &parse_branch);
		else if (s_b && s_b->content.e_type != 1 && s_b->content.e_type != 0)
		{
			red_creat(s_b, token, &red);
			s_b = s_b->next;
		}
		if (s_b && (s_b->content.e_type == 0 || s_b->next == NULL))
			ft_creat_big_list(big_list, &parse_branch, &red, &i);
		s_b = s_b->next;
	}
	while(tmp1)
	{
		t = tmp1->next;
		free(tmp1->content.value);
		free(tmp1);
		tmp1 = t;
	}
	t_p_l *tmp = parse_branch;
	free(token);
	free_lexer(&lx);
	expand(big_list, env);
}