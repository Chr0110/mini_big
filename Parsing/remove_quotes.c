/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:48:12 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/07 17:15:14 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_s_a(char **res, int *i, char *s)
{
	(*i)++;
	while (s[(*i)] != 39)
	{
		*res = ft_strjoin_one(*res, s[(*i)]);
		(*i)++;
	}
	(*i)++;
}

void	remove_d_a(char **res, int *i, char *s)
{
	(*i)++;
	while (s[(*i)] != 34)
	{
		*res = ft_strjoin_one(*res, s[(*i)]);
		(*i)++;
	}
	(*i)++;
}

void	remove_quotes(t_token *node)
{
	char	*s;
	int		i;
	char	*res;

	res = strdup("");
	i = 0;
	s = node->value;
	while (s[i])
	{
		if (s[i] == 34)
			remove_d_a(&res, &i, s);
		else if (s[i] == 39)
			remove_s_a(&res, &i, s);
		else
		{
			res = ft_strjoin_one(res, s[i]);
			i++;
		}
	}
	node->value = res;
}

void	remove_f_quotes(t_b_l *temp_big)
{
	t_b_l *big;

	big = temp_big;
	while (big)
	{
		t_p_l *arg = big->arg;
		t_r *red = big->red;
		while (arg)
		{
			remove_quotes(&arg->content);
			arg = arg->next;
		}
		while (red)
		{
			remove_quotes(&red->content);
			red = red->next;
		}
		big = big->next;
	}
}
