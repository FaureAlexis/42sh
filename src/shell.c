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
        execution_control(cmd, shell);
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
    if (create_env(shell, env) == FAILURE || init_history(shell) == FAILURE)
        return FAILURE;
    if (save_path(shell) == FAILURE)
        return FAILURE;
    code = loop(env, shell);
    free_shell(shell);
    return code;
}
