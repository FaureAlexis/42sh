/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execute command
*/

#include "42sh.h"

void exec_cmd(char *cmd, shell_t *shell)
{
    char *binary = NULL;
    char **args = NULL;

    if (!cmd || !shell)
        return;
    binary = parse_binary(cmd);
    args = parse_args(cmd);
    if (!binary)
        return;
}
