/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** cd
*/

#include "42sh.h"

static env_t *change_pwd(env_t *pwd, char *name, env_t *env)
{
    char *buff = malloc(sizeof(char) * 201);
    char *file = NULL;

    getcwd(buff, 200);
    if (pwd == NULL) {
        file = strcat(name, buff);
        pwd = create_node_from_str(file);
        free(file);
        env = add_node_to_list(env, pwd);
        free(buff);
        return pwd;
    }
    free(pwd->block);
    pwd->block = strcat("", buff);
    free(buff);
    return pwd;
}

static int cd_flag_neg(env_t *node, env_t *pwd, env_t *env)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (strlen(pwd->block) + 1));

    str = strcpy(str, pwd->block);
    for (int i = (get_nb_words_pos(pwd->block, '/')); i > 0; i -= 1) {
        chdir("..");
    }
    i = chdir(node->block);
    pwd = change_pwd(pwd, "PWD=", env);
    free(node->block);
    node->block = my_strcat(str, "\0");
    free(str);
    return i;
}

static int cd(char **array, env_t *env)
{
    env_t *pwd = find_nodenv(env, "PWD\0");
    env_t *oldpwd = find_nodenv(env, "OLDPWD\0");
    env_t *home = find_nodenv(env, "HOME\0");
    char **result = NULL;
    int i = 0;

    if ((array[1] == NULL && strcmp(array[0], "cd ") == 0) ||
    (strcmp(array[1], "~") == 0 && strlen(array[1]) == 1)) {
        i = cd_flag_neg(home, pwd, env);
        return i;
    } else if (strcmp(array[1], "-") == 0 && strlen(array[1]) == 1) {
        i = cd_flag_neg(oldpwd, pwd, env);
        return i;
    } else {
        oldpwd = change_pwd(oldpwd, "OLDPWD=", env);
        i = chdir(array[1]);
        pwd = change_pwd(pwd, "PWD=", env);
        return i;
    }
}

int exec_cd(env_t *head, int exit, char *buff)
{
    char **array = create_array_from_str(buff, " ");
    int i = 0;

    if (array[1] != NULL && array[2] != NULL) {
        putstr("cd: Too many arguments.\n");
        return 0;
    }
    i = cd(array, head);
    if (i != 0) {
        printf("%s: Not a directory.\n", array[1]);
    }
    array_free(array);
    return 0;
}
