/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:21:00 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/23 13:20:39 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getcwd(t_vars *vars)
{
	char	str[SIZE_ALL];
	char	*ptr;

	if (!getcwd(str, sizeof(str)))
		ptr = ft_strdup(vars->pwd);
	else
		ptr = ft_strdup(getcwd(str, sizeof(str)));
	return (ptr);
}

int	ft_pwd(t_vars *vars)
{
	char	*ptr;

	ptr = ft_getcwd(vars);
	ft_putstr(ptr, vars->outfile[vars->index]);
	free(ptr);
	write(vars->outfile[vars->index], "\n", 1);
	return (0);
}
