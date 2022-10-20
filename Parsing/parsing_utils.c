/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:09:03 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 09:04:35 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	red_creat(t_list *s_b, t_token *token, t_r **red)
{
	int	l;
	int	j;

	l = ft_strlen(s_b->next->content.value);
	j = -1;
	if (s_b->content.e_type == 2)
		token->e_type = 2;
	else if (s_b->content.e_type == 3)
		token->e_type = 3;
	else if (s_b->content.e_type == 4)
		token->e_type = 4;
	else if (s_b->content.e_type == 5)
		token->e_type = 5;
	if (s_b->next)
	{
		token->value = malloc(sizeof(char) * (l + 1));
		token->value[l] = '\0';
		while (++j < l)
			token->value[j] = s_b->next->content.value[j];
	}
	ft_creat_red_lst(red, token);
	free(token->value);
}

void	creat_cmd(t_list *s_b, t_token *token, t_p_l **parse_branch, int *i)
{
	int	l;
	int	j;

	l = ft_strlen(s_b->content.value);
	j = 0;
	token->value = malloc(sizeof(char) * (l + 1));
	token->value[l] = '\0';
	while (j < l)
	{
		token->value[j] = s_b->content.value[j];
		j++;
	}
	token->e_type = TOKEN_COMMD;
	ft_creat_parse_lst(parse_branch, token);
	free(token->value);
	(*i)++;
}

void	creat_arg(t_list *s_b, t_token *token, t_p_l **parse_branch)
{
	int	l;
	int	j;

	l = ft_strlen(s_b->content.value);
	j = 0;
	token->value = malloc(sizeof(char) * (l + 1));
	token->value[l] = '\0';
	while (j < l)
	{
		token->value[j] = s_b->content.value[j];
		j++;
	}
	token->e_type = TOKEN_ARG;
	ft_creat_parse_lst(parse_branch, token);
	free(token->value);
}
