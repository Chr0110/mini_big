/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:09:05 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:56:05 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	panic(char *name, char *arg, char *msg, int error)
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
