/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** manage execution of command
*/

#include "42sh.h"

int execution_control(char **cmd, shell_t *shell)
{
    if (!cmd || !cmd[0] || !shell)
        return FAILURE;
    for (int i = 0; cmd[i] != NULL; i += 1) {
            char **env = env_to_tab(shell);
            exec_cmd(cmd[i], shell, env);
    }
    return SUCCESS;
}
