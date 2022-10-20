/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_big_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:01:45 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:52:31 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_b_l	*ft_lstlast4(t_b_l *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back4(t_b_l **lst, t_b_l *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast4(*lst)->next = new;
	new->next = NULL;
	return ;
}

void	ft_creat_big_list(t_b_l **b_l, t_p_l **p_l, t_r **red, int *i)
{
	t_b_l	*new;

	*i = 0;
	new = malloc(sizeof(t_b_l));
	if (!new)
		printf("error\n");
	new->arg = *p_l;
	new->red = *red;
	new->next = NULL;
	ft_lstadd_back4(b_l, new);
	*p_l = NULL;
	*red = NULL;
	return ;
}
