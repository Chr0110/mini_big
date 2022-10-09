/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:28 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/09 18:11:47 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


// void	sig_handler(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		printf("\nSIG HANDLE\n");
// 		// readline functions : rl_replaceline rl_newline rl_prompt
// 		// printf("\n");
// 		exit (EXIT_SUCCESS);
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
// 	}
// }
t_b_l *ft_parsing(char *ptr ,char **env, t_b_l *big_list)
{
	char *buffer;
	//char *ptr;
	//t_b_l	*big_list;
	//t_b_l	*temp;

	big_list = NULL;
	
	// signal(SIGQUIT, SIG_IGN);
	// signal(SIGINT, handler);
	// signal(SIGINT, sig_handler);
	// signal(SIGQUIT, SIG_IGN);
	//ptr = readline(GREEN"minishell$> "NOR);
	if (ptr == 0x0)
		exit(EXIT_SUCCESS);
	// add_history(ptr);
	init_lexer(ptr, env, &big_list);
	
	return(big_list);
}