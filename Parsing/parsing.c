/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:41:47 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/28 01:56:09 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_b_l	*ft_parsing(char *ptr, char **env, t_b_l *big_list)
{
	big_list = NULL;
	init_lexer(ptr, env, &big_list);
	return (big_list);
}
