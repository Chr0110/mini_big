/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:05:26 by eradi-            #+#    #+#             */
/*   Updated: 2022/09/30 06:05:52 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
	new->next = NULL;
	return ;
}

void	ft_creatlst(t_list **small_branch, t_token *token)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		printf("error\n");
	new->content = *token;
	new->next = NULL;
	ft_lstadd_back(small_branch, new);
	return ;
}
