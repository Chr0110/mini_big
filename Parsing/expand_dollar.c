/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:10:23 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/15 06:07:48 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	expand_dollar(t_token *cont, char **env, int type, t_p_l **exp_list)
{
	t_exp_list	*list;
	list = malloc(1 * sizeof(t_exp_list));
	list->i = 0;
	list->s = cont->value;
	list->res = ft_strdup("");
	*exp_list = NULL;
	while (list->s[list->i])
	{
		if (list->s[list->i] == 34)
			list->res = d_q_r(list, env, type);
		else if (list->s[list->i] == 39)
			list->res = s_q_r(list, &type);
		else
			list->res = n_q_r(list, env, type);
	}
	if (there_is_a_space(list->res) && type == 0)
		add_to_parse_list(list->res, exp_list);
	else if (there_is_a_space(list->res) && type != 0)
		panic("ambiguous redirect", NULL, NULL, 1);
	else
	{
		int n = 0;
		while(list->res[n])
			n++;
		free(cont->value);
		cont->value = malloc((n) * sizeof(char*));
		cont->value[n] = '\0';
		n = 0;
		while(list->res[n])
		{
			cont->value[n] = list->res[n];
			n++;
		}
	}
	free(list->res);
	free(list);
}
