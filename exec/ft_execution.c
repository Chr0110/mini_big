/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/07 20:13:00 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
	

void ft_execution(t_b_l *big, t_vars *vars, char *ptr)
{
	//printf("%s\n", big->arg->content.value);
	ft_pipe(ptr, vars);
}
