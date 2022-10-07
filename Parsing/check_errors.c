/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:25:30 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/07 17:15:14 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	check_errors(t_list *small_branch, t_token *token, char **env, t_b_l **big_branch)
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
		parsing(small_branch, token, env, big_branch);
}
