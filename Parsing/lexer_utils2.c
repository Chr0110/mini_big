/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:58:48 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/30 03:16:07 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*skip_white_spaces(char *src)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	if (!src)
		return (NULL);
	i = 0;
	j = 0;
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
	src = NULL;
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
	s2 = malloc((i + 1) * sizeof(char));
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

void	lexer_init(t_lx	*lx)
{
	lx->text = (char **)malloc((lx->tx + 1) * sizeof(char *));
	lx->redirection_in = (char **)malloc((lx->red_i + 1) * sizeof(char *));
	lx->redirection_out = (char **)malloc((lx->red_o + 1) * sizeof(char *));
	lx->pip = (char **)malloc((lx->pi + 1) * sizeof(char *));
	lx->heredoc = (char **)malloc((lx->her + 1) * sizeof(char *));
	lx->append = (char **)malloc((lx->app + 1) * sizeof(char *));
	lx->text[lx->tx] = NULL;
	lx->redirection_in[lx->red_i] = NULL;
	lx->redirection_out[lx->red_o] = NULL;
	lx->pip[lx->pi] = NULL;
	lx->heredoc[lx->her] = NULL;
	lx->append[lx->app] = NULL;
	lx->error = 0;
	lx->t = 0;
	lx->r_i = 0;
	lx->r_o = 0;
	lx->p = 0;
	lx->h = 0;
	lx->a = 0;
	lx->t_sz = ft_strlen(lx->str);
}
