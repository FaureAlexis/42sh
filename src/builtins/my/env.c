/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** env command
*/

#include "42sh.h"

int my_env(char **args, shell_t *shell)
{
    if (!args || !shell || !shell->env)
        return FAILURE;
    env_t *env = shell->env->first;
    while (env) {
        printf("%s=%s\n", env->name, env->value);
        env = env->next;
    }
    return SUCCESS;
}
