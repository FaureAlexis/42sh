/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execute command
*/

#include "42sh.h"

void exec_cmd(char *command, shell_t *shell)
{
    if (!shell || !command)
        return;
}

void check_command(char *command)
{
    cmd_t *cmd = NULL;
    cmd = malloc(sizeof(cmd_t));
    cmd->binary = NULL;
    cmd->args = NULL;
    if (!cmd || !command)
        return;
    if (!is_operator(command)) {
        cmd->operator= NOTHING;
    } else {
        // get index & op
    }
}
