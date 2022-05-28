/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execute command
*/

#include "42sh.h"

cmd_t *check_command(char *command)
{
    cmd_t *cmd = NULL;
    cmd = malloc(sizeof(cmd_t));
    cmd->binary = NULL;
    cmd->args = NULL;
    if (!cmd || !command)
        return NULL;
    if (!is_operator(command)) {
        cmd->operator= NOTHING;
        return cmd;
    } else {
        if (get_operator_and_index(cmd, command) != FAILURE)
            return cmd;
    }
    return NULL;
}



int exec_cmd(char *command, shell_t *shell)
{
    if (!shell || !command)
        return FAILURE;
    cmd_t *cmd = check_command(command);
    if (!cmd)
        return FAILURE;
    if (cmd->operator== NOTHING) {
        cmd->binary = parse_binary(command);
        cmd->args = parse_args(command);
        if (is_a_binary(cmd->binary)) {
            call_binary(cmd->binary, cmd->args, shell);
        } else {
            execute(cmd, shell);
        }
    } else {
        if (cmd->operator == PIPE)
            my_pipe(command, cmd, shell);
        else
            redirect(command, cmd, shell);
    }
    return SUCCESS;
}
