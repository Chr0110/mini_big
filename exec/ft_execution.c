/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/18 14:42:55 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_bar(t_b_l *big)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	len = ft_lstsize(big->arg);
	big->str = malloc(sizeof(char *) * (len + 1));
	big->str[len] = NULL;
	while (big->arg)
	{
		big->str[i] = ft_strdup(big->arg->content.value);
		big->arg = big->arg->next;
		i++;
	}
}

void	ft_execution(t_b_l *big, t_vars *vars, char *ptr)
{
	t_b_l	*sv;
	int		j;
	int		i;

	j = 0;
	if (big == NULL)
		return ;
	sv = big;
	while (big)
	{
		fill_bar(big);
		big = big->next;
		j++;
	}
	big = sv;
	ft_pipe(big, vars, j);
}
