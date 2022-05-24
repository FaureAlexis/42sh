/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** shell loop
*/

#include "42sh.h"

static int loop(char **env, shell_t *shell)
{
    char **cmd = NULL;
    if (!env)
        return FAILURE;
    while (1) {
        cmd = get_commands(shell);
        if (cmd == NULL)
            return SUCCESS;
        for (int i = 0; cmd[i]; i += 1)
            printf("%s\n", cmd[i]);
    }
    return SUCCESS;
}

int shell(char **env)
{
    if (!env || check_env(env) == FAILURE)
        return FAILURE;
    shell_t *shell = malloc(sizeof(shell_t));
    if (!shell)
        return FAILURE;
    shell->prompt_theme = TCSH;
    return loop(env, shell);
}
