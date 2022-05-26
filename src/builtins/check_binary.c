/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** check if command is a binary
*/

#include "42sh.h"

bool is_a_binary(char *binary)
{
    if (!binary)
        return false;
    char *list[] = {
        "cd", "env", "setenv", "unsetenv", "theme", "alias", "history", NULL};
    for (int idx = 0; list[idx]; idx += 1) {
        if (strcmp(binary, list[idx]) == 0)
            return true;
    }
    return false;
}

int call_binary(char *binary, char **args, shell_t *shell)
{
    if (!binary || !args || !shell)
        return FAILURE;
    int (*func_list[7])(char **args, shell_t *shell) = {&my_cd, &my_env,
        &my_setenv, &my_unsetenv, &my_theme, &my_alias, &my_history};
    char *list[] = {"exit", "cd", "env", "setenv", "unsetenv", "theme",
        "alias", "history", NULL};
    for (int idx = 0; list[idx]; idx += 1) {
        if (strcmp(binary, list[idx]) == 0)
            return func_list[idx](args, shell);
    }
    return FAILURE;
}
