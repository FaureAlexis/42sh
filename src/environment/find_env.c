/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** get env
*/

#include "42sh.h"

char *get_env_value(shell_t *shell, char *name)
{
    if (!name || !shell)
        return NULL;
    env_t *env = shell->env->first;
    while (env) {
        if (strcmp(name, env->name) == 0)
            return env->value;
        env = env->next;
    }
    return NULL;
}

int update_env_value(shell_t *shell, char *name, char *value)
{
    if (!shell || !name || !value)
        return FAILURE;
    env_t *env = shell->env->first;
    while (env) {
        if (strcmp(name, env->name) == 0) {
            env->value = value;
            return SUCCESS;
        }
        env = env->next;
    }
    return FAILURE;
}
