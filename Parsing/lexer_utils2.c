/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:58:48 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/14 01:53:51 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*skip_white_spaces(char *src)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	char *str;
	while (src[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	i = 0;
	while (src[i] && (src[i] == ' ' || src[i] == '\t'))
		i++;
	while (src[i])
	{
		str[j] = src[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(src);
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
}
