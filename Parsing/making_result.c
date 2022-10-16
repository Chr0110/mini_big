/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:12:53 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/16 20:33:07 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*s_q_r(t_exp_list *list, int *type)
{
	list->res = ft_strjoin_one(list->res, list->s[(list->i)]);
	list->i++;
	while (list->s[(list->i)] != 39)
	{
		list->res = ft_strjoin_one(list->res, list->s[(list->i)]);
		list->i++;
	}
	list->res = ft_strjoin_one(list->res, list->s[(list->i)]);
	(list->i)++;
	*type = 1;
	return (list->res);
}

char	*d_q_r(t_exp_list *ex_ls, char **env, int type)
{
	char	*value;
	int		v;
	int 	cmp;
	int		j;

	v = 0;
	cmp = 0;
	while (env[v])
		v++;
	ex_ls->res = ft_strjoin_one(ex_ls->res, ex_ls->s[ex_ls->i]);
	ex_ls->i++;
	while (ex_ls->s[ex_ls->i] != 34)
	{
		if (ex_ls->s[ex_ls->i] == '$' && type != 4)
		{
			if (ex_ls->s[ex_ls->i + 1] != 34 && ex_ls->s[ex_ls->i + 1] != '$' && ex_ls->s[ex_ls->i + 1] != '?')
				value = expand_dollar_q(ex_ls, env, v, cmp);
			else
				ex_ls->res = dollar_cases(&ex_ls->res, ex_ls->s, &ex_ls->i, j);
		}
		else
			ex_ls->res = ft_strjoin_one(ex_ls->res, ex_ls->s[ex_ls->i++]);
	}
	ex_ls->res = ft_strjoin_one(ex_ls->res, ex_ls->s[ex_ls->i++]);
	return (ex_ls->res);
}

char	*n_q_r(t_exp_list *list, char **env, int type)
{
	int	v;
	int j;

	v = 0;
	while (env[v])
		v++;
	while (list->s[list->i] != 34 && list->s[list->i] != 39
		&& list->s[list->i] != '\0')
	{
		if (list->s[list->i] == '$' && type != 4)
		{
			(list->i)++;
			if (list->s[list->i] == '\0' || list->s[list->i] == '$' || list->s[list->i] == '?')
				list->res = dollar_cases2(&list->res, list->s, &list->i, j);
			else
				list->res = expand_dollar_n_q(list, env, v);
		}
		else
			list->res = ft_strjoin_one(list->res, list->s[list->i++]);
	}
	return (list->res);
}