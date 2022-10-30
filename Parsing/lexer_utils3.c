/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:50:01 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/30 04:08:35 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_ft_creat_list(t_lx *lx, int *j, t_token *tkn, t_list **sm_br)
{
	ft_creatlst(sm_br, tkn);
	free(lx->text[lx->t]);
	lx->t = lx->t + 1;
	if (lx->str[lx->j] != 0)
		lx->text[lx->t] = ft_strdup("");
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}

void	ft_creat_normal_text(t_lx *lx, int *j, t_token *tkn)
{
	while (lx->str[lx->j] != '\"' && lx->str[lx->j] != '\''
		&& lx->str[lx->j] != '<' && lx->str[lx->j] != '>'
		&& lx->str[lx->j] != '|' && *j < lx->t_sz)
	{
		lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
		tkn->value = lx->text[lx->t];
		tkn->e_type = TOKEN_TEXT;
		lx->j++;
		(*j)++;
		if (lx->str[lx->j] == ' ')
			return ;
	}
}

void	pip_lexer(t_lx *lx, int *j, t_token *tkn, t_list **small_b)
{
	lx->pip[lx->p] = malloc(2 * sizeof(char));
	lx->pip[lx->p][0] = '|';
	lx->pip[lx->p][1] = '\0';
	tkn->value = lx->pip[lx->p];
	tkn->e_type = TOKEN_PIP;
	ft_creatlst(small_b, tkn);
	lx->p = lx->p + 1;
	lx->j++;
	(*j)++;
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}

void	append_lexer(t_lx *lx, int *j, t_token *tkn, t_list **sm_br)
{
	lx->append[lx->a] = malloc(3 * sizeof(char));
	lx->append[lx->a][0] = '>';
	lx->append[lx->a][1] = '>';
	lx->append[lx->a][2] = '\0';
	tkn->value = lx->append[lx->a];
	tkn->e_type = TOKEN_APPEND;
	lx->a = lx->a + 1;
	lx->j += 2;
	(*j) += 2;
	ft_creatlst(sm_br, tkn);
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}
