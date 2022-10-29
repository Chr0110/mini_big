/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:45:46 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/29 00:45:44 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	ft_putstr(YELLOW"minishell$> ", 2);
	ft_putstr(NOR"exit\n", 2);
	exit(1);
}

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
	//	rl_replace_line("", 1);
		rl_redisplay();
	}
	if (signum == SIGQUIT)
		rl_on_new_line();
}

void	tgcatt(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}

void	init_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	tgcatt();
}

void	ft_initial(t_vars *vars, char **env, int ac)
{
	(void) ac;
	ft_initial_exec(vars, env);
	init_signal();
}
