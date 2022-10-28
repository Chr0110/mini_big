/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:44:09 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 21:43:25 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_number(char **bar)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (bar[i])
	{
		j = 0;
		while (bar[i][j])
		{
			if (ft_isdigit(bar[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	next_exit(char **bar)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (bar[i])
	{
		if (strcmp(bar[i], "exit") == 0)
		{
			while (bar[i + 1][j])
			{
				if (!ft_isdigit(bar[i + 1][j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	ft_exit(char **bar)
{
	int	i;

	i = 0;
	while (bar[i])
		++i;
	if (i == 1)
		print_exit();
	else if (i == 2 && check_number(bar) == 1)
		print_num(bar[1]);
	else if (next_exit(bar) == 0)
	{
		ft_putstr("exit\nexit: ", 2);
		ft_putstr(bar[i - 1], 2);
		ft_putstr(": numeric argument required\n", 2);
		exit(255);
	}
	else
	{
		ft_putstr("exit: too many arguments\n", 2);
		return (1);
	}
	return (0);
}

void	print_num(char *bar)
{
	if (ft_strlen(bar) > 20)
	{
		ft_putstr("exit\nexit: ", 1);
		ft_putstr(bar, 1);
		ft_putstr(" : numeric argument required\n", 2);
		exit(255);
	}
	else
	{
		ft_putstr("exit\n", 1);
		exit(ft_atoi(bar) % 256);
	}	
}

void	print_exit(void)
{
	ft_putstr("exit\n", 1);
	exit(g_status);
}
