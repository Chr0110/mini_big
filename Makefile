NAME = minishell

LIB = minishell.h

SRC_P = \
		./Parsing/parsing.c\
		./Parsing/lexer.c\
		./Parsing/lexer_utils.c\
		./Parsing/lexer_utils2.c\
		./Parsing/lexer_utils3.c\
		./Parsing/lexer_utils4.c\
		./Parsing/lexer_utils5.c\
		./Parsing/creat_big_list.c\
		./Parsing/creat_list_list.c\
		./Parsing/creat_parse_list.c\
		./Parsing/creat_red_list.c\
		./Parsing/parse.c\
		./Parsing/check_errors.c\
		./Parsing/error_utils.c\
		./Parsing/error_utils1.c\
		./Parsing/error_utils2.c\
		./Parsing/expand.c\
		./Parsing/expand_utils.c\
		./Parsing/expand_utils1.c\
		./Parsing/expand_utils2.c\
		./Parsing/expand_utils3.c\
		./Parsing/expand_dollar.c\
		./Parsing/making_result.c\
		./Parsing/dollar_cases.c\
		./Parsing/give_me_that_mf_dollar.c\
		./Parsing/remove_quotes.c\
		./Parsing/parsing_utils.c\

SRC_E = \
		./minishell.c\
		./exec/ft_execution.c\
		./exec/minishell_utils.c\
		./exec/ft_pwd.c\
		./exec/ft_echo.c\
		./exec/ft_cd.c\
		./exec/ft_env.c\
		./exec/ft_export.c\
		./exec/ft_exit.c\
		./exec/ft_unset.c\
		./exec/is_builtins.c\
		./exec/initial_env.c\
		./exec/ft_pipe.c\
		./exec/ft_path.c\
		./exec/ft_rediraction.c\
		# test.c\
		# pipex_utils2.c\
		# multiple_pipe.c\

SRC = $(SRC_E) $(SRC_P)

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