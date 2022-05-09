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

SRC_ERROR				=	error_handling/check_env.c

SRC						= 	$(SRC_42SH)	\
							$(SRC_ERROR) \
							main.c

OBJ						=	$(addprefix src/, $(SRC:.c=.o))

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

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY	=	all re fclean clean
