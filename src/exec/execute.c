/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execute command
*/

#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "42sh.h"

static int is_a_bin(char *binary)
{
    if (binary[0] == '.' && binary[1] == '/')
        return 1;
    else
        return 0;
}

void handle_error(char *binary)
{
    fprintf(stderr, "%s", binary);
    if (errno == ENOENT) {
        fprintf(stderr, ": Command not found.\n");
    } else if (errno == ENOEXEC) {
        fprintf(stderr, ": Exec format error. Wrong Architecture.\n");
    } else if (errno == EFAULT) {
        printf("erreur de merde");
    } else {
        fprintf(stderr, ": ");
        fprintf(stderr, "%s", strerror(errno));
        fprintf(stderr, ".\n");
    }
}

int handle_signals(int sig)
{
    switch (sig) {
        case SIGSEGV:
            printf("Segmentation fault");
            return 1;
        case SIGFPE:
            printf("Floating exception");
            return 1;
        case SIGBUS:
            printf("Bus error");
            return 1;
        case SIGABRT:
            printf("Abort");
            return 1;
        default: return 0;
    }
}

void handle_return(int status)
{
    int sig = WTERMSIG(status);
    bool crash = false;

    if (!WIFSIGNALED(status))
        return;
    if (handle_signals(sig) == 1)
        crash = true;
    if (crash && WCOREDUMP(status))
        printf(" (core dumped)");
    printf("\n");
}

int execute(cmd_t *cmd, shell_t *shell, char **env)
{
    char *name = malloc(sizeof(char) * strlen(cmd->binary) + 20);
    strcpy(name, cmd->binary);
    if (is_a_bin(cmd->binary) == 0) {
        cmd->binary = search_in_path(name, shell);
        if (!cmd->binary) {
            fprintf(stderr, "%s: Command not found.\n", name);
            return FAILURE;
        }
    }
    pid_t pid = fork();
    if (pid == 0) {
        pid = getpid();
        int err = execve(cmd->binary, cmd->args, env);
        if (err != 0) {
            handle_error(name);
        }
    } else if (pid == -1) {
        fprintf(stderr, "Error : Unable to fork child process\n");
        return FAILURE;
    } else {
        int status;
        waitpid(pid, &status, 0);
        kill(pid, SIGKILL);
        handle_return(status);
    }
    return SUCCESS;
}
