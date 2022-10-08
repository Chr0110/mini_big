/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/08 15:48:30 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
	


void ft_execution(t_b_l *big, t_vars *vars, char *ptr)
{
	t_p_l *lil;
	int len = 0;
	
	len = count_list(big);
	// printf("len %d\n", len);
	// while(big)
	// {
	// 	lil = big->arg;
	// 	while (lil)
	// 	{
	// 		printf(GREEN"%s\n", lil->content.value);
	// 		lil = lil->next;
	// 	}
	// 	// printf(MAG"%s\n", big->arg->content.value);
	// 	big = big->next;
	// }
	ft_pipe(big, vars, len);
	
}
