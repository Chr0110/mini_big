/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_red_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:07:57 by eradi-            #+#    #+#             */
/*   Updated: 2022/09/30 06:08:19 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_r	*ft_lstlast3(t_r *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back3(t_r **lst, t_r *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast3(*lst)->next = new;
	new->next = NULL;
	return ;
}

void	ft_creat_red_lst(t_r **red_branch, t_token *token)
{
	t_r	*new;

	new = malloc(sizeof(t_r));
	if (!new)
		printf("error\n");
	new->content = *token;
	new->next = NULL;
	ft_lstadd_back3(red_branch, new);
	return ;
}
