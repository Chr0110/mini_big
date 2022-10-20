/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_red_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:07:57 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:53:23 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	int	j;
	int	i;

	new = malloc(sizeof(t_r));
	if (!new)
		printf("error\n");
	i = ft_strlen(token->value);
	j = 0;
	new->content.value = malloc((i + 1) * sizeof(char *));
	new->content.value[i] = '\0';
	while (j < i)
	{
		new->content.value[j] = token->value[j];
		j++;
	}
	new->content.e_type = token->e_type;
	new->next = NULL;
	ft_lstadd_back3(red_branch, new);
	return ;
}
