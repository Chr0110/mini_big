NAME = minishell

LIB = minishell.h

SRC = 	minishell.c\
		lexer.c\
		lexer_utils.c\
		lexer_utils2.c\
		lexer_utils3.c\
		lexer_utils4.c\
		lexer_utils5.c\
		creat_big_list.c\
		creat_list_list.c\
		creat_parse_list.c\
		creat_red_list.c\
		parse.c\
		check_errors.c\
		error_utils.c\
		error_utils1.c\
		error_utils2.c\
		expand.c\
		expand_utils.c\
		expand_utils1.c\
		expand_utils2.c\
		expand_utils3.c\
		expand_dollar.c\
		expand_quotes.c\
		making_result.c\
		dollar_cases.c\
		give_me_that_mf_dollar.c\
		remove_quotes.c\
		parsing_utils.c\

CC = gcc -fsanitize=address 

CFLAGS =  -g 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIB)
			$(CC)  -o $(NAME)    $(OBJ) -lreadline
clean:
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re