/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** setenv command
*/

#include "42sh.h"

int my_setenv(char **args, shell_t *shell)
{
    char *name = NULL;
    char *value = NULL;
    if (!args || !shell || !shell->env || !args[1])
        return FAILURE;
    name = args[1];
    if (!args[2])
        value = "";
    else
        value = args[2];
    return add_node(shell, name, value);
}
