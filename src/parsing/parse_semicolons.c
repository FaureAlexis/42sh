/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** parse ; from input
*/

#include "42sh.h"

char **parse_semicolons(char *cmd)
{
    const char *sep = ";";
    char **list = NULL;
    char *token = NULL;

    if (!cmd)
        return NULL;
    list = malloc(sizeof(char *) * strlen(cmd));
    if (!list) {
        list[0] = cmd;
        return list;
    }
    token = strtok(cmd, sep);
    for (int idx = 0; token; idx += 1, token = strtok(NULL, sep))
        list[idx] = clean_string(token);
    return list;
}
