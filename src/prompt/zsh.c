/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** zsh & omz
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "42sh.h"

static char *parse_dir(char *pwd)
{
    char *token = NULL;
    char *dir = NULL;
    token = strtok(pwd, "/");
    while (token) {
        dir = token;
        token = strtok(NULL, "/");
    }
    dir[strlen(dir)] = '\0';
    return dir;
}

static char *parse_git_branch(void)
{
    int fd = 0;
    char *token = NULL;
    char *buffer = NULL;
    char *branch = NULL;
    struct stat sa = {0};
    if (stat(".git/HEAD", &sa) != -1) {
        fd = open(".git/HEAD", O_RDONLY);
        buffer = malloc(sa.st_size + 2);
        read(fd, buffer, sa.st_size + 1);
        token = strtok(buffer, "/");
        while (token != NULL) {
            branch = token;
            token = strtok(NULL, "/");
        }
        branch[strlen(branch) - 1] = '\0';
        free(buffer);
        close(fd);
        return branch;
    }
    return NULL;
}

void display_zsh(char *pwd)
{
    if (!pwd)
        return;
    char *git_branch = NULL;
    char *current_dir = NULL;
    current_dir = parse_dir(pwd);
    git_branch = parse_git_branch();
    if (!current_dir)
        return;
    printf("\x1b[1m\x1b[92m➜  \x1b[36m%s", current_dir);
    if (git_branch) {
        printf("\x1b[34m git:(\x1b[91m%s\x1b[34m)", git_branch);
    }
    printf("\x1b[33m ✗ \x1b[0m");
}
