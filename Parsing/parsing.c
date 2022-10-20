/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:41:47 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/20 10:41:53 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

t_b_l	*ft_parsing(char *ptr, char **env, t_b_l *big_list)
{
	char	*ptr;
	t_b_l	*big_list;

	big_list = NULL;
	if (ptr == 0x0)
		exit(EXIT_SUCCESS);
	init_lexer(ptr, env, &big_list);
	return (big_list);
}
