/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:03:11 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/30 04:40:23 by eradi-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define CYAN     "\x1b[36m"
# define NOR      "\x1B[37m"

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "exec/exec.h"

int	g_status;

typedef struct s_token
{
	char	*value;
	enum
	{
		TOKEN_PIP,
		TOKEN_TEXT,
		TOKEN_REDIRECTION_IN,
		TOKEN_REDIRECTION_OUT,
		TOKEN_HERDOC,
		TOKEN_APPEND,
		TOKEN_DOLLAR,
		TOKEN_COMMD,
		TOKEN_ARG,
	} e_type;
}	t_token;

typedef struct s_lx
{
	int		tx;
	int		red_i;
	int		red_o;
	int		pi;
	int		her;
	int		app;
	char	c;
	int		t_sz;
	char	*str;
	int		j;
	int		i;
	int		error;
	int		t;
	int		r_i;
	int		r_o;
	int		p;
	int		h;
	int		a;
	int		s;
	char	**text;
	char	**pip;
	char	**redirection_in;
	char	**redirection_out;
	char	**append;
	char	**heredoc;
	t_token	*token;
}	t_lx;

typedef struct s_list
{	
	t_token			content;
	struct s_list	*next;
}	t_list;

typedef struct s_r
{
	t_token		content;
	struct s_r	*next;
}	t_r;

typedef struct s_p_l
{
	t_token			content;
	struct s_p_l	*next;
}	t_p_l;

typedef struct s_b_l
{
	char			**str;
	t_p_l			*arg;
	t_r				*red;
	struct s_b_l	*next;
}	t_b_l;

typedef struct s_exp_list
{
	char	*s;
	int		i;
	char	*res;
}	t_exp_list;

typedef struct s_for_exp
{
	t_p_l	*prev_arg;
	t_p_l	*current_arg_next;
	t_p_l	*tmp_ex_ls_last;
	t_p_l	*current_arg;
	t_r		*current_red;
}	t_for_exp;

typedef struct s_get_value
{
	int		i;
	int		j;
	int		n;
	char	*env_cmp;
	char	*res;
}	t_get_value;

