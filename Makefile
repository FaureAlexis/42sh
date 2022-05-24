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

SRC_PROMPT				=	prompt/display_prompt.c		\
							prompt/zsh.c				\
							prompt/get_input.c

SRC_ERROR				=	error_handling/check_env.c

SRC_PARSING 			=	parsing/parse_semicolons.c

SRC_TOOLS				=	tools/string/clean_string.c

SRC_BUILTINS			=	builtins/check_builtins.c			\
							builtins/my/alias.c 				\
							builtins/my/cd.c 					\
							builtins/my/env.c 				\
							builtins/my/history.c 			\
							builtins/my/setenv.c 				\
							builtins/my/unsetenv.c 			\
							builtins/my/theme.c				\

SRC						= 	$(addprefix src/, $(SRC_42SH))		\
							$(addprefix src/, $(SRC_PROMPT))	\
							$(addprefix src/, $(SRC_ERROR))		\
							$(addprefix src/, $(SRC_PARSING))	\
							$(addprefix src/, $(SRC_TOOLS))		\
							$(addprefix src/, $(SRC_BUILTINS))	\

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
