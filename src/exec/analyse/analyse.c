/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** command analysis
*/

#include "42sh.h"

int analyse_cmd(cmd_t *cmd)
{
    if (!cmd)
        return FAILURE;
    return SUCCESS;
}

int get_operator_and_index(cmd_t *cmd, char *command)
{
    if (!cmd)
        return FAILURE;
    for (int i = 0; command[i] != '\0'; i += 1) {
        switch (command[i]) {
            case '|':
                cmd->operator = PIPE;
                cmd->index = i;
                return SUCCESS;
            case '<':
                cmd->operator = INPUT;
                cmd->index = i;
                return SUCCESS;
            case '>':
                cmd->operator = OUTPUT;
                cmd->index = i;
                return SUCCESS;
            default: continue;
        }
    }
    return FAILURE;
}

bool is_operator(char *command)
{
    if (!command)
        return false;
    for (int i = 0; command[i] != '\0'; i += 1) {
        switch (command[i]) {
            case '|': return true;
            case '<': return true;
            case '>': return true;
            default: continue;
        }
    }
    return false;
}
