/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:58:48 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/06 22:05:18 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	lexer_init(t_lx	*lexer)
{
	lexer->error = 0;
	lexer->text = (char **)malloc(1000 * sizeof(char *));
	lexer->redirection_in = (char **)malloc(1000 * sizeof(char *));
	lexer->redirection_out = (char **)malloc(1000 * sizeof(char *));
	lexer->pip = (char **)malloc(1000 * sizeof(char *));
	lexer->heredoc = (char **)malloc(1000 * sizeof(char *));
	lexer->append = (char **)malloc(1000 * sizeof(char *));
	lexer->t = 0;
	lexer->r_i = 0;
	lexer->r_o = 0;
	lexer->p = 0;
	lexer->h = 0;
	lexer->a = 0;
	lexer->t_sz = ft_strlen(lexer->str);
	lexer->text[lexer->t] = ft_strdup("");
	lexer->redirection_in[lexer->r_i] = ft_strdup("");
	lexer->redirection_out[lexer->r_o] = ft_strdup("");
	lexer->pip[lexer->p] = ft_strdup("");
	lexer->heredoc[lexer->h] = ft_strdup("");
	lexer->append[lexer->a] = ft_strdup("");
}
