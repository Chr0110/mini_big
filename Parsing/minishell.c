/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:28 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/15 23:18:59 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	free_big(t_b_l *big_list, t_p_l *tmp, t_b_l *btmp)
{
	t_r *rtmp;
	t_b_l *btmp1;

	btmp = big_list;
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
		free(btmp1);
	}
	free(btmp);
}

int main (int ac, char **av,char **env)
{
	char	*buffer;
	char	*ptr;
	t_b_l	*big_list;
	t_p_l	*tmp;
	t_b_l	*btmp;

	big_list = NULL;
	while(1)
	{
		ptr = readline(GREEN"minishell$> "NOR);
		if (ptr == 0x0)
			exit(EXIT_SUCCESS);
		add_history(ptr);
		init_lexer(ptr, env, &big_list);
		t_b_l *btmp2 = big_list;
		while(btmp2)
		{
			t_p_l *tmp = btmp2->arg;
			t_r *rtmp = btmp2->red;
			while(tmp)
			{
				printf("%s\n", tmp->content.value);
				tmp = tmp->next;
			}
			while(rtmp)
			{
				printf("%s\n", rtmp->content.value);
				rtmp = rtmp->next;
			}
			btmp2 = btmp2->next;
		}
		if (big_list)
			free_big(big_list, tmp, btmp);
	}
	return (0);
}
