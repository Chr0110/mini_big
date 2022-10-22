/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:35:33 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 08:07:06 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		j;
	char	*big;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		big = (char *)haystack + i;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return (big);
				j++;
			}
			big = 0;
		}
		i++;
	}
	return (NULL);
}

int	count_list(t_b_l *lst)
{
	t_b_l	*sv;
	int		len;

	len = 0;
	sv = lst;
	if (!lst)
		return (0);
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	lst = sv;
	return (len);
}

int	ft_atoi(const char *str)
{
	size_t	res;
	int		signe;
	size_t	i;

	i = 0;
	signe = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = signe * (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res > 9223372036854775807)
		{
			if (signe == -1)
				return (0);
			return (-1);
		}
	}
	return (res * signe);
}
