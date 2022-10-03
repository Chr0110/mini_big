/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:37:25 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/01 10:48:43 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s, char c)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s);
	temp = malloc((i + 2) * sizeof(char));
	while (j < i)
	{
		temp[j] = s[j];
		j++;
	}
	temp[i] = c;
	temp[i + 1] = '\0';
	return (temp);
}

int	count_s_q(int *i, t_lx *lexer)
{
	(*i)++;
	while (lexer->str[(*i)] != '\'' && lexer->str[(*i)] != '\0')
		(*i)++;
	if ((*i) == ft_strlen(lexer->str))
		return (1);
	else
		(*i)++;
	return (0);
}

int	count_d_q(int *i, t_lx *lexer)
{
	(*i)++;
	while (lexer->str[(*i)] != '\"' && lexer->str[(*i)] != '\0')
		(*i)++;
	if ((*i) == ft_strlen(lexer->str))
		return (1);
	else
		(*i)++;
	return (0);
}

int	number_of_quotes(t_lx *lexer)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (lexer->str[i])
	{
		if (lexer->str[i] == '\"' || lexer->str[i] == '\'')
		{
			if (lexer->str[i] == '\"')
			{
				if (count_d_q(&i, lexer) == 1)
					return (1);
			}
			else if (lexer->str[i] == '\'')
				if (count_s_q(&i, lexer) == 1)
					return (1);
		}
		else
			i++;
	}
	return (0);
}
