/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** clean string
*/

#include "42sh.h"

char *clean_string(char *str)
{
    char *res = NULL;
    int j = 0;
    int i = 0;
    if (!str)
        return NULL;
    res = malloc(sizeof(char) * strlen(str) + 1);
    for (; str[i] == ' ' || str[i] == '\t'; i += 1)
        ;
    for (; str[i] != '\0'; i += 1) {
        if (str[i] == '\t' || str[i] == '\n') {
            res[j] = ' ';
        } else {
            res[j] = str[i];
        }
        j += 1;
    }
    return res;
}
