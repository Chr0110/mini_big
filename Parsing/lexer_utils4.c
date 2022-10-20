/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:35:56 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 09:02:33 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	red_in_lexer(t_lx *lexer, int *j, t_token *token, t_list **small_branch)
{
	lexer->redirection_in[lexer->r_i] = malloc(2 * sizeof(char));
	lexer->redirection_in[lexer->r_i][0] = '<';
	lexer->redirection_in[lexer->r_i][1] = '\0';
	token->value = lexer->redirection_in[lexer->r_i];
	token->e_type = TOKEN_REDIRECTION_IN;
	lexer->r_i = lexer->r_i + 1;
	lexer->j++;
	(*j)++;
	ft_creatlst(small_branch, token);
	while (lexer->str[lexer->j] == ' ')
	{
		lexer->j++;
		(*j)++;
	}
}

void	red_out_lx(t_lx *lexer, int *j, t_token *token, t_list **small_branch)
{
	lexer->redirection_out[lexer->r_o] = malloc(2 * sizeof(char));
	lexer->redirection_out[lexer->r_o][0] = '>';
	lexer->redirection_out[lexer->r_o][1] = '\0';
	token->value = lexer->redirection_out[lexer->r_o];
	token->e_type = TOKEN_REDIRECTION_OUT;
	lexer->r_o = lexer->r_o + 1;
	lexer->j++;
	(*j)++;
	ft_creatlst(small_branch, token);
	while (lexer->str[lexer->j] == ' ')
	{
		lexer->j++;
		(*j)++;
	}
}

void	heredoc_lexer(t_lx *lx, int *j, t_token *token, t_list **small_branch)
{
	lx->heredoc[lx->h] = malloc(3 * sizeof(char));
	lx->heredoc[lx->h][0] = '<';
	lx->heredoc[lx->h][1] = '<';
	lx->heredoc[lx->h][2] = '\0';
	token->value = lx->heredoc[lx->h];
	token->e_type = TOKEN_HERDOC;
	lx->h = lx->h + 1;
	lx->j += 2;
	(*j) += 2;
	ft_creatlst(small_branch, token);
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}

int	d_q_with_error(t_lx *lx, int *j, t_token *token)
{
	lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
	token->value = lx->text[lx->t];
	token->e_type = TOKEN_TEXT;
	lx->j++;
	(*j)++;
	if (number_of_quotes(lx) == 1)
	{
		while ((*j) < lx->t_sz)
		{
			lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
			token->value = lx->text[lx->t];
			token->e_type = TOKEN_TEXT;
			lx->j++;
			(*j)++;
		}
		lx->error++;
		panic("syntax error", "quotes", "close the quotes", 1);
		return (1);
	}
	return (0);
}
