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
    int is_good = 0;
    struct dirent *stream = NULL;
    DIR *op = NULL;

    if (!dir_path || !command)
        return false;
    is_good = access(dir_path, R_OK);
    if (is_good == -1) {
        perror(dir_path);
    }
    op = opendir(dir_path);
    if (op == NULL)
        return false;
    while ((stream = readdir(op)) != NULL) {
        if (stream->d_type == DT_DIR)
            return false;
        if (strcmp(stream->d_name, command) == 0)
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
            tmp = malloc(strlen(binary_name) + 1);
            tmp = strcpy(tmp, shell->path[i]);
            tmp = strcat(tmp, "/");
            binary_name = strcat(tmp, binary_name);
            free(tmp);
            return binary_name;
        }
    }
    return NULL;
}
