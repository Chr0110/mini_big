/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:54:31 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/30 04:40:23 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	d_q_lexer(t_lx *lx, int *j, t_token *token)
{
	lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
	token->value = lx->text[lx->t];
	token->e_type = TOKEN_TEXT;
	lx->j++;
	(*j)++;
	while (lx->str[lx->j] != '\"' && lx->str[lx->j] != '\0')
	{
		lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
		token->value = lx->text[lx->t];
		token->e_type = TOKEN_TEXT;
		lx->j++;
		(*j)++;
		if (lx->str[lx->j] == ' ')
		{
			if (not_b_q(lx->str, lx->j) == 1)
				return (0);
		}
	}
	lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
	token->value = lx->text[lx->t];
	token->e_type = TOKEN_TEXT;
	lx->j++;
	(*j)++;
	return (1);
}

int	s_q_lexer(t_lx *lx, int *j, t_token *token)
{
	lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
	token->value = lx->text[lx->t];
	token->e_type = TOKEN_TEXT;
	lx->j++;
	(*j)++;
	while (lx->str[lx->j] != '\'' && lx->str[lx->j] != '\0')
	{
		lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
		token->value = lx->text[lx->t];
		token->e_type = TOKEN_TEXT;
		lx->j++;
		(*j)++;
		if (lx->str[lx->j] == ' ')
		{
			if (not_b_s_q(lx->str, lx->j) == 1)
				return (0);
		}
	}
	lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
	token->value = lx->text[lx->t];
	token->e_type = TOKEN_TEXT;
	lx->j++;
	(*j)++;
	return (1);
}

void	quotes_error(t_lx *lx)
{
	lx->error++;
	panic("syntax error", "quotes", "close the quotes", 1);
}

void	creat_utile(t_lx *lx, int *j, t_token *tkn, t_list **sm_br)
{
	ft_ft_creat_list(lx, j, tkn, sm_br);
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}

void	lexer_q_cases(t_lx *lx, int *j, t_token *token, t_list **sm_br)
{
	if (lx->t == 0)
		lx->text[lx->t] = ft_strdup("");
	while (lx->str[lx->j] != '<' && lx->str[lx->j] != '>'
		&& lx->str[lx->j] != '|' && *j < lx->t_sz)
	{
		if (lx->str[lx->j] == '\"')
			while (d_q_lexer(lx, j, token) != 0)
				break ;
		if (lx->str[lx->j] == '\'')
			while (s_q_lexer(lx, j, token) != 0)
				break ;
		if (lx->str[lx->j] != '\"' && lx->str[lx->j] != '\''
			&& lx->str[lx->j] != '<' && lx->str[lx->j] != '>'
			&& lx->str[lx->j] != '|' && lx->str[lx->j] != ' ' && *j < lx->t_sz)
			ft_creat_normal_text(lx, j, token);
		if (lx->str[lx->j] == ' ')
			break ;
	}
	creat_utile(lx, j, token, sm_br);
}
