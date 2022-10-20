/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:05:26 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:52:51 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(token->value);
	new = malloc(sizeof(t_p_l));
	new->content.value = malloc((i + 1) * sizeof(char *));
	new->content.value[i] = '\0';
	if (!new)
		printf("error\n");
	while (j < i)
	{
		new->content.value[j] = token->value[j];
		j++;
	}
	new->content.e_type = token->e_type;
	new->next = NULL;
	ft_lstadd_back(small_branch, new);
}
