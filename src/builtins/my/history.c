/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** history command
*/

#include "42sh.h"

int my_history(char **args, shell_t *shell)
{
    int i = 0;
    if (!args || !shell || !shell->history)
        return FAILURE;
    printf("\n");
    his_element_t *node = shell->history->first;
    if (!node)
        return FAILURE;
    while (i < shell->history->size) {
        printf("    %d  %s\n", node->block, node->command);
        node = node->next;
        i += 1;
    }
    return SUCCESS;
}
