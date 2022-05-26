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
    if (!args || !shell || !shell->env || !args[0])
        return FAILURE;
    name = args[0];
    if (!args[1])
        value = "";
    else
        value = args[1];
    return add_node(shell, name, value);
}
