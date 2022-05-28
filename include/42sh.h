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
    #define PIPE_WRITE  1
    #define PIPE_READ   0

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

/* history struct */

typedef struct history_element_s {
    int block;
    char *command;
    struct history_element_s *next;
    struct history_element_s *prev;
} his_element_t;

typedef struct history_list_s {
    his_element_t *first;
    his_element_t *last;
    int size;
} history_t;

/* Main struct */

typedef struct shell_s {
    enum theme_e prompt_theme;
    char **path;

    list_t *env;
    history_t *history;
} shell_t;

/* Command struct */

enum cmd_e { NOTHING, PIPE, OUTPUT, INPUT, ERR };

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
char **env_to_tab(shell_t *shell);
int add_node(shell_t *shell, const char *name, const char *value);
int update_env_value(shell_t *shell, char *name, char *value);
char *get_env_value(shell_t *shell, char *name);
int save_path(shell_t *shell);
char *search_in_path(char *binary_name, shell_t *shell);
/* History management */

void clear_my_history(shell_t *shell);
void add_command_to_history(shell_t *shell, char *command);
int init_history(shell_t *shell);

/* Prompt management */

void display_zsh(char *pwd);
void display_prompt(shell_t *shell);

/* Command input parsing */
char **get_commands(shell_t *shell);
char **parse_semicolons(char *cmd);
char **parse_pipes(char *cmd);
char *clean_string(char *str);
char **parse_args(char *command);
char *parse_binary(char *command);
int my_arrlen(char **array);

/* Command analysis*/

bool is_operator(char *command);
bool is_a_binary(char *binary);
int get_operator_and_index(cmd_t *cmd, char *command);

/* Command execution */

int execution_control(char **cmd, shell_t *shell);
int exec_cmd(char *cmd, shell_t *shell);
int execute(cmd_t *cmd, shell_t *shell);
int call_binary(char *binary, char **args, shell_t *shell);
int my_pipe(char *command, cmd_t *cmd, shell_t *shell);
int redirect(char *command, cmd_t *cmd, shell_t *shell);

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
