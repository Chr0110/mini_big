/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:28 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/06 23:33:52 by eradi-           ###   ########.fr       */
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
	t_b_l	*big_list;
	t_b_l	*temp;

	//*big_list = NULL;
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
		init_lexer(ptr, env, &big_list);
		while(big_list)
		{
			while (big_list->arg)
			{
				printf("%s\n", big_list->arg->content.value);
				big_list->arg = big_list->arg->next;
			}
			big_list = big_list->next;
		}
	}
	return (0);
}