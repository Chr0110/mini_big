/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_that_mf_dollar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:00:13 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/02 20:04:25 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_value(char **s, char **env, int *cmp)
{
	int		i;
	int		j;
	int		n;
	char	*env_cmp;
	char	*res;

	i = -1;
	j = -1;
	n = 0;
	while (env[++i])
	{
		while (env[i][++j] != '=')
		env_cmp = strdup("");
		while (n < j)
			env_cmp = ft_strjoin_one(env_cmp, env[i][n++]);
		n = 0;
		if (ft_strncmp(env_cmp, *s, strlen(env[i])) == 0)
		{
			*s = take_from_env(env, j, i);
			break ;
		}
		else
			j = 0;
	}
	*cmp = i;
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

char	*frg3_dik_dollar_n_d_q(t_exp_list *ex_ls, char **env, int cmp1)
{
	int		v;
	char	*value;
	int		cmp;

	cmp = 0;
	v = ex_ls->i + 1;
	while (ex_ls->s[v] != '\'' && ex_ls->s[v] != ' '
		&& ex_ls->s[v] != '\"' && ex_ls->s[v] != '\0')
			v++;
	value = malloc(((v - (ex_ls->i)) + 1) * sizeof(char));
	v = 0;
	while (is_alpha(ex_ls->s[(ex_ls->i)]) == 1 || ex_ls->s[ex_ls->i] == '_')
	value[v++] = ex_ls->s[(ex_ls->i)++];
	value[v] = '\0';
	get_value(&value, env, &cmp);
	if (cmp != cmp1)
	{
		v = -1;
		while (value[++v])
			(ex_ls->res) = ft_strjoin_one((ex_ls->res), value[v]);
	}
	return ((ex_ls->res));
}

char	*frg3_dik_dollar_d_q(t_exp_list *ex_ls, char **env, int cmp1)
{
	int		v;
	char	*value;
	int		cmp;

	cmp = 0;
	ex_ls->i = ex_ls->i + 1;
	v = ex_ls->i + 1;
	while (ex_ls->s[v] != '\'' && ex_ls->s[v] != ' '
		&& ex_ls->s[v] != '\"' && ex_ls->s[v] != '\0' && ex_ls->s[v] != '$')
			v++;
	value = malloc(((v - (ex_ls->i)) + 1) * sizeof(char));
	v = 0;
	while (is_alpha(ex_ls->s[(ex_ls->i)]) == 1 || ex_ls->s[ex_ls->i] == '_')
		value[v++] = ex_ls->s[(ex_ls->i)++];
	value[v] = '\0';
	get_value(&value, env, &cmp);
	if (cmp != cmp1)
	{
		v = -1;
		while (value[++v])
			(ex_ls->res) = ft_strjoin_one((ex_ls->res), value[v]);
	}
	return (ex_ls->res);
}
