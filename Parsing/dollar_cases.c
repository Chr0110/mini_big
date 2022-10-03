/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:08:28 by eradi-            #+#    #+#             */
/*   Updated: 2022/09/30 06:09:29 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*dollar_cases2(char **res, char *s, int *i)
{
	if (s[(*i)] == '$')
	{
		(*res) = ft_strjoin_one((*res), '1');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '7');
		*i += 1;
	}
	else if (s[(*i)] == '\0')
		(*res) = ft_strjoin_one((*res), '$');
	return ((*res));
}

char	*dollar_cases(char **res, char *s, int *i)
{
	*i += 1;
	if (s[(*i)] == '$')
	{
		(*res) = ft_strjoin_one((*res), '1');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '7');
		*i += 1;
	}
	else if (s[(*i)] == 34)
		(*res) = ft_strjoin_one((*res), '$');
	return ((*res));
}
