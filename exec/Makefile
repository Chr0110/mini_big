NAME = minishell

LIB = minishell.h

SRC = minishell.c\
		minishell_utils.c\
		ft_pwd.c\
		ft_echo.c\
		ft_cd.c\
		ft_env.c\
		ft_export.c\
		ft_exit.c\
		ft_unset.c\
		is_builtins.c\
		initial_env.c\
		ft_pipe.c\
		ft_path.c\
		ft_rediraction.c\
		# pipex_utils2.c\
		# multiple_pipe.c\
		#multiple_rediraction.c\
		herdoc.c
		
CC = cc 

CFLAGS =   -I /Users/sriyani/goinfre/brew/opt/readline/include #-fsanitize=address 
LIB_FLAG = -L /Users/sriyani/goinfre/brew/opt/readline/lib
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIB)
			$(CC) $(CFLAGS) $(LIB_FLAG) -o $(NAME)   -lreadline  $(OBJ) 

$(OBJ):
	$(CC) -c $(CFLAGS) $(@:%.o=%.c) -o $(@)

clean:
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re