/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_parse_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 06:06:26 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:53:08 by eradi-           ###   ########.fr       */
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
	ft_lstadd_back2(parse_branch, new);
	return ;
}
