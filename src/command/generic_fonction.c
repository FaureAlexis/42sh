/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** generic_fonction
*/

#include "42sh.h"

char **creat_array_from_str(char *cmd, const char *sep)
{
    char **list = NULL;
    char *token = NULL;

    if (!cmd)
        return NULL;
    list = malloc(sizeof(char *) * strlen(cmd));
    if (!list) {
        list[0] = cmd;
        return list;
    }
    token = strtok(cmd, sep);
    for (int idx = 0; token; idx += 1, token = strtok(NULL, sep))
        list[idx] = clean_string(token);
    return list;
}

int comp_sep(char c, char pos)
{
    if (c != pos && c != '\n' && c != '\0') {
        return (1);
    }
    return (0);
}

int get_nb_words_comp(char const *str, char pos)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != '\0') {
        if (comp_sep(str[i], pos) == 1 && comp_sep(str[i + 1], pos) == 0) {
            nb_words += 1;
            }
        i += 1;
    }
    return nb_words;
}

env_t *find_nodenv(env_t *env, char *file)
{
    env_t *node = env;

    while (strcmp(node->name, file) != 0) {
        if (!node->next) {
            return NULL;
        }
        node = node->next;
    }
    return node;
}
