/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:38:40 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/30 03:15:10 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	choose_a_path(t_b_l **big, t_lx *lx, char **env, t_list *s_b)
{
	t_list	*t;
	t_list	*tmp1;

	if (lx->error == 0)
		check_errors(s_b, env, big, lx);
	else
	{
		if (s_b && (s_b->content.value && (s_b->content.e_type == 0
					|| s_b->content.e_type == 2
					|| s_b->content.e_type == 3 || s_b->content.e_type == 4
					|| s_b->content.e_type == 5)))
		{
			tmp1 = s_b;
			while (tmp1)
			{
				t = tmp1->next;
				free(tmp1->content.value);
				free(tmp1);
				tmp1 = t;
			}
		}
		free_lexer(&lx);
		*big = NULL;
	}
}

void	get_token(char **env, t_lx *lx, t_list *small_branch, t_b_l **big_list)
{
	int		j;
	t_token	*token;

	token = malloc(1 * sizeof(t_token));
	lexer_init(lx);
	j = 0;
	while (lx->j < lx->t_sz)
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
	printf("%d\n", lexer->pi);
	printf("%d\n", lexer->red_i);
	printf("%d\n", lexer->red_o);
	printf("%d\n", lexer->her);
	printf("%d\n", lexer->app);
	// exit(0);
	get_token(env, lexer, small_branch, big_branch);
}
