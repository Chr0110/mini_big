/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sriyani <sriyani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:49:34 by sriyani           #+#    #+#             */
/*   Updated: 2022/10/23 11:38:57 by sriyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <sys/stat.h>
# include <dirent.h>
# define SIZE_ALL	10240
# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define CYAN	"\x1b[36m"
# define NOR	"\x1B[37m"
# define MAG	"\x1B[35m"

typedef struct s_data
{
	char	*har;
	int		flag;
	int		p[2];
	int		count;
	char	**type;
	char	*name;
}	t_data;

typedef struct s_vars
{
	pid_t	*child_pro;
	//char	*content;
	//char	**nar;
	//char	**envp;
	//char	**var;
	//char	**cmd;
	char	**bar;
	char	**env;
	char	**exp;
	char	**sar;
	char	**mar;
	char	*pwd;
	int		len;
	int		*infile;
	int		*outfile;
	int		index;
	int		sig_on;
	int		pid;
	int		n_sar;
	int		n_mar;
	int		count_pipe;
	int		flag;
	int		*hold_pid;
}	t_vars;

int		len_env(char **ptr);
void	print_export_error(int l, char **bar, int i);
int		ft_atoi(const char *str);
void	ft_execute(char **cmd, t_vars *vars);
void	check_rediraction2(t_b_l *lil, t_vars *vars, t_data *data, int len);
void	body_pipe(t_vars *vars, t_data *data, int i, int len);
void	fin_pipe(t_vars *vars, pid_t *child_pro, t_data *data, int len);
void	ft_dup(t_vars *vars, t_data *data, int i);
void	built_inside_pipe(t_vars *vars, int i, char **bar);
int		ft_pipe2(t_b_l *big, t_data *data, t_vars *vars, int len);
int		one_built(t_b_l *big, t_vars *vars, t_data *data, int len);
void	creat_pipe(int len, int i, t_vars *vars);
void	intial_fd(t_vars *vars, int len);
int		check_export2(char **bar, int i, int j, int k);
int		check_export3(char **bar, int i);
void	check_export4(char **bar, t_vars *vars, int o, int i);
void	check_export6(char **bar, t_vars *vars, int k);
int		check_export5(char **bar, t_vars *vars);
void	remove_double2(char **test, t_vars *vars, int len);
char	*takevariable2(t_vars *vars, char **str, int i, int j);
void	aff_export3(t_vars *vars, int i);
void	ft_replace_shlvl2(t_vars *vars, int i);
void	path_error(char *cmd);
void	ft_unset_exp2(t_vars *vars, char *barr, char **take);
char	*take_variable_exp2(char **var, t_vars *vars, int i);
void	ft_unset2(t_vars *vars, char *barr, char **take);
int		check_isdouble(char **test, int len, char *str);
void	remove_str(char **test, char *str, t_vars *vars);
void	take_bar2(char **barr, char **bar, int i);
void	add_bar_to_env(int len, char **barr, char **bar, t_vars *vars);
void	fill_bar(t_b_l *big);
int		print_echo(char **bar, t_vars *vars, int o, int j);
int		option_echo(t_vars *vars, char **bar, int j, int y);
int		normal_echo(t_vars *vars, char **bar, int j);
char	**ft_split(char const *s, char c);
int		ft_len(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(char **path);
void	ft_putendl_fd(char *s, int fd);
int		builtins(t_vars *vars, char **bar);
int		is_builtins(char **bar);
int		ft_pwd(t_vars *vars);
int		ft_echo(char **bar, t_vars *vars);
int		ft_cd(char **ptr, t_vars *vars);
int		ft_chdir(char *ptr, t_vars *vars);
char	**sort_str(char **ptr, int len);
int		ft_exit(char **bar);
int		check_export(char **bar, t_vars *vars);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char	*dst,	char	*src);
char	*ft_strcat(char	*s1, char *s2);
int		ft_isalnum(int c);
int		ft_strchr(const char *s, int c);
int		aff_export(char **bar, t_vars *vars);
void	aff_export2(t_vars *vars);
int		ft_env(char **bar, t_vars *vars);
void	aff_env(char **ptr, t_vars *vars);
void	initial_env(t_vars *vars, char **env);
void	initial_exp(t_vars *vars);
void	add_var(char **bar, t_vars *vars);
int		ft_unset(char **bar, t_vars *vars);
void	add_env(char **bar, t_vars *vars);
void	add_export(char **bar, t_vars *vars);
void	is_not_double(int len, t_vars *vars);
char	**take_bar(char **bar);
char	**check_bar(char **bar, char **barr);
char	**take_variable(int len, t_vars *vars);
char	**take_variable2(int len, t_vars *vars);
int		size_env(t_vars *vars);
void	change_valeur(char *ptr, char *str);
void	env_to_exp(t_vars *vars);
void	remove_double(char **bar, t_vars *vars);
int		unset_exp(char **bar, t_vars *vars);
int		size_exp(t_vars *vars);
void	ft_replace(t_vars *vars);
void	ft_append(t_vars *vars);
char	*ft_itoa(int n);
char	*ft_getcwd(t_vars *vars);
void	ft_replace_shlvl(t_vars *vars);
void	ft_replace_oldpwd(t_vars *vars);
int		check_rediraction(t_b_l *lil);
char	*ft_path(char *av, char **env);
void	ft_pipe(t_b_l *big, t_data *data, t_vars *vars, int len);
int		ft_rediraction(t_b_l *lil, t_vars *vars, t_data *data);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strstr(const char *haystack, const char *needle);
void	ft_putstr(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_close(int len, t_vars *vars, char *ptr);	
void	psudo_close(t_vars *vars, int i);
void	ft_execution(t_b_l *big, t_data *data, t_vars *vars);
int		check_path(char **env);
char	**find_path(char **env, int i, char *envp);
char	*ft_copie_shlvl(char *str);
void	ft_initial_exec(t_vars *vars, char **env);
int		count_list(t_b_l *lst);
char	*find_user(t_vars *vars);
void	ft_transform(t_b_l *lil);
void	ft_test(t_b_l *lil2);
void	ft_wait(pid_t *child_pro, int len);
void	init_signal(void);
void	sig_handler(int signum);
int		check_herdoc(t_b_l *lil);
void	sig_han(int signum);
void	pip_herdoc(t_vars *vars, t_b_l *lil, int len, t_data *data);
void	ft_herdoc(t_vars *vars, char *dil, t_data *data);
int		is_herdoc(t_b_l *lil, t_vars *vars, t_data *data);
char	*creat_name(int i);
void	ft_replace2(t_vars *vars);
int		builtins2(t_vars *vars, char **bar);
int		redirect_app(t_vars *vars, int i, char *str);
int		redirect_out(t_vars *vars, int i, char *str);
int		redirect_in(t_vars *vars, int i, char *str);
void	is_herdoc2(t_vars *vars, t_b_l *lil, t_data *data);
int		redirect_herd(t_data *data, t_vars *vars, t_b_l *lil2);
char	*ft_expand(t_vars *vars, char *ptr);
char	*ft_expand2(t_vars *vars, int i, int j);
void	ft_herdoc2(t_vars *vars, char *str, t_data *data);
#endif
