/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:03:54 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/15 22:51:02 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    sig_handler(int signum)
{
    if (signum == SIGINT)
    {
        ft_putchar_fd('\n', 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();	
    }
	if (signum == SIGQUIT)
        rl_on_new_line();
}


void	tgcatt(void)
{
	struct termios term;

	 tcgetattr(0, &term);
   	 term.c_lflag &= ~ECHOCTL;
   	 tcsetattr(0, TCSANOW, &term);
    
}


void init_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	// signal(SIGQUIT,  sig_term);
	tgcatt();
}


int main(int ac, char **av, char  **env)
{
	char *buffer;
	char *ptr;
	t_vars *vars;
	t_b_l *big;
	t_b_l *temp;
	t_data *data;

	vars = malloc(sizeof(t_vars));
	data = malloc(sizeof(t_data));
	ft_initial_exec(vars, env);
	data->id = 0;
	init_signal();
	while(1)
	{
		g_var[1] = 0;
		ptr = readline(YELLOW"minishell$> "NOR);
		init_signal();
		if (!ptr)
		{
			ft_putstr(YELLOW"minishell$> ", 2);
			ft_putstr(NOR"exit\n", 2);
			exit(1);
		}
		if(ft_strlen1(ptr) != 0)
		{
			add_history(ptr);
			big = ft_parsing(ptr, env, temp);
			//ft_execution(big,vars,ptr);
		}
		free(ptr);
		if (big)
		{
			t_b_l *btmp = big;
			t_b_l *btmp1;
			t_p_l *tmp;
			t_r *rtmp;
			while(btmp)
			{
				while(btmp->arg)
				{
					tmp = btmp->arg;
					btmp->arg = btmp->arg->next;
					free(tmp->content.value);
					free(tmp);
				}
				while(btmp->red)
				{
					rtmp = btmp->red;
					btmp->red = btmp->red->next;
					free(rtmp->content.value);
					free(rtmp);
				}
				btmp1 = btmp;
				btmp = btmp->next;
				printf("m here\n");
				free(btmp1);
			}
			free(btmp);
		}
	}
	
}
