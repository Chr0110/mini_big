/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:25:30 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/16 05:54:55 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	global_error(t_list *temp, int *error, int *i)
{
	if (pip_error(temp, error) == 1)
		return (1);
	else if (temp->content.e_type == 2 && red_in_error(temp, error) == 1)
		return (1);
	else if (temp->content.e_type == 3 && red_out_error(temp, error) == 1)
		return (1);
	else if (temp->content.e_type == 4 && here_error(temp, error) == 1)
		return (1);
	else if (temp->content.e_type == 5 && app_error(temp, error) == 1)
		return (1);
	return (0);
}

void	free_for_error(t_lx *lx, t_list *small_branch)
{
	free_lexer(&lx);
	t_list *t;
	t_list *tmp1 = small_branch;
	while(tmp1)
	{
		t = tmp1->next;
		free(tmp1->content.value);
		free(tmp1);
		tmp1 = t;
	}
}

void	check_errors(t_list *small_branch, char **env, t_b_l **big_branch, t_lx *lx)
{
	int		i;
	int		error;
	t_list	*temp;

	i = 0;
	error = 0;
	temp = small_branch;
	while (temp)
	{
		if (i == 0 && temp->content.e_type == 0 && print_this_error(&i, &error))
			break ;
		else if (global_error(temp, &error, &i))
			break ;
		else
			i++;
		temp = temp->next;
	}
	if (error == 0)
		parsing(small_branch, env, big_branch, lx);
	else
	{
		free_for_error(lx, small_branch);
		*big_branch = NULL;
	}
}
