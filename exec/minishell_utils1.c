/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:21 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 15:27:50 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if ((*s != c && len == 0) || (*s != c && *(s - 1) == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		end;
	int		index;
	int		start;

	end = 0;
	start = 0;
	index = 0;
	if (!s)
		return (NULL);
	ptr = ft_calloc(sizeof(char *), (ft_len(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (index < ft_len(s, c))
	{
		while (s[end] == c && s[end])
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		ptr[index] = ft_substr(s, start, end - start);
		index++;
	}
	ptr[index] = NULL;
	return (ptr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	ptr = ft_calloc(sizeof(char), (len + 1));
	if (!ptr)
		return (ptr);
	while (s[start] && i < len && start <= ft_strlen(s))
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s2[i] - s1[i]);
}
