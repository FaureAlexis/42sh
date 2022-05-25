/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** free shell
*/

#include "42sh.h"

void free_shell(shell_t *shell)
{
    if (!shell)
        return;
    free(shell);
}
