/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** piep
*/

#include <sys/wait.h>
#include <signal.h>
#include "42sh.h"

void exec_child(char *command, shell_t *shell)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));
    cmd->binary = parse_binary(command);
    cmd->args = parse_args(command);
    if (is_a_binary(cmd->binary)) {
        call_binary(cmd->binary, cmd->args, shell);
    } else {
        execute(cmd, shell);
    }
}

int exec_pipe(shell_t *shell, char *command1, char *command2)
{
    pid_t pid;
    int status = 0;
    int fd[2];
    if (pipe(fd) == -1)
        return FAILURE;
    if ((pid = fork()) < 0)
        return FAILURE;
    if (pid == 0) {
        close(fd[PIPE_WRITE]);
        dup2(fd[PIPE_READ], 0);
        exec_child(command2, shell);
        close(fd[PIPE_READ]);
    } else {
        close(fd[PIPE_READ]);
        dup2(fd[PIPE_WRITE], 1);
        exec_child(command1, shell);
        close(fd[PIPE_WRITE]);
        waitpid(pid, &status, 0);
        kill(pid, SIGKILL);
    }
    return SUCCESS;
}

int my_pipe(char *command, cmd_t *cmd, shell_t *shell)
{
    int len = 0;
    char **pipe_commands = parse_pipes(command);
    if (!pipe_commands)
        return FAILURE;
    len = my_arrlen(pipe_commands);
    printf("Command nb : %d, pipe nb : %d\n", len, len - 1);
    for (int i = 0; i < len - 1; i += 1) {
        exec_pipe(shell, pipe_commands[i], pipe_commands[i + 1]);
    }
}