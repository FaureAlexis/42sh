/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** init cmd history
*/

#include "42sh.h"

int init_history(shell_t *shell)
{
    if (!shell)
        return FAILURE;
    shell->history = malloc(sizeof(history_t));
    if (!shell->history)
        return FAILURE;
    shell->history->first = NULL;
    shell->history->last = NULL;
    shell->history->size = 0;
    return SUCCESS;
}
