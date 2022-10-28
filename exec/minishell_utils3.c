/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:33:51 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 15:26:33 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_lenght(int n)
{
	long	len;
	long	num;

	len = 0;
	num = n;
	if (n < 0)
	{
		num = num * (-1);
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_zero(char *p)
{
	p = NULL;
	p = ft_calloc(2, sizeof(char));
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	num;
	long int	len;

	ptr = NULL;
	len = ft_lenght(n);
	if (n == 0)
		return (ft_zero(ptr));
	ptr = ft_calloc ((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	num = n;
	if (n < 0)
	{
		ptr[0] = '-';
		num = num * (-1);
	}
	while (len-- > 0 && num > 0)
	{
		ptr[len] = num % 10 + '0';
		num = num / 10;
	}
	return (ptr);
}

void	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
