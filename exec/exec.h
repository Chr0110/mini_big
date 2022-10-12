# ifndef EXEC_H
# define EXEC_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <termios.h>
#include <sys/errno.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define CYAN 	"\x1b[36m"
# define NOR  	"\x1B[37m"
# define MAG  "\x1B[35m"


typedef struct s_env
{
	char *content;
	char *str;
	struct s_env *next;
}	t_env;

typedef struct s_data 
{
	int id;
	char **type;

} t_data;

int g_var[2];

typedef struct s_vars
{
	char *content;
	char **bar;
	char **env;
	char **nar;
	char **envp;
	char **var;
	char **exp;
	char *pwd;
	char **cmd;
	int	len;
	int	*infile;
	int	*outfile;
	int index;
	int s0;
	int s1;
	int flag;

}	t_vars;


// t_vars *vars;

char	**ft_split(char const *s, char c);
int		ft_len(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
// char	*ft_strdupp(char *s1);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(char **path);
void	ft_putendl_fd(char *s, int fd);
int is_builtins(t_vars *vars, char **bar);
void	builtins(t_vars *vars, char **bar);
void 	ft_pwd(t_vars *vars);
void	ft_echo(char **bar, t_vars *vars);
void	ft_cd(char **ptr, t_vars *vars);
void	ft_chdir(char *ptr, t_vars *vars);
char	**sort_str(char **ptr);
void	ft_exit(char **bar, t_vars *vars);
void	 check_export(char **bar, t_vars *vars);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char	*dst,	char	*src);
char	*ft_strcat(char	*s1, char *s2);
int		ft_isalnum(int c);
int		ft_strchr(const char *s, int c);
void	aff_export(char **bar,t_vars *vars);
void	aff_export2(char **bar,t_vars *vars);
void	ft_env(char **bar,t_vars *vars);
void 	aff_env(char **ptr, t_vars *vars);
void	initial_env(t_vars *vars, char **env);
void	initial_exp(t_vars *vars, char **env);
void 	add_var(char **bar,t_vars *vars);
void	ft_unset(char **bar,t_vars *vars);
void	check_export2(char **bar,t_vars *vars);
void	add_env(char **bar,t_vars *vars);
void	add_export(char **bar,t_vars *vars);
void	is_not_double(int len,t_vars *vars);
char	**take_bar(char **bar,t_vars *vars);
char	**check_bar(char **bar,char **barr);
char	**take_variable(int len, t_vars *vars);
char	**take_variable2(int len, t_vars *vars);
int		size_env(t_vars *vars);
void	change_valeur(char *ptr, char *str);
void	env_to_exp(t_vars *vars);
void	remove_double(char **bar,t_vars *vars);
void	unset_exp(char **bar ,t_vars *vars);
int		size_exp(t_vars *vars);
void	ft_replace(t_vars *vars);
void	ft_append(t_vars *vars);
char	*ft_itoa(int n);
char *ft_getcwd(t_vars *vars);
void 	ft_replace_shlvl(t_vars *vars);
void 	ft_replace_oldpwd(t_vars *vars);


//////                 PIPEX              ///////////////
int		check_rediraction(t_b_l *lil);
char	*ft_path(char *av, char **env);
void	ft_pipe(t_b_l *big, t_vars *vars, int  len);
void	ft_rediraction( t_b_l *lil, t_vars *vars, int i);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strstr(const char *haystack, const char *needle);
void	ft_putstr(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void 	ft_close(int len, t_vars *vars);
void ft_wait(pid_t child_pro, int len);
void 	psudo_close(t_vars *vars, int i);
void 	ft_execute(char **cmmd,t_vars *vars);
int 	check_path(char **env);
char 	**find_path(char **env, int i, char *envp);
// char	*copie_echo(char *ptr);
// void 	ft_test(char *ptr, char **env);
char 	*ft_copie_shlvl(char *str);
void	ft_initial_exec(t_vars *vars, char **env);

// int	count_lil(t_p_l *lst);
int	count_list(t_b_l *lst);
char *find_user(t_vars *vars);
void	ft_chdir(char *ptr, t_vars *vars);
void ft_transform(t_b_l *lil);
void ft_test(t_b_l *lil2);
void init_signal(void);

# endif
