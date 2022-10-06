/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:17:34 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/05 13:00:02 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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
int main (int ac, char **av,char **env)
{
	char *buffer;
	char *ptr;
	while(1)
	{
		// signal(SIGQUIT, SIG_IGN);
		// signal(SIGINT, handler);
		ptr = readline(GREEN"minishell$> "NOR);
		// signal(SIGINT, sig_handler);
		// signal(SIGQUIT, SIG_IGN);
		if (ptr == 0x0)
			exit(EXIT_SUCCESS);
		add_history(ptr);
		init_lexer(ptr, env);
		free(ptr);
	}
	return (0);
}