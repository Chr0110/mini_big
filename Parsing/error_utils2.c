/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:35:02 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/01 15:35:22 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	r_o_error(int i, int *error)
{
	if (i == 2)
	{
		printf("syntax error near unexpected token `>'\n");
		(*error)++;
		return (1);
	}
	else if (i == 3)
	{
		printf("syntax error near unexpected token `<'\n");
		(*error)++;
		return (1);
	}
	else if (i == 4)
	{
		printf("syntax error near unexpected token `<<'\n");
		(*error)++;
		return (1);
	}
	else if (i == 5)
	{
		printf("syntax error near unexpected token `>>'\n");
		(*error)++;
		return (1);
	}
	return (0);
}

int	r_i_error(int i, int *error)
{
	if (i == 2)
	{
		printf("syntax error near unexpected token `>'\n");
		(*error)++;
		return (1);
	}
	else if (i == 3)
	{
		printf("syntax error near unexpected token `<'\n");
		(*error)++;
		return (1);
	}
	else if (i == 4)
	{
		printf("syntax error near unexpected token `<<'\n");
		(*error)++;
		return (1);
	}
	else if (i == 5)
	{
		printf("syntax error near unexpected token `>>'\n");
		(*error)++;
		return (1);
	}
	return (0);
}
