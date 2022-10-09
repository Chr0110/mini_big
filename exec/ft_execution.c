/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/09 15:32:30 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
	


void ft_execution(t_b_l *big, t_vars *vars, char *ptr)
{
	t_p_l *lil;
	t_b_l *sv;
	int len = 0;
	int j= 0;
	int i;
	char *str;
	
	// len = count_list(big);
	// printf("len %d\n", len);
	sv = big;
	while(big)
	{
		lil = big->arg;
		len = ft_lstsize(lil);
		big->str = malloc(sizeof(char *) * (len + 1));
		i = 0;
		while (lil)
		{
			// printf(GREEN"%s          %d\n", lil->content.value, i);
			big->str[i] = ft_strdup(lil->content.value);
			lil = lil->next;
			i++;
		}
		big->str[len] = NULL;
		big = big->next;
		j++;
	}
	big = sv;
	// while(big)
	// {
	// 	ft_transform(big);
	// 	big= big->next;
	// }
	
	ft_pipe(big, vars, j);
	
}
