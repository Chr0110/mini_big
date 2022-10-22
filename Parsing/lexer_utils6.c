/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:03:10 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/22 07:51:58 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free2d(char **ptr)
{
	int	j;

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

void	free_lexer(t_lx **lexer)
{
	if ((*lexer) == NULL)
		return ;
	free((*lexer)->str);
	free((*lexer)->text);
	free2d((*lexer)->pip);
	free2d((*lexer)->append);
	free2d((*lexer)->heredoc);
	free2d((*lexer)->redirection_in);
	free2d((*lexer)->redirection_out);
	free((*lexer));
}

void	free_lexer2(t_lx **lexer)
{
	if ((*lexer) == NULL)
		return ;
	free((*lexer)->str);
	free((*lexer)->text);
	free((*lexer)->pip);
	free((*lexer)->append);
	free((*lexer)->heredoc);
	free((*lexer)->redirection_in);
	free((*lexer)->redirection_out);
	free((*lexer));
}

void	go_count_again(char *s, int *i, t_lx *lexer)
{
	if (s[(*i)] == '<' && s[(*i) + 1] != '<' && not_between_quotes(s, (*i)))
		lexer->red_i++;
	else if (s[(*i)] == '>' && s[(*i) + 1] != '>'
		&& not_between_quotes(s, (*i)))
		lexer->red_o++;
	else if (s[(*i)] != '<' && s[(*i)] != '>'
		&& s[(*i)] != '|' && s[(*i)] != ' ')
	{
		while (s[(*i)] != '<' && s[(*i)] != '>' && s[(*i)] != '|'
			&& s[(*i)] != ' ' && (*i) < ft_strlen1(s))
			(*i)++;
		(*i) = (*i) - 1;
		lexer->tx++;
	}
}

void	how_much(char *s, t_lx *lexer)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '|')
			lexer->pi++;
		else if (s[i] == '<' && s[i + 1] == '<' && not_between_quotes(s, i))
		{
			lexer->her++;
			i++;
		}
		else if (s[i] == '>' && s[i + 1] == '>' && not_between_quotes(s, i))
		{
			lexer->app++;
			i++;
		}
		else
			go_count_again(s, &i, lexer);
		i++;
	}
}
