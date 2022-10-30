/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:25:30 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/30 03:26:38 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	global_error(t_list *temp, int *error)
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
	t_list	*t;
	t_list	*tmp1;

	free(lx->text[lx->tx]);
	free_lexer(&lx);
	tmp1 = small_branch;
	while (tmp1)
	{
		t = tmp1->next;
		free(tmp1->content.value);
		free(tmp1);
		tmp1 = t;
	}
}

void	check_errors(t_list *s_b, char **env, t_b_l **big_branch, t_lx *lx)
{
	int		i;
	int		error;
	t_list	*temp;

	i = 0;
	error = 0;
	temp = s_b;
	while (temp)
	{
		if (i == 0 && temp->content.e_type == 0 && print_this_error(&error))
			break ;
		else if (global_error(temp, &error))
			break ;
		else
			i++;
		temp = temp->next;
	}
	if (error == 0)
		parsing(s_b, env, big_branch, lx);
	else
	{
		free_for_error(lx, s_b);
		*big_branch = NULL;
	}
}
