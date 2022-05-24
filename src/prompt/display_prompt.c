/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** display_prompt.c
*/

#include "42sh.h"

static char *get_pwd(void)
{
    size_t size = 2048;
    char *pwd = NULL;

    pwd = malloc(size);
    pwd = getcwd(pwd, size);
    if (!pwd)
        return NULL;
    return pwd;
}

void display_prompt(shell_t *shell)
{
    if (!shell || !shell->prompt_theme)
        return;
    char *pwd = NULL;

    pwd = get_pwd();
    display_zsh(pwd);
}
