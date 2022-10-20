/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:12:53 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 09:04:04 by eradi-           ###   ########.fr       */
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
	*type = 0;
	return (list->res);
}

char	*d_q_r(t_exp_list *e, char **env, int type)
{
	char	*value;
	int		v;
	int		j;

	j = 0;
	v = 0;
	while (env[v])
		v++;
	e->res = ft_strjoin_one(e->res, e->s[e->i]);
	e->i++;
	while (e->s[e->i] != 34)
	{
		if (e->s[e->i] == '$' && type != 4)
		{
			if (e->s[e->i + 1] != 34 && e->s[e->i + 1] != '$'
				&& e->s[e->i + 1] != '?')
				value = expand_dollar_q(e, env, v, 0);
			else
				e->res = dollar_cases(&e->res, e->s, &e->i, j);
		}
		else
			e->res = ft_strjoin_one(e->res, e->s[e->i++]);
	}
	e->res = ft_strjoin_one(e->res, e->s[e->i++]);
	return (e->res);
}

char	*n_q_r(t_exp_list *e, char **env, int type)
{
	int	v;
	int	j;

	j = 0;
	v = 0;
	while (env[v])
		v++;
	while (e->s[e->i] != 34 && e->s[e->i] != 39
		&& e->s[e->i] != '\0')
	{
		if (e->s[e->i] == '$' && type != 4)
		{
			(e->i)++;
			if (e->s[e->i] == '\0' || e->s[e->i] == '$' || e->s[e->i] == '?')
				e->res = dollar_cases2(&e->res, e->s, &e->i, j);
			else
				e->res = expand_dollar_n_q(e, env, v);
		}
		else
			e->res = ft_strjoin_one(e->res, e->s[e->i++]);
	}
	return (e->res);
}
