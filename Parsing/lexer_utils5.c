/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:54:31 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/02 17:08:37 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	d_q_lexer(t_lx *lx, int *j, t_token *token)
{
	while (lx->str[lx->j] != '\0')
	{
		lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
		token->value = lx->text[lx->t];
		token->e_type = TOKEN_TEXT;
		lx->j++;
		(*j)++;
		if (lx->str[lx->j] == ' ')
		{
			if (not_between_quotes(lx->str, lx->j) == 1)
				return (0);
		}
		if (lx->str[lx->j] == '\'')
			s_q_lexer(lx, j, token);
	}
	return (1);
}

int	s_q_lexer(t_lx *lx, int *j, t_token *token)
{
	while (lx->str[lx->j] != '\0')
	{
		lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
		token->value = lx->text[lx->t];
		token->e_type = TOKEN_TEXT;
		lx->j++;
		(*j)++;
		if (lx->str[lx->j] == ' ')
		{
			if (not_between_s_quotes(lx->str, lx->j) == 1)
				return (0);
		}
		if (lx->str[lx->j] == '\"')
			d_q_lexer(lx, j, token);
	}
	return (1);
}

int	lexer_q_cases(t_lx *lx, int *j, t_token *token, t_list **sm_br)
{
	while (lx->str[lx->j] != '<' && lx->str[lx->j] != '>'
		&& lx->str[lx->j] != '|' && *j < lx->t_sz)
	{
		if (lx->str[lx->j] == '\"' || lx->str[lx->j] == '\'')
		{
			if (lx->str[lx->j] == '\"')
			{
				if (d_q_with_error(lx, j, token) == 1)
					return (0);
				else
					while (d_q_lexer(lx, j, token) != 0)
						break ;
			}
			else
			{
				if (d_q_with_error(lx, j, token) == 1)
					break ;
				else
					while (s_q_lexer(lx, j, token) != 0)
						break ;
			}
			ft_ft_creat_list(lx, j, token, sm_br);
		}
		if (lx->str[lx->j] != '\"' && lx->str[lx->j] != '\''
			&& lx->str[lx->j] != '<' && lx->str[lx->j] != '>'
			&& lx->str[lx->j] != '|' && *j < lx->t_sz)
			ft_creat_normal_text(lx, j, token, sm_br);
	}
	return (1);
}
