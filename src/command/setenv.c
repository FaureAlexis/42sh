/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** setenv
*/

#include "42sh.h"

int choice_past_or_modife(env_t *tmp, char **array, int i)
{
    if (strcmp(tmp->name, array[1]) == 0) {
        free(tmp->block);
        tmp->block = strcat(array[2], "\0");
        i += 1;
        return i;
    }
    return 0;
}

int check_env(env_t *head, char *str, char **array)
{
    env_t *tmp = head;
    env_t *node = NULL;
    int i = 0;

    while (tmp->next != NULL && i == 0) {
        i += choice_past_or_modife(tmp, array, i);
        tmp = tmp->next;
    }
    i += choice_past_or_modife(tmp, array, i);
    if (i == 0) {
        node = create_node_from_str(str);
        head = add_node_to_list(head, node);
    }
    return 0;
}

int my_setenv(env_t *head, int exit, char *buff)
{
    char **array = str_to_word_array(buff);
    char *str = NULL;
    char **arr_file = str_to_word_array_pos(array[1], '=');

    if (array[2] == NULL && arr_file[1] == NULL) {
        str = strcat(array[1], "=\0");
    } else if (array[2] == NULL && arr_file[1] != NULL) {
        str = strcat(array[1], "\0");
    } else {
        str = str_setenv(array, buff);
    }
    check_env(head, str, array);
    free(str);
    array_free(array);
    array_free(arr_file);
    return 0;
}

int error_bef_setenv(env_t *head, int exit, char *buff)
{
    char **array = str_to_word_array(buff);

    if (array[1][0] >= '0' && array[1][0] <= '9') {
        putstr("setenv: Variable name must begin with a letter.\n");
        return 0;
    } else if (str_alphanum(array[1]) == 1) {
        putstr(\
        "setenv: Variable name must contain alphanumeric characters.\n");
        return 0;
    } else {
        my_setenv(head, exit, buff);
        return 0;
    }
}

int gets_setenv(env_t *head, int exit, char *buff)
{
    char **array = creat_array_from_str(buff, " ");

    if (array[1] != NULL && array[2] != NULL && array[3] != NULL) {
        putstr("setenv: Too many arguments.\n");
    } else if (array[1] == NULL) {
        print_env(head, exit, buff);
    } else {
        error_bef_setenv(head, exit, buff);
    }
    array_free(array);
    return 0;
}