void	free_big(t_b_l *big_list, t_p_l *tmp, t_b_l *btmp);
void	free2d(char **ptr);
int		find_dollar(char *s);
char	*ft_itoa(int n);
void	free_lexer(t_lx **lexer);
void	init_lexer(char *src, char **env, t_b_l **big_list);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_p_l *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_creatlst(t_list **stack, t_token *token);
void	parsing(t_list *small_branch, char **env, t_b_l **big_list, t_lx *lx);
void	check_errors(t_list *s_b, char **env, t_b_l **big_list, t_lx *lx);
void	expand(t_b_l **big_list, char **env);
void	ft_creat_parse_lst(t_p_l **parse_branch, t_token *token);
void	ft_creat_red_lst(t_r **red_branch, t_token *token);
void	ft_creat_big_list(t_b_l **b_l, t_p_l **p_l, t_r **r, int *i);
int		ft_strncmp(const char *src1, const char *src2, size_t n);
char	*take_from_env(char **env, int j, int i);
int		there_is_a_space(char *str);
char	*get_value(char *s, char **env, int *cmp);
char	*get_value2(char **res, char **env_cmp);
void	get_param_values(int *i, int *n, int *j);
void	retry(int *j, char **env_cmp, int *n);
void	check_export5_2(char **bar, t_vars *vars, int i);
char	*ft_strjoin_one(char *str, char c);
char	*handle_dollar_double_quotes(char *s, int *i, char **env);
char	**find_path(char **env);
char	*handle_dollar_no_quotes(char *s, int *i, char **env);
char	*expand_dollar_q(t_exp_list *ex_ls, char **env, int cmp1, int cmp);
char	*expand_dollar_n_q(t_exp_list *ex_ls, char **env, int cmp1);
char	*handle_dollar_no_quotes1(char *s, int *i, char **env, int cmp1);
void	add_to_parse_list(char *str, t_p_l **expand_list);
void	expand_quotes(t_token *ar_cnt, char **env, int type, t_p_l **ex_ls);
void	expand_dollar(t_token *cnt, char **env, int type, t_p_l **ex_ls);
int		is_alpha(char c);
int		panic(char *name, char *arg, char *msg, int error);
void	ft_putstr_fd(char *s, int fd);
int		lent(char **ptr);
void	kill_pro(pid_t *child_pro, int len);
void	check_lil_str(char **str);
void	make_list(t_p_l **curr, t_p_l *prev, t_p_l *x_ls);
int		find_dollar(char *s);
int		there_is_a_dollar(char *s);
int		not_b_q(char *s, int i);
char	*make_s_q_res(char **res, char *s, int *i, int *type);
char	*make_d_q_res(t_exp_list *ex_ls, char **env, int type);
char	*make_n_q_res(t_exp_list *ex_ls, char **env, int type);
char	*dollar_cases2(char **res, char *s, int *i, int j);
char	*dollar_cases(char **res, char *s, int *i, int j);
char	*skip_white_spaces(char *src);
int		still_a_quote(t_lx *lexer, int i);
int		number_of_s_quotes(t_lx *lexer);
int		number_of_quotes(t_lx *lexer);
void	make_list(t_p_l **curr, t_p_l *t_a_prev, t_p_l *x_ls);
void	exp_creat_list(t_b_l *t_big, char **env, t_p_l *ex_ls, t_b_l *tmp_big);
void	remove_s_a(char **res, int *i, char *s);
void	remove_d_a(char **res, int *i, char *s);
void	remove_quotes(t_token *node);
void	remove_f_quotes(t_b_l *t_b2);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_creatlst(t_list **small_branch, t_token *token);
t_p_l	*ft_lstlast2(t_p_l *lst);
void	ft_lstadd_back2(t_p_l **lst, t_p_l *new);
void	ft_creat_parse_lst(t_p_l **parse_branch, t_token *token);
t_r		*ft_lstlast3(t_r *lst);
void	ft_lstadd_back3(t_r **lst, t_r *new);
void	ft_creat_red_lst(t_r **red_branch, t_token *token);
t_b_l	*ft_lstlast4(t_b_l *lst);
void	ft_lstadd_back4(t_b_l **lst, t_b_l *new);
char	*ft_strdup(char *s1);
int		ft_strlen1(char *s);
void	lexer_init(t_lx	*lexer);
int		size_env(t_vars *vars);
int		size_exp(t_vars *vars);
int		not_b_s_q(char *s, int i);
void	red_in_lexer(t_lx *lx, int *j, t_token *tk, t_list **s_b);
void	red_out_lx(t_lx *lexer, int *j, t_token *token, t_list **small_branch);
void	heredoc_lexer(t_lx *lexer, int *j, t_token *token, t_list **s_b);
int		d_q_with_error(t_lx *lexer, int *j, t_token *token);
int		d_q_lexer(t_lx *lexer, int *j, t_token *token);
int		s_q_lexer(t_lx *lexer, int *j, t_token *token);
void	lexer_q_cases(t_lx *lx, int *j, t_token *token, t_list **small_branch);
void	ft_ft_creat_list(t_lx *lexer, int *j, t_token *token, t_list **s_b);
void	ft_creat_normal_text(t_lx *lx, int *j, t_token *tk);
void	pip_lexer(t_lx *lexer, int *j, t_token *token, t_list **s_b);
void	append_lexer(t_lx *lexer, int *j, t_token *token, t_list **s_b);
t_b_l	*ft_parsing(char *ptr, char **env, t_b_l *big_list);
int		r_o_error(int i, int *error);
int		r_i_error(int i, int *error);
int		red_in_error(t_list *temp, int *error);
int		print_this_error(int *error);
int		pip_error(t_list *temp, int *error);
int		heredoc_error(int i, int *error);
int		append_error(int i, int *error);
int		red_out_error(t_list *temp, int *error);
int		here_error(t_list *temp, int *error);
int		app_error(t_list *temp, int *error);
int		r_o_error(int i, int *error);
int		r_i_error(int i, int *error);
void	red_creat(t_list *s_b, t_token *token, t_r **red);
void	creat_cmd(t_list *s_b, t_token *token, t_p_l **parse_branch, int *i);
void	creat_arg(t_list *s_b, t_token *token, t_p_l **parse_branch);
char	*s_q_r(t_exp_list *list, int *type);
char	*d_q_r(t_exp_list *ex_ls, char **env, int type);
char	*n_q_r(t_exp_list *ex_l, char **env, int type);
int		not_between_sd_quotes(char *s, int i);
void	expand1(t_for_exp *exp, t_b_l *tmp_big);
void	expand2(t_for_exp *exp, t_p_l *ex_ls, t_b_l *tmp_big);
void	expand3(t_for_exp *exp);
t_p_l	*get_last_node(t_p_l *list);
void	free_lexer2(t_lx **lexer);
void	go_count_again(char *s, int *i, t_lx *lexer);
void	how_much(char *s, t_lx *lexer);
void	quotes_error(t_lx *lx);

#endif
