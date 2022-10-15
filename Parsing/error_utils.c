/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:09:05 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/05 14:30:13 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	espace;

	espace = ' ';
	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &espace, 1);
}

int panic(char *name, char *arg, char *msg, int error)
{
	if (name)
		ft_putstr_fd(name, 2);
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(":", 2);
	}
	if (msg)
		ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	g_status = error;
	return (1);
}

int	print_this_error(int *i, int *error)
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
	if (i == 0)
	{
		panic("syntax error", "|", "error in redirecion in", 258);
		(*error)++;
		return (1);
	}
	else if (i == 2)
	{
		panic("syntax error", ">", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	else if (i == 3)
	{
		panic("syntax error", "<", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	else if (i == 4)
	{
		panic("syntax error", "<<", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	else if (i == 5)
	{
		panic("syntax error", "<<", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	return (0);
}

int	append_error(int i, int *error)
{
	if (i == 0)
	{
		panic("syntax error", "|", "error in redirecion in", 258);
		(*error)++;
		return (1);
	}
	else if (i == 2)
	{
		panic("syntax error", ">", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	else if (i == 3)
	{
		panic("syntax error", "<", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	else if (i == 4)
	{
		panic("syntax error", "<<", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	else if (i == 5)
	{
		panic("syntax error", ">>", "error in redirection", 258);
		(*error)++;
		return (1);
	}
	return (0);
}
