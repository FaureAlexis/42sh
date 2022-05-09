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

/* Shell loop */

int shell(char **env);

/* Error handling */

int check_env(char **env);

#endif /* !SH_H */
