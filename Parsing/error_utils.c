/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:09:05 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/02 17:09:10 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_this_error(int *i, int *error)
{
	printf("syntax error near unexpected token `|'\n");
	(*i)++;
	(*error)++;
	return (1);
}

int	pip_error(t_list *temp, int *error)
{
	if (temp->content.e_type == 0 && temp->next == NULL)
	{
		printf("syntax error\n");
		(*error)++;
		return (1);
	}
	else if (temp->content.e_type == 0 && temp->next->content.e_type == 0)
	{
		printf("syntax error\n");
		(*error)++;
		return (1);
	}
	return (0);
}

int	heredoc_error(int i, int *error)
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

int	append_error(int i, int *error)
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
