/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_dollar_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:08:40 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 09:07:18 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_value2(char **res, char **env_cmp)
{
	int		n;
	char	*s;

	n = 0;
	while ((*res)[n])
		n++;
	s = malloc((n) * sizeof(char *));
	s[n] = '\0';
	n = 0;
	while ((*res)[n])
	{
		s[n] = (*res)[n];
		n++;
	}
	free((*res));
	free(*env_cmp);
	return (s);
}

void	get_param_values(int *i, int *n, int *j)
{
	*i = -1;
	*j = 0;
	*n = 0;
}

void	retry(int *j, char **env_cmp, int *n)
{
	*j = 0;
	*n = 0;
	free(*env_cmp);
}
