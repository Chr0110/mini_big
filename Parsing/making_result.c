/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:12:53 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/12 13:36:21 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*s_q_r(char **res, char *s, int *i, int *type)
{
	(*res) = ft_strjoin_one((*res), s[(*i)]);
	(*i)++;
	while (s[(*i)] != 39)
	{
		(*res) = ft_strjoin_one((*res), s[(*i)]);
		(*i)++;
	}
	(*res) = ft_strjoin_one((*res), s[(*i)]);
	(*i)++;
	*type = 1;
	return ((*res));
}

char	*d_q_r(t_exp_list *ex_ls, char **env, int type)
{
	char	*value;
	int		v;

	v = 0;
	while (env[v])
		v++;
	ex_ls->res = ft_strjoin_one(ex_ls->res, ex_ls->s[ex_ls->i]);
	ex_ls->i++;
	while (ex_ls->s[ex_ls->i] != 34)
	{
		if (ex_ls->s[ex_ls->i] == '$' && type != 4)
		{
			if (ex_ls->s[ex_ls->i + 1] != 34 && ex_ls->s[ex_ls->i + 1] != '$')
				value = frg3_dik_dollar_d_q(ex_ls, env, v);
			else
				ex_ls->res = dollar_cases(&ex_ls->res, ex_ls->s, &ex_ls->i);
		}
		else
			ex_ls->res = ft_strjoin_one(ex_ls->res, ex_ls->s[ex_ls->i++]);
	}
	ex_ls->res = ft_strjoin_one(ex_ls->res, ex_ls->s[ex_ls->i++]);
	return (ex_ls->res);
}

char	*n_q_r(t_exp_list *ex_l, char **env, int type)
{
	// char	*value;
	int		v;

	v = 0;
	while (env[v])
		v++;
	while (ex_l->s[ex_l->i] != 34 && ex_l->s[ex_l->i] != 39
		&& ex_l->s[ex_l->i] != '\0')
	{
		if (ex_l->s[ex_l->i] == '$' && type != 4)
		{
			(ex_l->i)++;
			if (ex_l->s[ex_l->i] == '\0' || ex_l->s[ex_l->i] == '$')
				ex_l->res = dollar_cases2(&ex_l->res, ex_l->s, &ex_l->i);
			else
			{
				ex_l->res = frg3_dik_dollar_n_d_q(ex_l, env, v);
				//printf("------------>%s\n", ex_l->res);
			}
		}
		else
			ex_l->res = ft_strjoin_one(ex_l->res, ex_l->s[ex_l->i++]);
	}
	return (ex_l->res);
}