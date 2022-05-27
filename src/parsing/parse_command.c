/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** parse command binary and arguments
*/

#include "42sh.h"

char *parse_binary(char *command)
{
    int len = 0;
    char *binary = NULL;
    if (!command)
        return NULL;
    binary = malloc(strlen(command) + 1);
    for (int idx = 0; command[idx] != '\0'; idx += 1) {
        if (command[idx] == 32)
            break;
        binary[len] = command[idx];
        len += 1;
    }
    binary[len] = 0;
    return binary;
}

char **parse_args(char *command)
{
    int len = 0;
    char **args = NULL;
    char *token = NULL;
    if (!command)
        return NULL;
    args = malloc(sizeof(char *) * strlen(command) + 1);
    if (!args)
        return NULL;
    token = strtok(command, " ");
    token = strtok(NULL, " ");
    while (token) {
        args[len] = token;
        token = strtok(NULL, " ");
        len += 1;
    }
    if (args[0] == NULL)
        args[0] = "";
    args[len + 1] = NULL;
    return args;
}
