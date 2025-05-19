##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## a Makefile
##

ALIAS = src/builtins/alias
BUILTINS = src/builtins
ENV = src/env
EXECUTION = src/execute
REDIRECTION = src/redirect
UTILS = utils
HISTORY = src/history
INHIBITORS = src/inhibitors
PARENTHESES = src/parentheses
GLOBBING = src/globing

SRC		=	src/main.c									\
			src/minishell.c								\
			$(ENV)/remplace_var.c						\
			$(ENV)/push_to_list.c						\
			$(ENV)/copy_env.c							\
			$(ENV)/env_utils.c							\
			$(BUILTINS)/my_env.c						\
			$(BUILTINS)/my_setenv.c						\
			$(BUILTINS)/my_unsetenv.c					\
			$(BUILTINS)/my_cd.c							\
			$(BUILTINS)/my_history.c					\
			$(BUILTINS)/my_which.c						\
			$(BUILTINS)/my_where.c						\
			$(BUILTINS)/my_repeat.c						\
			$(BUILTINS)/my_echo.c						\
			$(ALIAS)/my_alias.c							\
			$(ALIAS)/my_unalias.c						\
			$(ALIAS)/add_alias.c						\
			$(ALIAS)/remove_alias.c						\
			$(ALIAS)/search_alias.c						\
			$(ALIAS)/replace_by_alias.c					\
			$(ALIAS)/free_alias.c						\
			$(ALIAS)/reconcat_args.c					\
			$(EXECUTION)/execute_node.c					\
			$(EXECUTION)/execute.c						\
			$(EXECUTION)/execute_binary.c				\
			$(EXECUTION)/execute_commande.c				\
			$(EXECUTION)/execute_builtin.c				\
			$(EXECUTION)/handle_signal.c				\
			$(EXECUTION)/handle_execute.c				\
			$(REDIRECTION)/handle_input_read_write.c	\
			$(REDIRECTION)/handle_input_redir.c			\
			$(REDIRECTION)/handle_output_append.c		\
			$(REDIRECTION)/handle_output_redir.c		\
			$(REDIRECTION)/handle_pipe.c				\
			$(REDIRECTION)/handle_semicolon.c			\
			$(REDIRECTION)/handle_double_pipe.c			\
			$(REDIRECTION)/handle_double_ampersand.c	\
			$(REDIRECTION)/ll_parsor.c					\
			$(UTILS)/send_message.c 					\
			$(UTILS)/str_cpy_part.c						\
			$(UTILS)/str_to_split_array.c				\
			$(UTILS)/str_to_word_array.c				\
			$(UTILS)/free_word_array.c					\
			$(UTILS)/free_list.c						\
			$(UTILS)/array_len.c						\
			$(UTILS)/put_char.c							\
			$(UTILS)/my_strcmp.c						\
			$(UTILS)/my_strcpy.c						\
			$(UTILS)/my_strlen.c						\
			$(UTILS)/my_strdup.c						\
			$(UTILS)/my_strcat.c						\
			$(UTILS)/trim_spaces.c						\
			$(UTILS)/my_strcat_malloc.c					\
			$(UTILS)/make_path.c						\
			$(UTILS)/get_path_array.c					\
			$(HISTORY)/push_to_history.c				\
			$(HISTORY)/free_history.c					\
			$(INHIBITORS)/handle_inhibitors.c			\
			$(PARENTHESES)/handle_parentheses.c			\
			$(GLOBBING)/arg_globing.c					\

NAME		=	42sh

INCS		=	-iquote./include

LDLIBS		=	-L./lib/

WARNINGS	=	-Wall -Wextra

CPPFLAGS	=	$(INCS) $(LDLIBS) $(WARNINGS)

CFLAGS		=	$(INCS) $(LDLIBS)

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug: CFLAGS += -g3
debug: re

unit_tets: re
unit_tets: clean

tests_run: 	unit_tets
			./tests/sell_tests.sh

.PHONY: all clean fclean re
