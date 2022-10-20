/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:09:38 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:56:14 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	red_in_error(t_list *temp, int *error)
{
	if (temp->next == NULL)
	{
		panic("syntax error", "newline", "error in redirection in", 258);
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
		panic("syntax error", "newline", "error in redirection out", 258);
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
		panic("syntax error", "newline", "error in heredoc", 258);
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
		panic("syntax error", "newline", "error in redirection append", 258);
		(*error)++;
		return (1);
	}
	else if (temp->next != NULL)
		if (append_error(temp->next->content.e_type, error) == 1)
			return (1);
	return (0);
}
