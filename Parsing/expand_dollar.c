/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:10:23 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/07 17:15:14 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	go_print_error(char **env)
// {
// 	char	*ptr;

// 	printf("ambiguous redirect\n");
// 	while (1)
// 	{
// 		ptr = readline(GREEN"minishell$> "NOR);
// 		if (ptr == 0)
// 			exit(EXIT_SUCCESS);
// 		add_history(ptr);
// 		init_lexer(ptr, env);
// 		free(ptr);
// 	}
// }

void	expand_dollar(t_token *cont, char **env, int type, t_p_l **exp_list)
{
	t_exp_list	*ex_ls;
	
	ex_ls = malloc(1 * sizeof(t_exp_list));
	ex_ls->res = strdup("");
	ex_ls->i = 0;
	ex_ls->s = cont->value;
	*exp_list = NULL;
	while (ex_ls->s[ex_ls->i])
	{
		if (ex_ls->s[ex_ls->i] == 34)
			ex_ls->res = d_q_r(ex_ls, env, type);
		else if (ex_ls->s[ex_ls->i] == 39)
			ex_ls->res = s_q_r(&ex_ls->res, ex_ls->s, &(ex_ls->i), &type);
		else
			ex_ls->res = n_q_r(ex_ls, env, type);
	}
	if (there_is_a_space(ex_ls->res))
	{
		// if (type == 3 || type == 2 || type == 5)
			// go_print_error(env, );
			add_to_parse_list(ex_ls->res, exp_list);
	}
	else
		cont->value = ex_ls->res;
}
