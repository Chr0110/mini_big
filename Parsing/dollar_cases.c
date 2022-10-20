/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:08:28 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:53:38 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*dollar_cases2(char **res, char *s, int *i, int j)
{
	char	*exit_status;

	j = 0;
	exit_status = ft_itoa(g_status);
	if (s[(*i)] == '$')
	{
		(*res) = ft_strjoin_one((*res), '1');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '7');
		*i += 1;
	}
	else if (s[(*i)] == '?')
	{
		while (j < ft_strlen(exit_status))
		{
			(*res) = ft_strjoin_one((*res), exit_status[j]);
			j++;
		}
		*i += 1;
	}
	else if (s[(*i)] == '\0')
		(*res) = ft_strjoin_one((*res), '$');
	free(exit_status);
	return ((*res));
}

char	*dollar_cases(char **res, char *s, int *i, int j)
{
	char	*exit_status;

	j = 0;
	exit_status = ft_itoa(g_status);
	*i += 1;
	if (s[(*i)] == '$')
	{
		(*res) = ft_strjoin_one((*res), '1');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '3');
		(*res) = ft_strjoin_one((*res), '7');
		*i += 1;
	}
	else if (s[(*i)++] == '?')
	{
		while (j < ft_strlen(exit_status))
		{
			(*res) = ft_strjoin_one((*res), exit_status[j]);
			j++;
		}
	}
	else if (s[(*i)] == 34)
		(*res) = ft_strjoin_one((*res), '$');
	free(exit_status);
	return ((*res));
}
