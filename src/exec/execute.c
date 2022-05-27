/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** execute command
*/

#include <errno.h>
#include <signal.h>
#include "42sh.h"

int is_a_binary(char *binary)
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
    } else {
        fprintf(stderr, ": ");
        fprintf(stderr, "%s", strerror(errno));
        fprintf(stderr, ".\n");
    }
}

int handle_signals(int sig)
{
    switch (sig) {
        case SIGSEGV: printf("Segmentation fault"); return 1;
        case SIGFPE: printf("Floating exception"); return 1;
        case SIGBUS: printf("Bus error"); return 1;
        case SIGABRT: printf("Abort"); return 1;
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

int execute(char *binary, char **args, shell_t *shell)
{
    pid_t pid = fork();
    char *name = malloc(sizeof(char) * sizeof(binary));
    strcpy(name, binary);
    if (is_a_binary(binary) == 0) {
        binary = search_in_path(name, shell);
    }
    if (pid == 0) {
        pid = getpid();
        int err = execve(binary, args, env_to_tab(shell));
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
