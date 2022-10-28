/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_exp_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:54:25 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 20:54:47 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	size_env(t_vars *vars)
{
	int	len;

	len = 0;
	while (vars->env[len])
		++len;
	return (len);
}

int	size_exp(t_vars *vars)
{
	int	len;

	len = 0;
	while (vars->exp[len])
		len++;
	return (len);
}
