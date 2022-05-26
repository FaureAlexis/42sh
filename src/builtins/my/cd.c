/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** cd command
*/

#include "42sh.h"

int handle_cd_error(shell_t *shell, int err, char *pwd, char *path)
{
    if (err == SUCCESS) {
        update_env_value(shell, "OLDPWD", pwd);
        strcat(pwd, "/");
        strcat(pwd, path);
        return update_env_value(shell, "PWD", pwd);
    } else {
        return FAILURE;
    }
}

int change_directory(shell_t *shell, char *path)
{
    if (!path)
        return FAILURE;
    int err = SUCCESS;
    char *pwd = NULL;
    char *oldpwd = NULL;
    char *home = NULL;
    pwd = get_env_value(shell, "PWD");
    oldpwd = get_env_value(shell, "OLDPWD");
    home = get_env_value(shell, "HOME");
    if (!pwd || !oldpwd || !home)
        return FAILURE;

    if (strcmp(path, "-") == 0)
        err = chdir(oldpwd);
    else if (strcmp(path, "~") == 0)
        err = chdir(home);
    else
        err = chdir(path);
    return handle_cd_error(shell, err, pwd, path);
}

int my_cd(char **args, shell_t *shell)
{
    if (!args || !shell || !args[0])
        return FAILURE;
    int err = 0;

    if (args[0] != NULL && args[1] != NULL) {
        printf("cd: Too many arguments.\n");
        return 0;
    }
    err = cd(args[0]);
    if (err != SUCCESS) {
        printf("%s: Not a directory.\n", args[0]);
    }
    return SUCCESS;
}
