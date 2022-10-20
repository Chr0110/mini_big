/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_that_mf_dollar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:00:13 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/20 09:00:48 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_value(char *s, char **env, int *cmp)
{
	int		i;
	int		j;
	int		n;
	char	*env_cmp;
	char	*res;

	get_param_values(&i, &n, &j);
	while (env[++i])
	{
		while (env[i][j] != '=')
			j++;
		env_cmp = ft_strdup("");
		while (n < j)
			env_cmp = ft_strjoin_one(env_cmp, env[i][n++]);
		if (ft_strncmp(env_cmp, s, ft_strlen(env[i])) == 0)
		{
			res = take_from_env(env, j, i);
			s = get_value2(&res, &env_cmp);
			break ;
		}
		else
			retry(&j, &env_cmp, &n);
	}
	*cmp = i;
	return (s);
}

char	*take_from_env(char **env, int j, int i)
{
	int		n;
	char	*res;

	j++;
	n = j;
	while (env[i][n])
		n++;
	n = n - j;
	res = malloc((n + 1) * sizeof(char));
	res[n] = '\0';
	n = 0;
	while (env[i][j])
		res[n++] = env[i][j++];
	return (res);
}

char	*expand_dollar_n_q(t_exp_list *list, char **env, int cmp1)
{
	int		v;
	char	*value;
	char	*value1;
	int		cmp;

	cmp = 0;
	v = list->i + 1;
	while (list->s[v] != '\'' && list->s[v] != ' '
		&& list->s[v] != '\"' && list->s[v] != '\0')
			v++;
	value = malloc(((v - (list->i)) + 1) * sizeof(char));
	v = 0;
	while (is_alpha(list->s[(list->i)]) == 1 || list->s[list->i] == '_')
		value[v++] = list->s[(list->i)++];
	value[v] = '\0';
	value1 = get_value(value, env, &cmp);
	free(value);
	if (cmp != cmp1)
	{
		v = -1;
		while (value1[++v])
			(list->res) = ft_strjoin_one((list->res), value1[v]);
		free(value1);
	}
	return ((list->res));
}

char	*expand_dollar_q(t_exp_list *list, char **env, int cmp1, int cmp)
{
	int		v;
	char	*value;
	char	*value1;

	cmp = 0;
	list->i = list->i + 1;
	v = list->i + 1;
	while (list->s[v] != '\'' && list->s[v] != ' '
		&& list->s[v] != '\"' && list->s[v] != '\0')
			v++;
	value = malloc(((v - (list->i)) + 1) * sizeof(char));
	v = 0;
	while (is_alpha(list->s[(list->i)]) == 1 || list->s[list->i] == '_')
		value[v++] = list->s[(list->i)++];
	value[v] = '\0';
	value1 = get_value(value, env, &cmp);
	free(value);
	if (cmp != cmp1)
	{
		v = -1;
		while (value1[++v])
			(list->res) = ft_strjoin_one((list->res), value1[v]);
		free(value1);
	}
	return ((list->res));
}
