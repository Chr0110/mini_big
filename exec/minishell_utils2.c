/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:32:10 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/18 11:39:43 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, " ", 1);
	return ;
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	if (!((c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc((ft_strlen (s1) + ft_strlen (s2) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	else
		ft_strcpy (ptr, s1);
	ft_strcat (ptr, s2);
	return (ptr);
}
