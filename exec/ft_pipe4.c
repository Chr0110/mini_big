/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:52:30 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/27 16:58:33 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	kill_pro(pid_t *child_pro, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		kill(child_pro[i], SIGKILL);
		i++;
	}
}

void	check_lil_str(char **str)
{
	if (str)
		ft_free(str);
	str = NULL;
}
