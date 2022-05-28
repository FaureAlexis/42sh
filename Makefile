##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

ifndef VERBOSE
.SILENT:
endif

SRC_42SH				=	shell.c

SRC_PROMPT				=	display_prompt.c		\
							zsh.c				\
							get_input.c

SRC_ERROR				=	check_env.c

SRC_PARSING 			=	parse_semicolons.c		\
							parse_command.c			\
							parse_pipes.c

SRC_TOOLS				=	string/clean_string.c	\
							array_len.c

SRC_BUILTINS			=	check_binary.c			\
							my/alias.c 				\
							my/cd.c 					\
							my/env.c 				\
							my/history.c 			\
							my/setenv.c 				\
							my/unsetenv.c 			\
							my/theme.c				\

SRC_FREE 				=	free_shell.c 					\

SRC_EXEC 				=	execute.c					\
							exec_control.c 				\
							check_command.c 			\
							analyse/analyse.c 			\
							pipe.c						\
							redirections/in.c 			\
							redirections/redirect.c     \

SRC_ENV					=	create_env.c				\
							find_env.c 					\
							get_path.c					\
							search_in_path.c			\

SRC_HISTORY				= 	add_history.c 				\
							clear_history.c				\
							init_history.c

SRC						= 	$(addprefix src/, $(SRC_42SH))						\
							$(addprefix src/prompt/, $(SRC_PROMPT))				\
							$(addprefix src/error_handling/, $(SRC_ERROR))		\
							$(addprefix src/parsing/, $(SRC_PARSING))			\
							$(addprefix src/tools/, $(SRC_TOOLS))				\
							$(addprefix src/builtins/, $(SRC_BUILTINS))			\
							$(addprefix src/free/, $(SRC_FREE)) 				\
							$(addprefix src/exec/, $(SRC_EXEC)) 				\
							$(addprefix src/environment/, $(SRC_ENV))			\
							$(addprefix src/history/, $(SRC_HISTORY))			\

MAIN 					=	main.c

OBJ						=	$(SRC:.c=.o)	\
							$(addprefix src/, $(MAIN:.c=.o))

TESTS						=	tests/test_shell.c

OBJ_TESTS				=	$(SRC:.c=.o)

NAME					=	42sh

CPPFLAGS				=	-I ./include -g

all:	$(NAME)

PREBUILD:
	@echo -e "\e[92mCompiling sources : \e[34m$(NAME)\e[5m . \e[0m\e[5m . \
	\e[34m . \e[0m"

$(NAME):	PREBUILD $(OBJ)
	@echo -e "\e[92mBuilding sources : \e[34m$(NAME)\e[5m . \e[0m\e[5m . \
	\e[34m . \e[0m"
	@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@echo -e "\e[92m\e[1mBuild successfull !\e[0m"

clean:
	@echo -e "\e[95mCleaning sources : \e[34m$(NAME)\e[0m"
	@rm -f $(OBJ)
	@rm -f unit*

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

tests_run:  fclean $(OBJ_TESTS)
	$(CC) -o unit_tests $(OBJ_TESTS) $(TESTS) $(CPPFLAGS) -lcriterion --coverage
	./unit_tests

.PHONY	=	all re fclean clean tests_run
