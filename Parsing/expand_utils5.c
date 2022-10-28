/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:12:26 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/28 02:12:44 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	make_list(t_p_l **curr, t_p_l *prev, t_p_l *x_ls)
{
	t_p_l	*temp_ar;

	temp_ar = *curr;
	get_last_node(x_ls)->next = (*curr)->next;
	if (prev != NULL)
		prev->next = x_ls;
	else
		*curr = x_ls;
}

int	find_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	there_is_a_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
