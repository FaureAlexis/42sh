/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** clear history
*/

#include "42sh.h"

int clear_my_history(shell_t *shell)
{
    int i = 0;
    if (!shell || !shell->history)
        return FAILURE;
    his_element_t *tmp = NULL;
    his_element_t *node = shell->history->first;
    while (i < shell->history->size) {
        if (!node)
            break;
        tmp = node;
        node = node->next;
        free(tmp);
        i += 1;
    }
    shell->history->first = NULL;
    shell->history->last = NULL;
    return SUCCESS;
}
