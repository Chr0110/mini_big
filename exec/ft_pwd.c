/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:21:00 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/24 21:41:37 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getcwd(t_vars *vars)
{
	char	*ptr;

	ptr = ft_strdup(getcwd(NULL, 0));
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
