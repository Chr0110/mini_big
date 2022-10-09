/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:58:48 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/09 04:24:08 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*skip_white_spaces(char *src, char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (src[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i] == ' ' || src[i] == '\t')
		i++;
	while (src[i])
	{
		str[j] = src[i];
		i++;
		j++;
	}
	// while (str[j - 1] == ' ' || str[j - 1] == '\t')
	// 	j--;
	str[j] = '\0';
	return (str);
}

int	still_a_quote(t_lx *lexer, int i)
{
	int	j;
	int	d;
	int	s;

	j = 0;
	d = 0;
	s = 0;
	while (j < i)
	{
		if (lexer->str[j] == 34)
		{
			j++;
			d++;
		}
		else if (lexer->str[j] == '\'')
		{
			j++;
			s++;
		}
		else
			j++;
	}
	if (d % 2 == 0 && s % 2 == 0)
		return (0);
	return (1);
}

char	*ft_strdup(char *s1)
{
	int		j;
	int		i;
	char	*s2;

	i = ft_strlen(s1);
	j = 0;
	s2 = malloc(i + 1 * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[j] != '\0')
	{
		s2[j] = (char)s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	lexer_init(t_lx	*lexer)
{
	lexer->text = (char **)malloc((lexer->tx + 1) * sizeof(char *));
	lexer->redirection_in = (char **)malloc((lexer->red_i + 1) * sizeof(char *));
	lexer->redirection_out = (char **)malloc((lexer->red_o + 1) * sizeof(char *));
	lexer->pip = (char **)malloc((lexer->pi + 1) * sizeof(char *));
	lexer->heredoc = (char **)malloc((lexer->her + 1) * sizeof(char *));
	lexer->append = (char **)malloc((lexer->app + 1) * sizeof(char *));
	lexer->text[lexer->tx] = NULL;
	lexer->redirection_in[lexer->red_i] = NULL;
	lexer->redirection_out[lexer->red_o] = NULL;
	lexer->pip[lexer->pi] = NULL;
	lexer->heredoc[lexer->her] = NULL;
	lexer->append[lexer->app] = NULL;
	lexer->error = 0;
	lexer->t = 0;
	lexer->r_i = 0;
	lexer->r_o = 0;
	lexer->p = 0;
	lexer->h = 0;
	lexer->a = 0;
	lexer->t_sz = ft_strlen(lexer->str);
	if (lexer->tx != 0)
		lexer->text[lexer->t] = ft_strdup("");
	if (lexer->red_i != 0)
		lexer->redirection_in[lexer->r_i] = ft_strdup("");
	if (lexer->red_o != 0)
		lexer->redirection_out[lexer->r_o] = ft_strdup("");
	if (lexer->pi != 0)
		lexer->pip[lexer->p] = ft_strdup("");
	if (lexer->her != 0)
		lexer->heredoc[lexer->h] = ft_strdup("");
	if (lexer->app != 0)
		lexer->append[lexer->a] = ft_strdup("");
}

