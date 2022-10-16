/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:09:03 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/16 20:46:35 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	red_creat(t_list *s_b, t_token *token, t_r **red)
{
	int l = ft_strlen(s_b->next->content.value);
	int j = 0;

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
		while(j < l)
		{
			token->value[j] = s_b->next->content.value[j];
			j++;
		}
	}
	ft_creat_red_lst(red, token);
	free(token->value);
}

void	creat_cmd(t_list *s_b, t_token *token, t_p_l **parse_branch, int *i)
{
	int l = ft_strlen(s_b->content.value);
	int j = 0;
	token->value = malloc(sizeof(char) * (l + 1));
	token->value[l] = '\0';
	while(j < l)
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
	int l = ft_strlen(s_b->content.value);
	int j = 0;
	token->value = malloc(sizeof(char) * (l + 1));
	token->value[l] = '\0';
	while(j < l)
	{
		token->value[j] = s_b->content.value[j];
		j++;
	}
	token->e_type = TOKEN_ARG;
	ft_creat_parse_lst(parse_branch, token);
	free(token->value);
}
