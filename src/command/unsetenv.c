/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** unsetenv
*/

#include "42sh.h"

int unsetenv_error(char **array, env_t *head)
{
    env_t *node = head->next;

    if (array[1] == NULL){
        putstr("unsetenv: Too few arguments.\n");
        return 1;
    } else if (strcmp(head->name, array[1]) == 0) {
        free(head->name);
        free(head->block);
        free(head);
        head = node;
        return 1;
    } else {
        return 0;
    }
}

int unsetenv(env_t *head, int i, char *buff, char **array)
{
    env_t *node = head;
    env_t *tmp = NULL;
    env_t *prev = node;

    while (strcmp(node->name, array[i]) != 0) {
        if (node->next == NULL) {
            return 0;
        }
        prev = node;
        node = node->next;
    }
    tmp = node->next;
    free(node->name);
    free(node->block);
    free(node);
    prev->next = tmp;
    return 0;
}

int gets_unsetenv(env_t *head, int exit, char *buff)
{
    char **array = creat_array_from_str(buff, " ");

    if (unsetenv_error(array, head) == 1) {
        return 0;
    } else {
        for (int i = 1; array[i] != NULL; i += 1) {
            unsetenv(head, i, buff, array);
        }
        return 0;
    }
}

char *my_str_setenv(char **array, char *buff)
{
    char *str = malloc(sizeof(char) * (strlen(buff) - \
    strlen(array[0]) - 1));

    buff[strlen(array[0]) + strlen(array[1]) + 1] = '=';
    for (int i = (strlen(array[0]) + 1); buff[i + 1] != '\0'; i += 1) {
        str[i - (strlen(array[0]) + 1)] = buff[i];
    }
    str[strlen(buff) - strlen(array[0]) - 2] = '\0';
    return str;
}
