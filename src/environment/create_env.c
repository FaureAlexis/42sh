/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** create env linked list from env
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

char **env_to_tab(shell_t *shell)
{
    env_t *node = NULL;
    char **env = NULL;
    if (!shell)
        return NULL;
    env = malloc(sizeof(char *) * shell->env->size);
    node = shell->env->first;
    for (int i = 0; node; i += 1) {
        env[i] = malloc(strlen(node->name) + strlen(node->value) + 2);
        node = node->next;
    }
    return env;
}

int add_node(shell_t *shell, const char *name, const char *value)
{
    env_t *node = NULL;
    if (!shell || !name || !value)
        return FAILURE;
    node = malloc(sizeof(env_t));
    node->name = malloc(strlen(name) + 1);
    node->value = malloc(strlen(value) + 1);
    node->name = strcpy(node->name, name);
    node->value = strcpy(node->value, value);
    node->next = NULL;
    node->prev = NULL;
    if (!shell->env->first) {
        shell->env->first = node;
        shell->env->last = node;
        return SUCCESS;
    } else {
        shell->env->last->next = node;
        node->prev = shell->env->last;
        shell->env->last = node;
        return SUCCESS;
    }
}

int dup_env_value(shell_t *shell, char *env_object)
{
    char *name = NULL;
    char *value = NULL;
    char *token = NULL;

    token = strtok(env_object, "=");
    if (!token)
        return FAILURE;
    name = token;
    token = strtok(NULL, "=");
    if (!token)
        value = "";
    else
        value = token;
    return add_node(shell, name, value);
}

int create_env(shell_t *shell, char **env)
{
    if (!shell || !env)
        return FAILURE;
    shell->env = malloc(sizeof(list_t));
    if (!shell->env)
        return FAILURE;
    shell->env->size = 0;
    shell->env->first = NULL;
    shell->env->last = NULL;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (dup_env_value(shell, env[i]) == FAILURE)
            return FAILURE;
        shell->env->size += 1;
    }
    return SUCCESS;
}
