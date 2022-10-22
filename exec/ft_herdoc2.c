/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_herdoc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:07:07 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 07:50:34 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_herdoc(t_vars *vars, char *dil, t_data *data)
{
	char	*str;

	data->har = ft_strdup("");
	while (1)
	{
		str = readline("> ");
		if (!str || ft_strcmp(str, dil) == 0)
		{
			data->p[1] = open(data->name, O_TRUNC | O_WRONLY | O_CREAT, 0644);
			ft_putstr(data->har, data->p[1]);
			close(data->p[1]);
			exit(0);
		}
		if (str)
			ft_herdoc2(vars, str, data);
		free(str);
	}
}

void	ft_herdoc2(t_vars *vars, char *str, t_data *data)
{
	char	*tmp;

	tmp = NULL;
	tmp = data->har;
	if (ft_strchr(str, '$') == 0)
		str = ft_expand(vars, str);
	data->har = ft_strjoin(data->har, str);
	free(tmp);
	tmp = data->har;
	data->har = ft_strjoin(data->har, "\n");
	free(tmp);
}

void	sig_han(int signum)
{
	if (signum == SIGINT)
		exit(1);
}