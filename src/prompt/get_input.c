/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** get user input
*/

#include "42sh.h"
#include <readline/readline.h>
#include <readline/history.h>

char *get_input(shell_t *shell)
{
    //size_t size = 2048;
    char *input = NULL;

    //display_prompt(shell);
    //if (getline(&input, &size, stdin) == -1)
     //   return NULL;
    input = readline("> ");
    if (input[0] == '\n')
        return get_input(shell);
    add_history(input);
    return input;
}

char **get_commands(shell_t *shell)
{
    char *input = NULL;
    char *cmd = NULL;

    input = get_input(shell);
    if (!input)
        return NULL;
    cmd = clean_string(input);
    add_command_to_history(shell, clean_string(input));
    return parse_semicolons(cmd);
}
