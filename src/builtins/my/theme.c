/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** theme command
*/

#include "42sh.h"

int my_theme(char **args, shell_t *shell)
{
    if (!args || !shell)
        return FAILURE;
    printf("dans le theme");
    return SUCCESS;
}
