/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:02:26 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/09 18:28:09 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free2d(char **ptr)
{
	int j;

	j = 0;
	if (ptr == NULL)
		return ;
	while (ptr[j] != NULL)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
}

void	free_lexer(t_lx *lexer)
{
	if (lexer == NULL)
		return ;
	free(lexer->str);
	free2d(lexer->text);
	free2d(lexer->pip);
	free2d(lexer->append);
	free2d(lexer->heredoc);
	free2d(lexer->redirection_in);
	free2d(lexer->redirection_out);
	free(lexer);
}

void	how_much(char *s, t_lx *lexer)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '|')
			lexer->pi++;
		else if (s[i] == '<' && s[i + 1] == '<')
		{
			lexer->her++;
			i++;
		}
		else if (s[i] == '>' && s[i + 1] == '>')
		{
			lexer->app++;
			i++;
		}
		else if (s[i] == '<' && s[i + 1] != '<')
			lexer->red_i++;
		else if (s[i] == '>' && s[i + 1] != '>')
			lexer->red_o++;
		else if (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != ' ')
		{
			while (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != ' ' && i < ft_strlen(s))
				i++;
			i = i - 1;
			lexer->tx++;
		}
		i++;
	}
}
void	get_token(char **env, t_lx *lx, t_list *small_branch, t_b_l **big_list)
{

	int	j;
	t_token	*token;

	token = malloc(1 * sizeof(t_token));
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
		check_errors(small_branch, token, env, big_list);
	free(token);
	
}

void	init_lexer(char *src, char **env, t_b_l **big_branch)
{
	char	*str;
	t_list	*small_branch;
	t_lx	*lexer;
	int		j;

	lexer = malloc(1 * sizeof(t_lx));
	lexer->tx = 0;
	lexer->red_i = 0;
	lexer->red_o = 0;
	lexer->pi = 0;
	lexer->her = 0;
	lexer->app = 0;
	j = 0;
	small_branch = NULL;
	if (src[0] == '\0')
		return ;
	str = skip_white_spaces(src, str);
	lexer->str = str;
	lexer->j = 0;
	lexer->c = lexer->str[lexer->j];
	how_much(lexer->str, lexer);
	// printf("%d\n",lexer->tx);
	// printf("%d\n",lexer->red_i);
	// printf("%d\n",lexer->red_o);
	// printf("%d\n",lexer->pi);
	// printf("%d\n",lexer->her);
	// printf("%d\n",lexer->app);
	get_token(env, lexer, small_branch, big_branch);
	free_lexer(lexer);
}