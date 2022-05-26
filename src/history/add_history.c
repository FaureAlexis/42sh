/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** add command to history
*/

#include "42sh.h"

void add_command_to_history(shell_t *shell, char *command)
{
    his_element_t *node = NULL;
    if (!shell || !command)
        return;
    node = malloc(sizeof(his_element_t));
    node->command = command;
    node->next = node;
    node->prev = node;
    shell->history->size += 1;
    if (!shell->history->first) {
        node->block = 1;
        shell->history->first = node;
        shell->history->last = node;
    } else {
        node->block = shell->history->last->prev->block + 1;
        shell->history->last->next = node;
        node->prev = shell->history->last;
        shell->history->last = node;
    }
}
