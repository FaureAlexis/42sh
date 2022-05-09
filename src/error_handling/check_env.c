/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** check environment
*/

#include "42sh.h"

static int check_line(char *str)
{
    int i = 0;
    char *keyword = NULL;

    if (!str)
        return FAILURE;
    keyword = malloc(sizeof(char) * strlen(str) + 1);
    for (; str[i] != '='; i += 1)
        keyword[i] = str[i];
    keyword[i] = '\0';
    if (strcmp(keyword, "PATH") != 0)
        return FAILURE;
    return SUCCESS;
}

int check_env(char **env)
{
    if (!env)
        return FAILURE;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (check_line(env[i]) == 0)
            return SUCCESS;
    }
    return FAILURE;
}
