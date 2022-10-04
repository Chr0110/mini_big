/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:14:23 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/04 17:10:06 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_one(char *str, char c)
{
	char	*s;
	int		i;
	int		n;

	i = 0;
	n = 0;
	s = malloc(strlen(str) + 2);
	while (str[i])
		s[n++] = str[i++];
	s[n] = c;
	s[n + 1] = 0;
	free(str);
	return (s);
}

void	p_l_n_q_case(char **exp, int *i, t_p_l **ex_ls, char *s)
{
	t_token	*token;

	token = malloc(1 * sizeof(t_token));
	token->value = *exp;
	token->e_type = TOKEN_ARG;
	ft_creat_parse_lst(ex_ls, token);
	*exp = strdup("");
}

void	add_to_parse_list(char *s, t_p_l **expand_list)
{
	int		i;
	t_token	*token;
	char	*expand;

	*expand_list = NULL;
	expand = strdup("");
	token = malloc(1 * sizeof(t_token));
	i = 0;
	while(s[i])
	{
		if (s[i] == ' ')
		{
			i++;
			while (s[i] == ' ')
				i++;
		}
		while(s[i] != ' ' && s[i] != '\0')
			expand = ft_strjoin_one(expand, s[i++]);
		if (s[i] == ' ' || s[i] == '\0')
		{
			if (s[i] == '\0')
				p_l_n_q_case(&expand, &i, expand_list, s);
			else if (not_between_sd_quotes(s, i))
				p_l_n_q_case(&expand, &i, expand_list, s);
		}
		while(s[i] == ' ' && not_between_sd_quotes(s, i) == 0)
			expand = ft_strjoin_one(expand, s[i++]);
	}
}
