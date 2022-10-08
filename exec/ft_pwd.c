/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:21:00 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/08 17:58:22 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
char *ft_getcwd(void)
{
	char str[1024];
	char *ptr;
	
	ptr = ft_strdup(getcwd(str, sizeof(str)));
	return (ptr);
}

void	ft_pwd(t_vars *vars)
{
	
	char *ptr;
	
	ptr = ft_getcwd();
	ft_putstr(ptr, 1);
	// free(ptr);
	write(vars->outfile[vars->index], "\n", 1);
}
