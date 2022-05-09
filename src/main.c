/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** main entry
*/

#include "42sh.h"

int main(int ac, const char *av[], char **env)
{
    if (ac != 1 || !av || check_env(env) == FAILURE)
        return FAILURE;
    return shell(env);
}
