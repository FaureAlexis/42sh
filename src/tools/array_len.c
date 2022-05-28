/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** get array len
*/

#include "42sh.h"

int my_arrlen(char **array)
{
    int count = 0;
    if (!array)
        return -1;
    while (array[count]) {
        count += 1;
    }
    return count;
}
