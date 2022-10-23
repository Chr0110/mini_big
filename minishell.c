/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:03:54 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/23 15:25:06 by sriyani          ###   ########.fr       */
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
	// signal(SIGQUIT,  sig_term);
	tgcatt();
}

void	free_big(t_b_l *big_list, t_p_l *tmp, t_b_l *btmp)
{
	t_r *rtmp;
	t_b_l *btmp1;
	int i;
	btmp = big_list;
	while(btmp)
	{	
		i = 0;
		while(btmp->arg)
		{
			tmp = btmp->arg;
			btmp->arg = btmp->arg->next;
			free(tmp->content.value);////check
			free(tmp);
			i++;
		}
		while(btmp->red)
		{
			rtmp = btmp->red;
			btmp->red = btmp->red->next;
			free(rtmp->content.value);
			free(rtmp);
		}
		// i = i - 1;
		// while(i-- > 0)
		// if (btmp->str[i])
		// 	free(btmp->str[i]);
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
	vars = malloc(sizeof(t_vars));
	data = malloc(sizeof(t_data));
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
		if(ft_strlen1(ptr) != 0)
		{
			add_history(ptr);
			big = ft_parsing(ptr, env, temp);
			ft_execution(big, data, vars);
			if (big)
				free_big(big, tmp, btmp);
		}
	}
	
	ft_free(vars->bar);
	ft_free(vars->env);
	ft_free(vars->exp);
	ft_free(vars->sar);
	ft_free(vars->mar);
	free(vars);
	free(data);
}
