/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:37:25 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/22 07:51:27 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_s_q(int *i, t_lx *lexer)
{
	(*i)++;
	while (lexer->str[(*i)] != '\'' && lexer->str[(*i)] != '\0')
		(*i)++;
	if ((*i) == ft_strlen1(lexer->str))
		return (1);
	else
		(*i)++;
	return (0);
}

int	count_d_q(int *i, t_lx *lexer)
{
	(*i)++;
	while (lexer->str[(*i)] != '\"' && lexer->str[(*i)] != '\0')
		(*i)++;
	if ((*i) == ft_strlen1(lexer->str))
		return (1);
	else
		(*i)++;
	return (0);
}

int	number_of_quotes(t_lx *lexer)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (lexer->str[i])
	{
		if (lexer->str[i] == '\"' || lexer->str[i] == '\'')
		{
			if (lexer->str[i] == '\"')
			{
				if (count_d_q(&i, lexer) == 1)
					return (1);
			}
			else if (lexer->str[i] == '\'')
				if (count_s_q(&i, lexer) == 1)
					return (1);
		}
		else
			i++;
	}
	return (0);
}
