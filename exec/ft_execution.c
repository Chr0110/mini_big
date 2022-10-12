/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/11 11:21:26 by sriyani          ###   ########.fr       */
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
	if(big == NULL)
		return ;
	sv = big;
	while(big)
	{
		lil = big->arg;
		len = ft_lstsize(lil);
		big->str = malloc(sizeof(char *) * (len + 1));
		big->str[len] = NULL;
		i = 0;
		while (lil)
		{
			big->str[i] = ft_strdup(lil->content.value);
			lil = lil->next;
			i++;
		}
		big = big->next;
		j++;
	}
	big = sv;
	ft_pipe(big, vars, j);
}

	
	

	// t_b_l *lil2 = big;
	// ft_test(lil2);
// }
// void ft_test(t_b_l *lil2)
// {
// 	t_r *lit;
	
// 	int i = 0;
	
// 	while(lil2)
// 	{
// 		lit = lil2->red;
// 		while(lit)
// 		{
// 			printf(BLUE"%d            %s\n", lit->content.e_type, lit->content.value);
// 			lit = lit->next;
// 		}
// 		lil2 = lil2->next;
// 	}
// }
