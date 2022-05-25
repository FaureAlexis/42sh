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
        if (cmd == NULL) {
            printf("exit\n");
            return SUCCESS;
        }
        for (int i = 0; cmd[i] != NULL; i += 1) {
            exec_cmd(cmd[i], shell);
        }
    }

    return SUCCESS;
}

int shell(char **env)
{
    int code = FAILURE;
    if (!env || check_env(env) == FAILURE)
        return FAILURE;
    shell_t *shell = malloc(sizeof(shell_t));
    if (!shell)
        return FAILURE;
    shell->prompt_theme = TCSH;
    code = loop(env, shell);
    free_shell(shell);
    return code;
}
