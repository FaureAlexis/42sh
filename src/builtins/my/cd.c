/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** cd command
*/

#include "42sh.h"

int handle_cd_error(shell_t *shell, int err, char *pwd)
{
    char *npwd = NULL;
    if (err == SUCCESS) {
        update_env_value(shell, "OLDPWD", pwd);
        npwd = getcwd(npwd, 0);
        return update_env_value(shell, "PWD", npwd);
    } else {
        return FAILURE;
    }
}

int change_directory(shell_t *shell, char *path, char *pwd, char *oldpwd)
{
    if (!path)
        return FAILURE;
    int err = SUCCESS;
    
    if (!pwd || !oldpwd)
        return FAILURE;
    err = chdir(path);
    err = handle_cd_error(shell, err, pwd);
    if (err != SUCCESS) {
        printf("%s: Not a directory.\n", path);
    }
    return err;
}

int my_cd(char **args, shell_t *shell)
{
    char *path = NULL;

    if (!args || !shell || !args[1])
        return FAILURE;
    char *pwd = get_env_value(shell, "PWD");
    char *oldpwd = get_env_value(shell, "OLDPWD");
    char *home = get_env_value(shell, "HOME");
    if (args[1] != NULL && args[2] != NULL) {
        printf("cd: Too many arguments.\n");
        return FAILURE;
    }
    if (strcmp(args[1], "-") == 0)
        path = oldpwd;
    else if (strcmp(args[1], "~") == 0)
        path = home;
    else
        path = args[1];
    return change_directory(shell, path, pwd, oldpwd);
}
