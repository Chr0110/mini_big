/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:38:40 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/30 04:41:51 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	choose_a_path(t_b_l **big, t_lx *lx, char **env, t_list *s_b)
{
	if (lx->error == 0)
		check_errors(s_b, env, big, lx);
	else
	{
		free_lexer2(&lx);
		*big = NULL;
	}
}

int	check_quotes(t_lx *lx)
{
	if (number_of_quotes(lx) == 1)
	{
		quotes_error(lx);
		return (1);
	}
	return (0);
}

void	get_token(char **env, t_lx *lx, t_list *small_branch, t_b_l **big_list)
{
	int		j;
	t_token	*token;

	token = malloc(1 * sizeof(t_token));
	j = 0;
	while (lx->j < lx->t_sz)
	{
		if (check_quotes(lx))
			break ;
		if (lx->str[lx->j] != '<' && lx->str[lx->j] != '>'
			&& lx->str[lx->j] != ' ' && lx->str[lx->j] != '|' && j < lx->t_sz)
			lexer_q_cases(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '|' )
			pip_lexer(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '>' && lx->str[lx->j + 1] == '>')
			append_lexer(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '<' && lx->str[lx->j + 1] == '<')
			heredoc_lexer(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '>' && lx->str[lx->j + 1] != '>')
			red_out_lx(lx, &j, token, &small_branch);
		if (lx->str[lx->j] == '<' && lx->str[lx->j + 1] != '<')
			red_in_lexer(lx, &j, token, &small_branch);
	}
	choose_a_path(big_list, lx, env, small_branch);
	free(token);
}

char	*skip_white_spaces2(char *s)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen1(s) - 1;
	while (s[i] == ' ')
		i--;
	i++;
	str = NULL;
	str = malloc((i + 1) * sizeof(char));
	str[i] = '\0';
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	return (str);
}

void	init_lexer(char *src, char **env, t_b_l **big_branch)
{
	char	*str;
	char	*str2;
	t_list	*small_branch;
	t_lx	*lexer;

	lexer = malloc(1 * sizeof(t_lx));
	lexer->tx = 0;
	lexer->red_i = 0;
	lexer->red_o = 0;
	lexer->pi = 0;
	lexer->her = 0;
	lexer->app = 0;
	small_branch = NULL;
	str2 = skip_white_spaces(src);
	str = skip_white_spaces2(str2);
	free(str2);
	lexer->str = str;
	lexer->j = 0;
	lexer->c = lexer->str[lexer->j];
	how_much(lexer->str, lexer);
	lexer_init(lexer);
	get_token(env, lexer, small_branch, big_branch);
}
