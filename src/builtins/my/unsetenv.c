/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** unsetenv command
*/

#include "42sh.h"

int delete_env(shell_t *shell, env_t *env)
{
    if (env->prev)
        env->prev->next = env->next;
    if (env->next)
        env->next->prev = env->prev;
    if (shell->env->first == env)
        shell->env->first = env->next;
    if (shell->env->last == env)
        shell->env->last = env->prev;
    free(env);
    return SUCCESS;
}

int my_unsetenv(char **args, shell_t *shell)
{
    if (!args || !shell || !shell->env || !args[1])
        return FAILURE;
    env_t *env = shell->env->first;
    while (env) {
        if (strcmp(env->name, args[1]) == 0) {}
        env = env->next;
    }
    return FAILURE;
}
