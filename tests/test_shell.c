/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** integration tests
*/

#include <criterion/criterion.h>
#include "42sh.h"

Test(shell, test_no_env)
{
    char **env = NULL;
    cr_assert_eq(shell(env), 84);
}

Test(shell, test_no_path_env)
{
    char *env[] = {"USER=TOTO", NULL};
    cr_assert_eq(shell(env), 84);
}
