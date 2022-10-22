/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:41:47 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/22 08:06:34 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

t_b_l	*ft_parsing(char *ptr, char **env, t_b_l *big_list)
{
	big_list = NULL;
	init_lexer(ptr, env, &big_list);
	return (big_list);
}
