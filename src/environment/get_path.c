/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** save path
*/

#include "42sh.h"

int save_path(shell_t *shell)
{
    char *value = NULL;
    char *token = NULL;
    int len = 0;

    if (!shell || !shell->env)
        return FAILURE;
    value = get_env_value(shell, "PATH");
    if (!value)
        return FAILURE;
    shell->path = malloc(sizeof(char *) * strlen(value) + 1);
    token = strtok(value, ":");
    while (token) {
        shell->path[len] = token;
        len += 1;
        token = strtok(NULL, ":");
    }
    shell->path[len] = NULL;
    return SUCCESS;
}
