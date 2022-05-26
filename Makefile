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

SRC_TOOLS				=	string/clean_string.c

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
							analyse/analyse.c 			\

SRC						= 	$(addprefix src/, $(SRC_42SH))						\
							$(addprefix src/prompt/, $(SRC_PROMPT))				\
							$(addprefix src/error_handling/, $(SRC_ERROR))		\
							$(addprefix src/parsing/, $(SRC_PARSING))			\
							$(addprefix src/tools/, $(SRC_TOOLS))				\
							$(addprefix src/builtins/, $(SRC_BUILTINS))			\
							$(addprefix src/free/, $(SRC_FREE)) 				\
							$(addprefix src/exec/, $(SRC_EXEC)) 				\

MAIN 					=	main.c

OBJ						=	$(SRC:.c=.o)	\
							$(addprefix src/, $(MAIN:.c=.o))

TESTS					=	tests/test_shell.c

OBJ_TESTS				=	$(SRC:.c=.o)

NAME					=	42sh

CPPFLAGS				=	-I ./include -g -Werror -Wall -Wextra -Wpedantic

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
	$(CC) -o uni $(OBJ_TESTS) $(TESTS) $(CPPFLAGS) -lcriterion --coverage

.PHONY	=	all re fclean clean tests_run
