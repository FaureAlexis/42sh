/*
** EPITECH PROJECT, 2021
** bs
** File description:
** main
*/

#include "42sh.h"

int print_env(env_t *head, int exit, char *buff)
{
    char **array = creat_array_from_str(buff, " ");

    if (array[1] != NULL) {
        my_printf("env: '%s': No such file or directory\n", array[1]);
        array_free(array);
        return 0;
    } else if (head == NULL) {
        array_free(array);
        return 0;
    }
    array_free(array);
    print_list(head);
    return 0;
}

char *conc_str(char *str, int len_conc)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) - len_conc + 1));

    if (!result) {
        return NULL;
    }
    for (int i = len_conc; str[i] != '\0'; i += 1) {
        result[i - len_conc] = str[i];
    }
    result[my_strlen(str) - len_conc] = '\0';
    return result;
}

int len_node_env(char *variable)
{
    int result = 0;

    while (variable[result] != '=') {
        result += 1;
    }
    return result;
}

char **my_node_env(char *variable)
{
    char **array = malloc(sizeof(char *) * 3);
    int len_name = len_node_env(variable) + 1;
    int len_block = my_strlen(variable) - len_name + 1;
    int idx = 0;

    array[0] = malloc(sizeof(char) * len_name);
    array[1] = malloc(sizeof(char) * len_block);
    while (variable[idx] != '=') {
        array[0][idx] = variable[idx];
        idx += 1;
    }
    array[0][idx] = '\0';
    idx += 1;
    for (int i = 0; variable[idx + i] != '\0'; i += 1) {
        array[1][i] = variable[idx + i];
    }
    array[1][len_block - 1] = '\0';
    array[2] = NULL;
    return array;
}

env_t *env_non_null(env_t *head)
{
    char *buff = malloc(sizeof(char) * 201);

    if (head == NULL) {
        head = malloc(sizeof(env_t));
        head->name = my_strcat("PWD", "\0");
        getcwd(buff, 200);
        head->block = my_strcat(buff, "\0");
        head->next = NULL;
    }
    free(buff);
    return head;
}