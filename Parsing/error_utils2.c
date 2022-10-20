/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:35:02 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:56:39 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	r_o_error(int i, int *error)
{
	int	j;

	j = 0;
	if (i == 0)
		j = panic("syntax error", "|", "error in redirection out", 258);
	else if (i == 2)
		j = panic("syntax error", "<", "error in redirecion out", 258);
	else if (i == 3)
		j = panic("syntax error", ">", "error in redirecion out", 258);
	else if (i == 4)
		j = panic("syntax error", "<<", "error in redirecion out", 258);
	else if (i == 5)
		j = panic("syntax error", ">>", "error in redirecion out", 258);
	if (j == 1)
	{
		(*error)++;
		return (1);
	}
	return (0);
}

int	r_i_error(int i, int *error)
{
	int	j;

	j = 0;
	if (i == 0)
		j = panic("syntax error", "|", "error in redirecion in", 258);
	else if (i == 2)
		j = panic("syntax error", "<", "error in redirecion in", 258);
	else if (i == 3)
		j = panic("syntax error", ">", "error in redirecion in", 258);
	else if (i == 4)
		j = panic("syntax error", "<<", "error in redirecion in", 258);
	else if (i == 5)
		j = panic("syntax error", ">>", "error in redirecion in", 258);
	if (j == 1)
	{
		(*error)++;
		return (1);
	}
	return (0);
}
