/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:08:19 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/27 23:09:52 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_after_parsing(t_lx *lx, t_list *tmp1)
{
	t_list	*t;

	while (tmp1)
	{
		t = tmp1->next;
		free(tmp1->content.value);
		free(tmp1);
		tmp1 = t;
	}
	free_lexer(&lx);
}

void	parse2(t_b_l **big_list, t_list *s_b, t_p_l *p, t_r *red)
{
	int		i;
	t_token	*token;

	i = 0;
	token = malloc(1 * sizeof(t_token));
	while (s_b)
	{
		if (i == 0 && s_b->content.e_type == 1)
			creat_cmd(s_b, token, &p, &i);
		else if (s_b && s_b->content.e_type == 1)
			creat_arg(s_b, token, &p);
		else if (s_b && s_b->content.e_type != 1 && s_b->content.e_type != 0)
		{
			red_creat(s_b, token, &red);
			s_b = s_b->next;
		}
		if (s_b && (s_b->content.e_type == 0 || s_b->next == NULL))
			ft_creat_big_list(big_list, &p, &red, &i);
		s_b = s_b->next;
	}
	free(token);
}

void	parsing(t_list *s_b, char **env, t_b_l **big_list, t_lx *lx)
{
	int		i;
	t_p_l	*parse_branch;
	t_r		*red;
	t_list	*tmp1;

	tmp1 = s_b;
	i = 0;
	*big_list = NULL;
	parse_branch = NULL;
	red = NULL;
	parse2(big_list, s_b, parse_branch, red);
	free_after_parsing(lx, tmp1);
	expand(big_list, env);
}
