/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** search binary in file
*/

#include <dirent.h>
#include <string.h>
#include "42sh.h"

bool is_in_dir(char *dir_path, char *command)
{
    struct dirent *stream = NULL;
    DIR *op = NULL;

    if (!dir_path || !command)
        return false;
    op = opendir(dir_path);
    if (op == NULL)
        return false;
    while ((stream = readdir(op)) != NULL) {
        if (strcmp(stream->d_name, command) == 0 && stream->d_type != DT_DIR)
            return true;
    }
    return false;
}

char *search_in_path(char *binary_name, shell_t *shell)
{
    char *tmp = NULL;
    if (!binary_name || !shell || !shell->path)
        return NULL;
    for (int i = 0; shell->path[i]; i += 1) {
        if (is_in_dir(shell->path[i], binary_name)) {
            tmp = malloc(strlen(binary_name) + 2);
            tmp = strcpy(tmp, shell->path[i]);
            tmp = strcat(tmp, "/");
            tmp[strlen(tmp)] = 0;
            binary_name = strcat(tmp, binary_name);
            return binary_name;
        }
    }
    return NULL;
}
