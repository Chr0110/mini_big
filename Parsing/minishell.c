/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:17:34 by eradi-            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/05 13:00:02 by sriyani          ###   ########.fr       */
=======
/*   Updated: 2022/10/05 23:46:36 by eradi-           ###   ########.fr       */
>>>>>>> 16c3716e02b12a32be591a2e3859fd1e980eca2d
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
	t_b_l	**big_list;
	t_b_l	*temp;

	big_list = NULL;
	temp = NULL;
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
	}
	return (0);
}