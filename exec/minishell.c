/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:59:42 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/06 09:33:10 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char** av, char **env)
{
	char *buffer;
	char *ptr;
	int i = 0;
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	vars->pwd = ft_strdup("");
	vars->infile = malloc(sizeof(int)*100);
	vars->outfile = malloc(sizeof(int)*100);
	initial_env(vars, env);
	initial_exp(vars, env);
	ft_replace_shlvl(vars);
	ft_replace_oldpwd(vars);
	env_to_exp(vars);
	ft_replace(vars);
	ft_append(vars);
	while(1)
	{
		printf(YELLOW"minishell$> "NOR);
		ptr = readline(buffer);
		if(ft_strlen(ptr) != 0)
		{
			add_history(ptr);
			//ft_test(ptr, env);
			ft_pipe(ptr, vars);
			
			// ft_rediraction(ptr, vars, data);
		}
		else
			ft_putchar_fd('\n', 1);
		free(ptr);
			
	}
}