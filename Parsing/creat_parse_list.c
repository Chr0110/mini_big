/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_parse_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:06:26 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/07 17:15:14 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_p_l	*ft_lstlast2(t_p_l *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back2(t_p_l **lst, t_p_l *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast2(*lst)->next = new;
	new->next = NULL;
	return ;
}

void	ft_creat_parse_lst(t_p_l **parse_branch, t_token *token)
{
	t_p_l	*new;

	new = malloc(sizeof(t_p_l));
	if (!new)
		printf("error\n");
	new->content = *token;
	new->next = NULL;
	ft_lstadd_back2(parse_branch, new);
	return ;
}
