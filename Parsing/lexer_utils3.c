/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:50:01 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/02 17:08:17 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ft_creat_list(t_lx *lx, int *j, t_token *tkn, t_list **sm_br)
{
	ft_creatlst(sm_br, tkn);
	lx->t = lx->t + 1;
	lx->text[lx->t] = ft_strdup("");
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}

void	ft_creat_normal_text(t_lx *lx, int *j, t_token *tk, t_list **sm_br)
{
	lx->text[lx->t] = ft_strjoin_one(lx->text[lx->t], lx->str[lx->j]);
	tk->value = lx->text[lx->t];
	tk->e_type = TOKEN_TEXT;
	lx->j++;
	(*j)++;
	if (lx->str[lx->j] == ' ' || lx->str[lx->j] == '<' || lx->str[lx->j] == '>'
		|| lx->str[lx->j] == '|' || (*j) == lx->t_sz)
	{
		ft_creatlst(sm_br, tk);
		lx->t = lx->t + 1;
		lx->text[lx->t] = ft_strdup("");
		while (lx->str[lx->j] == ' ')
		{
			lx->j++;
			(*j)++;
		}
	}
}

void	pip_lexer(t_lx *lx, int *j, t_token *tk, t_list **sm_br)
{
	lx->pip[lx->p] = malloc(2 * sizeof(char));
	lx->pip[lx->p][0] = '|';
	lx->pip[lx->p][1] = '\0';
	tk->value = lx->pip[lx->p];
	tk->e_type = TOKEN_PIP;
	lx->pip[lx->p + 1] = ft_strdup("");
	lx->j++;
	(*j)++;
	ft_creatlst(sm_br, tk);
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}

void	append_lexer(t_lx *lx, int *j, t_token *tk, t_list **sm_br)
{
	lx->append[lx->a] = malloc(3 * sizeof(char));
	lx->append[lx->a][0] = '>';
	lx->append[lx->a][1] = '>';
	lx->append[lx->a][2] = '\0';
	tk->value = lx->append[lx->a];
	tk->e_type = TOKEN_APPEND;
	lx->append[lx->a + 1] = ft_strdup("");
	lx->j += 2;
	(*j) += 2;
	ft_creatlst(sm_br, tk);
	while (lx->str[lx->j] == ' ')
	{
		lx->j++;
		(*j)++;
	}
}
