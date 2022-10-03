/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:09:38 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/02 17:09:20 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	red_in_error(t_list *temp, int *error)
{
	if (temp->next == NULL)
	{
		printf("syntax error near unexpected token `newline'\n");
		(*error)++;
		return (1);
	}
	else if (temp->next != NULL)
		if (r_i_error(temp->next->content.e_type, error) == 1)
			return (1);
	return (0);
}

int	red_out_error(t_list *temp, int *error)
{
	if (temp->next == NULL)
	{
		printf("syntax error near unexpected token `newline'\n");
		(*error)++;
		return (1);
	}
	else if (temp->next != NULL)
		if (r_o_error(temp->next->content.e_type, error) == 1)
			return (1);
	return (0);
}

int	here_error(t_list *temp, int *error)
{
	if (temp->next == NULL)
	{
		printf("syntax error near unexpected token `newline'\n");
		(*error)++;
		return (1);
	}
	else if (temp->next != NULL)
		if (heredoc_error(temp->next->content.e_type, error) == 1)
			return (1);
	return (0);
}

int	app_error(t_list *temp, int *error)
{
	if (temp->next == NULL)
	{
		printf("syntax error near unexpected token `newline'\n");
		(*error)++;
		return (1);
	}
	else if (temp->next != NULL)
		if (append_error(temp->next->content.e_type, error) == 1)
			return (1);
	return (0);
}
