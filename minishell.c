/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:03:54 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/08 15:49:20 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av, char  **env)
{
	char *buffer;
	char *ptr;
	t_vars *vars;
	t_b_l *big;
	t_b_l *temp;

	vars = malloc(sizeof(t_vars));
	ft_initial_exec(vars, env);
	while(1)
	{
		ptr = readline(YELLOW"minishell$> "NOR);
		if(ft_strlen1(ptr) != 0)
		{
			add_history(ptr);
			big = ft_parsing(ptr, vars->env, temp);
			ft_execution(big,vars,ptr);
		}
		// else
		// 	ft_putchar_fd('\n', 1);
		free(ptr);
			
	}
}
