/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:09:55 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 08:58:05 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*handle_dollar_double_quotes(char *s, int *i, char **env)
{
	int		v;
	char	*value;
	char	*res;
	int		cmp;

	cmp = 0;
	res = strdup("");
	v = *i;
	while (s[v] != '\'' && s[v] != ' ' && s[v] != '\"' && s[v] != '\0')
		v++;
	value = malloc(((v - (*i)) + 1) * sizeof(char));
	v = 0;
	while (is_alpha(s[(*i)]) == 1 || s[*i] == '_')
		value[v++] = s[(*i)++];
	value[v] = '\0';
	get_value(value, env, &cmp);
	v = -1;
	while (value[++v])
		res = ft_strjoin_one(res, value[v]);
	return (res);
}

char	*handle_dollar_no_quotes(char *s, int *i, char **env)
{
	int		v;
	char	*value;
	char	*res;
	int		cmp;

	cmp = 0;
	v = 0;
	while (s[v] != '\'' && s[v] != ' ' && s[v] != '\"' && s[v] != '\0')
		v++;
	value = malloc((v + 1) * sizeof(char));
	v = 0;
	while ((is_alpha(s[(*i)]) == 1) || s[*i] == '_')
		value[v++] = s[(*i)++];
	value[v] = '\0';
	get_value(value, env, &cmp);
	v = 0;
	v = -1;
	while (value[++v])
		res = ft_strjoin_one(res, value[v]);
	return (res);
}

int	ft_lstsize(t_p_l *lst)
{
	t_p_l	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	is_alpha(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90) || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
