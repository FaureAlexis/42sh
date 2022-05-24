/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** header
*/

#ifndef SH_H
#define SH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SUCCESS 0
#define FAILURE 84

/* Prompt themes */
enum theme_e { OH_MY_ZSH, TCSH, EPITECH };

/* Main struct */
typedef struct shell_s {
    enum theme_e prompt_theme;
} shell_t;

/* Shell loop */

int shell(char **env);

/* Error handling */

int check_env(char **env);

/* Prompt management */

void display_zsh(char *pwd);
void display_prompt(shell_t *shell);

/* Command input parsing */
char **get_commands(shell_t *shell);
char **parse_semicolons(char *cmd);
char *clean_string(char *str);

/* My commands */

int my_alias(char **args, shell_t *shell);
int my_cd(char **args, shell_t *shell);
int my_history(char **args, shell_t *shell);
int my_env(char **args, shell_t *shell);
int my_setenv(char **args, shell_t *shell);
int my_unsetenv(char **args, shell_t *shell);
int my_theme(char **args, shell_t *shell);
#endif /* !SH_H */
