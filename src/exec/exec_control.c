/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** manage execution of command
*/

#include "42sh.h"

void execution_control(char **cmd, shell_t *shell)
{
    for (int i = 0; cmd[i] != NULL; i += 1) {
            exec_cmd(cmd[i], shell);
    }
}
