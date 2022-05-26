/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** clear history
*/

#include "42sh.h"

void clear_history(shell_t *shell)
{
    int i = 0;
    if (!shell || !shell->history)
        return;
    his_element_t *node = shell->history->first;
    while (i < shell->history->size) {
        if (node->prev)
            free(node->prev);
        i += 1;
        node = node->next;
    }
    free(node);
    shell->history->first = NULL;
    shell->history->last = NULL;
}
