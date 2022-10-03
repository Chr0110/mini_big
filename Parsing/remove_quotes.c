/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:48:12 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/03 08:49:46 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	remove_f_quotes(t_b_l *temp_big, t_p_l *arg, t_r *red, t_b_l *big_list)
{
	while (temp_big)
	{
		while (temp_big->arg)
		{
			remove_quotes(&temp_big->arg->content);
			temp_big->arg = temp_big->arg->next;
		}
		temp_big->arg = arg;
		while (temp_big->red)
		{
			remove_quotes(&temp_big->red->content);
			temp_big->red = temp_big->red->next;
		}
		temp_big->red = red;
		temp_big = temp_big->next;
	}
	temp_big = big_list;
}
