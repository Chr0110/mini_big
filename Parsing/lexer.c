/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:38:40 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/02 20:13:59 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_token(t_lx *lx, char **env, t_token *token, t_list *small_branch)
{
	int	j;

	lexer_init(lx);
	j = 0;
	while (j < lx->t_sz)
	{
		if (lx->str[lx->j] == '|' )
			pip_lexer(lx, &j, token, &small_branch);
		if (lx->str[lx->j] != '<' && lx->str[lx->j] != '>'
			&& lx->str[lx->j] != ' ' && lx->str[lx->j] != '|' && j < lx->t_sz)
			if (lexer_q_cases(lx, &j, token, &small_branch) == 0)
				break ;
		if (lx->str[lx->j] == '>' && lx->str[lx->j + 1] == '>')
			append_lexer(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '<' && lx->str[lx->j + 1] == '<')
			heredoc_lexer(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '>' && lx->str[lx->j + 1] != '>')
			red_out_lx(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '<' && lx->str[lx->j + 1] != '<')
			red_in_lexer(lx, &j, token, &small_branch);
	}
	if (lx->error == 0)
		check_errors(small_branch, token, env);
}

void	init_lexer(char *src, char **env)
{
	char	*str;
	t_token	*token;
	t_list	*small_branch;
	int		j;
	t_lx	*lexer;

	j = 0;
	small_branch = NULL;
	lexer = malloc(1 * sizeof(t_lx));
	token = malloc(1 * sizeof(t_token));
	if (src[0] == '\0')
		return ;
	str = skip_white_spaces(src, str);
	lexer->str = str;
	lexer->j = 0;
	lexer->c = lexer->str[lexer->j];
	get_token(lexer, env, token, small_branch);
}
