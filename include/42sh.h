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

/* minishell1 */

typedef struct env_s {
    char *name;
    char *block;
    struct env_s *next;
}env_t;

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
char **parse_args(char *command);
char *parse_binary(char *command);

/* Command execution */

void exec_cmd(char *cmd, shell_t *shell);

/* Generique commands */

env_t *find_nodenv(env_t *env, char *file);
char **creat_array_from_str(char *cmd, const char *sep);
int get_nb_words_comp(char const *str, char pos);
int comp_sep(char c, char pos);

/* Executable */

int exec_cd(env_t *head, int exit, char *buff);
int gets_setenv(env_t *head, int exit, char *buff);
int gets_unsetenv(env_t *head, int exit, char *buff);
int print_env(env_t *head, int exit, char *buff);

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
