/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:10:23 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/29 07:54:19 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	initial_param( t_exp_list **list, t_p_l **exp_list, t_token *cont)
{
	(*list) = malloc(1 * sizeof(t_exp_list));
	(*list)->i = 0;
	(*list)->s = cont->value;
	(*list)->res = ft_strdup("");
	*exp_list = NULL;
}

void	fill_cont_value(t_token **cont, t_exp_list *list)
{
	int	n;

	n = -1;
	(*cont)->value = malloc(ft_strlen(list->res) * sizeof(char *));
	(*cont)->value[ft_strlen(list->res)] = '\0';
	n = -1;
	while (list->res[++n])
		(*cont)->value[n] = list->res[n];
}

void	expand_dollar(t_token *cont, char **env, int type, t_p_l **exp_list)
{
	t_exp_list	*list;
	int			i;

	i = 0;
	initial_param(&list, exp_list, cont);
	while (list->s[list->i])
	{
		if (list->s[list->i] == 34)
			list->res = d_q_r(list, env, type);
		else if (list->s[list->i] == 39)
			list->res = s_q_r(list, &type);
		else
		{
			list->res = n_q_r(list, env, type);
			if (there_is_a_space(list->res) && type == 0)
				i = 1;
		}
	}
	if (there_is_a_space(list->res) && type == 0 && i == 1)
		add_to_parse_list(list->res, exp_list);
	free(cont->value);
	fill_cont_value(&cont, list);
	free(list->res);
	free(list);
}
