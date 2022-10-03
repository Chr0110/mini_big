/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:57:39 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/02 21:17:56 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *src1, const char *src2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!src1 || !src2)
		return (0);
	s1 = (unsigned char *)src1;
	i = 0;
	s2 = (unsigned char *)src2;
	while (n)
	{
		if (s1[i] == 0 || s2[i] == 0 || s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (0);
}

int	not_between_s_quotes(char *s, int i)
{
	int	j;
	int	n;

	n = 0;
	j = 0;
	while (j < i)
	{
		if (s[j] == '\'')
		{
			j++;
			n++;
		}
		else
			j++;
	}
	if (n % 2 == 0)
		return (1);
	return (0);
}

int	not_between_quotes(char *s, int i)
{
	int	j;
	int	n;

	n = 0;
	j = 0;
	while (j < i)
	{
		if (s[j] == '\"')
		{
			j++;
			n++;
		}
		else
			j++;
	}
	if (n % 2 == 0)
		return (1);
	return (0);
}

int	there_is_a_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && not_between_quotes(str, i))
			return (1);
		else
			i++;
	}
	return (0);
}
