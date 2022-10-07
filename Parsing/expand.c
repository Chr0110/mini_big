/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:00:11 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/07 17:20:57 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pip_number(t_b_l *big)
{
	int j;
	j = 0;
	while(big)
	{
		big = big->next;
		if (big != NULL)
			j++;
	}
	return(j);
}
int	arg_len(t_b_l *big)
{
	int	i;
	int	j;

	i = 0;
	t_b_l	*temp;
	temp = big;
	while(temp)
	{
		t_p_l *arg = temp->arg;
		while(arg)
		{
			j = ft_strlen1(arg->content.value);
			i = i + j;
			arg = arg->next;
		}
		temp = temp->next;
	}
	return (i);
}
char	*creat_the_string(t_b_l *big)
{
	int	i;
	i = 0;
	int j;
	j = 0;
	char *s;
	i = arg_len(big);
	j = pip_number(big);
	s = malloc((i + j + 1) * sizeof(char));
	s[i + j] = '\0';
	j = 0;
	i = 0;
	t_b_l	*temp;
	temp = big;
	while(temp)
	{
		t_p_l *arg = temp->arg;
		while(arg)
		{
			while(arg->content.value[j])
			{
				s[i] = arg->content.value[j];
				i++;
				j++;
			}
			arg = arg->next;
			if (arg != NULL)
			{
				s[i] = ' ';
				i++;
			}
			j = 0;
		}
		temp = temp->next;
		if (temp != NULL)
		{
			s[i] = '|';
			i++;
		}
	}
	return (s);
}

void	expand(t_b_l **big_list, char **env)
{
	t_b_l	*temp_big;
	t_r		*temp_red;
	int		i;
	char *s;

	temp_big = *big_list;
	exp_creat_list(temp_big, env);
	remove_f_quotes(temp_big);
}
