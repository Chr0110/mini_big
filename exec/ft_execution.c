/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 15:52:53 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_bar(t_b_l *big)
{
	int		i;
	t_p_l	*tmp;
	int		len;

	i = 0;
	tmp = big->arg;
	len = ft_lstsize(big->arg);
	big->str = ft_calloc(sizeof(char *), (len + 1));
	while (tmp)
	{
		big->str[i] = ft_strdup(tmp->content.value);
		tmp = tmp->next;
		i++;
	}
	big->str[i] = NULL;
	free(tmp);
	tmp = NULL;
}

void	ft_execution(t_b_l *big, t_data *data, t_vars *vars)
{
	t_b_l	*sv;
	int		j;

	j = 0;
	if (big == NULL)
		return ;
	sv = big;
	while (sv)
	{
		fill_bar(sv);
		sv = sv->next;
		j++;
	}
	ft_pipe(big, data, vars, j);
	big->str = NULL;
}
