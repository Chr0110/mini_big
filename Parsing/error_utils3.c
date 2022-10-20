/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 06:30:14 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:56:50 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_this_error(int *error)
{
	panic("syntax error", "|", "error in pip", 258);
	(*error)++;
	return (1);
}

int	pip_error(t_list *temp, int *error)
{
	if (temp->content.e_type == 0 && temp->next == NULL)
	{
		panic("syntax error", "|", "error in pip", 258);
		(*error)++;
		return (1);
	}
	else if (temp->content.e_type == 0 && temp->next->content.e_type == 0)
	{
		panic("syntax error", "|", "error in pip", 258);
		(*error)++;
		return (1);
	}
	return (0);
}

int	heredoc_error(int i, int *error)
{
	int	j;

	j = 0;
	if (i == 0)
		j = panic("syntax error", "|", "error in heredoc", 258);
	else if (i == 2)
		j = panic("syntax error", "<", "error in heredoc", 258);
	else if (i == 3)
		j = panic("syntax error", ">", "error in heredoc", 258);
	else if (i == 4)
		j = panic("syntax error", "<<", "error in heredoc", 258);
	else if (i == 5)
		j = panic("syntax error", "<<", "error in heredoc", 258);
	if (j == 1)
	{
		(*error)++;
		return (1);
	}
	return (0);
}

int	append_error(int i, int *error)
{
	int	j;

	j = 0;
	if (i == 0)
		j = panic("syntax error", "|", "error in append", 258);
	else if (i == 2)
		j = panic("syntax error", "<", "error in append", 258);
	else if (i == 3)
		j = panic("syntax error", ">", "error in append", 258);
	else if (i == 4)
		j = panic("syntax error", "<<", "error in append", 258);
	else if (i == 5)
		j = panic("syntax error", ">>", "error in append", 258);
	if (j == 1)
	{
		(*error)++;
		return (1);
	}
	return (0);
}
