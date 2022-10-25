/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:03:54 by sriyani           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/25 21:33:18 by eradi-           ###   ########.fr       */
=======
/*   Updated: 2022/10/25 15:27:15 by sriyani          ###   ########.fr       */
>>>>>>> 7e7dba743a2ed6c013b8500cfaa15b74103d4c5f
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    sig_handler(int signum)
{
    if (signum == SIGINT)
    {
        ft_putchar_fd('\n', 1);
        rl_on_new_line();
       rl_replace_line("", 1);
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
	signal(SIGQUIT,  sig_term);
	tgcatt();
}

void	free_big(t_b_l *big_list, t_p_l *tmp, t_b_l *btmp)
{
	t_r		*rtmp;
	t_b_l	*btmp1;

	btmp = big_list;
	while(btmp)
	{	
		while(btmp->arg)
		{
			tmp = btmp->arg;
			btmp->arg = btmp->arg->next;
<<<<<<< HEAD
			free(tmp->content.value);
=======
			free(tmp->content.value);////check
>>>>>>> 7e7dba743a2ed6c013b8500cfaa15b74103d4c5f
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
		free(btmp1);
	}
	free(btmp);
}

int main(int ac, char **av, char  **env)
{
	char *ptr;
	t_vars *vars;
	t_b_l *big;
	t_b_l *temp;
	t_data *data;
	t_p_l	*tmp;
	t_b_l	*btmp;

	av = NULL;
	ac = 0;
	temp = NULL;
	tmp = NULL;
	btmp = NULL;
	vars = ft_calloc(sizeof(t_vars) , 1);
	data = ft_calloc(sizeof(t_data) , 1);
	ft_initial_exec(vars, env);
	init_signal();
	while(1)
	{
		ptr = readline(YELLOW"minishell$> "NOR);

		init_signal();
		if (!ptr)
		{
			ft_putstr(YELLOW"minishell$> ", 2);
			ft_putstr(NOR"exit\n", 2);
			exit(1);
		}
		else if (!ft_strlen1(ptr))
			free(ptr);
		else if(ft_strlen1(ptr) != 0)
		{
			add_history(ptr);
<<<<<<< HEAD
			big = ft_parsing(ptr, env, temp);
=======
			big = ft_parsing(ptr, vars->env, temp);
			ptr = NULL;
>>>>>>> 7e7dba743a2ed6c013b8500cfaa15b74103d4c5f
			ft_execution(big, data, vars);
			if (big)
			{
				free_big(big, tmp, btmp);
<<<<<<< HEAD
				big = NULL;
			}
=======
			if(vars->n_mar)
				ft_free(vars->mar);
			vars->mar = NULL;
			if(vars->n_sar )
				ft_free(vars->sar);
			vars->sar = NULL;
>>>>>>> 7e7dba743a2ed6c013b8500cfaa15b74103d4c5f
		}
		// system("leaks minishell");
	}
	
<<<<<<< HEAD
=======
	
	
>>>>>>> 7e7dba743a2ed6c013b8500cfaa15b74103d4c5f
}
