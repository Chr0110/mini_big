/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eradi- <eradi-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:03:11 by eradi-            #+#    #+#             */
/*   Updated: 2022/10/03 11:57:09 by eradi-           ###   ########.fr       */
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

void	init_lexer(char *src, char **env);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_p_l *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_creatlst(t_list **stack, t_token *token);
void	parsing(t_list *small_branch, t_token *token, char **env);
void	check_errors(t_list *small_branch, t_token *token, char **env);
void	expand(t_b_l **big_list, char **env);
void	ft_creat_parse_lst(t_p_l **parse_branch, t_token *token);
void	ft_creat_red_lst(t_r **red_branch, t_token *token);
void	ft_creat_big_list(t_b_l **b_l, t_p_l **p_l, t_r **r, int *i);
int		ft_strncmp(const char *src1, const char *src2, size_t n);
char	*take_from_env(char **env, int j, int i);
int		there_is_a_space(char *str);
void	get_value(char **s, char **env, int *cmp);
char	*ft_strjoin_one(char *str, char c);
char	*handle_dollar_double_quotes(char *s, int *i, char **env, int cmp1);
char	*handle_dollar_no_quotes(char *s, int *i, char **env, int cmp1);
char	*frg3_dik_dollar_d_q(t_exp_list *ex_ls, char **env, int cmp1);
char	*frg3_dik_dollar_n_d_q(t_exp_list *ex_ls, char **env, int cmp1);
char	*handle_dollar_no_quotes1(char *s, int *i, char **env, int cmp1);
void	add_to_parse_list(char *str, t_p_l **expand_list);
void	expand_quotes(t_token *ar_cnt, char **env, int type, t_p_l **ex_ls);
void	expand_dollar(t_token *cnt, char **env, int type, t_p_l **ex_ls);
int		is_alpha(char c);
int		not_between_quotes(char *s, int i);
char	*make_s_q_res(char **res, char *s, int *i, int *type);
char	*make_d_q_res(t_exp_list *ex_ls, char **env, int type);
char	*make_n_q_res(t_exp_list *ex_ls, char **env, int type);
char	*dollar_cases2(char **res, char *s, int *i);
char	*dollar_cases(char **res, char *s, int *i);
char	*skip_white_spaces(char *src, char *str);
int		still_a_quote(t_lx *lexer, int i);
char	*ft_strjoin(char *s, char c);
int		number_of_s_quotes(t_lx *lexer);
int		number_of_quotes(t_lx *lexer);
void	make_list0(t_p_l **t_a, t_p_l *x_l, t_b_l **t_b, t_p_l *nxt); // TODO: remove
void	make_list(t_p_l **curr, t_p_l *t_a_prev, t_p_l *x_ls);
void	exp_creat_list(t_b_l *t_b, char **env);
void	remove_s_a(char **res, int *i, char *s);
void	remove_d_a(char **res, int *i, char *s);
void	remove_quotes(t_token *node);
void	remove_f_quotes(t_b_l *t_b2, t_p_l *ar, t_r *red, t_b_l *b_l);
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
int		ft_strlen(char *s);
void	lexer_init(t_lx	*lexer);
int		not_between_s_quotes(char *s, int i);
void	red_in_lexer(t_lx *lx, int *j, t_token *tk, t_list **s_b);
void	red_out_lx(t_lx *lexer, int *j, t_token *token, t_list **small_branch);
void	heredoc_lexer(t_lx *lexer, int *j, t_token *token, t_list **s_b);
int		d_q_with_error(t_lx *lexer, int *j, t_token *token);
int		d_q_lexer(t_lx *lexer, int *j, t_token *token);
int		s_q_lexer(t_lx *lexer, int *j, t_token *token);
int		lexer_q_cases(t_lx *lx, int *j, t_token *token, t_list **small_branch);
void	ft_ft_creat_list(t_lx *lexer, int *j, t_token *token, t_list **s_b);
void	ft_creat_normal_text(t_lx *lx, int *j, t_token *tk, t_list **s_b);
void	pip_lexer(t_lx *lexer, int *j, t_token *token, t_list **s_b);
void	append_lexer(t_lx *lexer, int *j, t_token *token, t_list **s_b);
int		r_o_error(int i, int *error);
int		r_i_error(int i, int *error);
int		red_in_error(t_list *temp, int *error);
int		print_this_error(int *i, int *error);
int		pip_error(t_list *temp, int *error);
int		heredoc_error(int i, int *error);
int		append_error(int i, int *error);
int		red_out_error(t_list *temp, int *error);
int		here_error(t_list *temp, int *error);
int		app_error(t_list *temp, int *error);
int		r_o_error(int i, int *error);
int		r_i_error(int i, int *error);
void	red_creat(t_list **s_b, t_token *token, t_r **red);
void	creat_cmd(t_list **s_b, t_token *token, t_p_l **parse_branch, int *i);
void	creat_arg(t_list **s_b, t_token *token, t_p_l **parse_branch);
char	*s_q_r(char **res, char *s, int *i, int *type);
char	*d_q_r(t_exp_list *ex_ls, char **env, int type);
char	*n_q_r(t_exp_list *ex_l, char **env, int type);
#endif
