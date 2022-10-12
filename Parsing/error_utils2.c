/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:35:02 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/11 09:04:39 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	r_o_error(int i, int *error)
{
	if (i == 0)
	{
		panic("syntax error", "|", "error in redirecion out", 258);
		(*error)++;
		return (1);
	}
	else if (i == 2)
	{
		panic("syntax error", ">", "error in redirecion out", 258);
		(*error)++;
		return (1);
	}
	else if (i == 3)
	{
		panic("syntax error", "<", "error in redirecion out", 258);
		(*error)++;
		return (1);
	}
	else if (i == 4)
	{
		panic("syntax error", "<<", "error in redirecion out", 258);
		(*error)++;
		return (1);
	}
	else if (i == 5)
	{
		panic("syntax error", ">>", "error in redirecion out", 258);
		(*error)++;
		return (1);
	}
	return (0);
}

int	r_i_error(int i, int *error)
{
	if (i == 0)
	{
		panic("syntax error", "|", "error in redirecion out", 258);
		(*error)++;
		return (1);
	}
	else if (i == 2)
	{
		panic("syntax error", ">", "error in redirecion in", 258);
		(*error)++;
		return (1);
	}
	else if (i == 3)
	{
		panic("syntax error", "<", "error in redirecion in", 258);
		(*error)++;
		return (1);
	}
	else if (i == 4)
	{
		panic("syntax error", "<<", "error in redirecion in", 258);
		(*error)++;
		return (1);
	}
	else if (i == 5)
	{
		panic("syntax error", ">>", "error in redirecion in", 258);
		(*error)++;
		return (1);
	}
	return (0);
}
