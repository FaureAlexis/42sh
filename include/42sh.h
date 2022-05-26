/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** header
*/

#ifndef SH_H
#define SH_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SUCCESS 0
#define FAILURE 84

/* Prompt themes */
enum theme_e { OH_MY_ZSH, TCSH, EPITECH };

/* env struct */

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
    struct env_s *prev;
} env_t;

typedef struct envlist_s {
    env_t *first;
    env_t *last;
    int size;
} list_t;

/* Main struct */

typedef struct shell_s {
    enum theme_e prompt_theme;
    char **path;
    list_t *env;
} shell_t;

/* Command struct */

enum cmd_e { NOTHING, PIPE, OUTPUT, INPUT };

typedef struct cmd_s {
    char *binary;
    char **args;
    enum cmd_e operator;
    int index;
} cmd_t;

/* Shell loop */

int shell(char **env);

/* Error handling */

int check_env(char **env);

/* Environment management */

int create_env(shell_t *shell, char **env);
int add_node(shell_t *shell, const char *name, const char *value);

/* Prompt management */

void display_zsh(char *pwd);
void display_prompt(shell_t *shell);

/* Command input parsing */
char **get_commands(shell_t *shell);
char **parse_semicolons(char *cmd);
char *clean_string(char *str);
char **parse_args(char *command);
char *parse_binary(char *command);

/* Command analysis*/

bool is_operator(char *command);

/* Command execution */

void exec_cmd(char *cmd, shell_t *shell);

/* My commands */

int my_alias(char **args, shell_t *shell);
int my_cd(char **args, shell_t *shell);
int my_history(char **args, shell_t *shell);
int my_env(char **args, shell_t *shell);
int my_setenv(char **args, shell_t *shell);
int my_unsetenv(char **args, shell_t *shell);
int my_theme(char **args, shell_t *shell);

/* Free memory */
void free_shell(shell_t *shell);
#endif /* !SH_H */
