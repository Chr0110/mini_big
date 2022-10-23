/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 17:41:49 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_bar(t_b_l *big)
{
	int	i;
	int	len;
	t_p_l *tmp;
	len = 0;
	i = 0;
	len = ft_lstsize(big->arg);
	tmp = big->arg;
	big->str = malloc(sizeof(char *) * (len + 1));
	while (tmp)
	{
		big->str[i] = tmp->content.value;
		tmp = tmp->next;
		i++;
	}
	big->str[i] = NULL;
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
	// free(sv);
	ft_pipe(big, data, vars, j);
}
