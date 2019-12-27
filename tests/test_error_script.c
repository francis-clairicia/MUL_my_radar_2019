/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** test_error_script.c
*/

#include <criterion/criterion.h>
#include "my_radar.h"

Test(valid_script, check_script_path_validity)
{
    cr_expect_eq(valid_script("test.txt"), 1);
    cr_expect_eq(valid_script("test.a"), 1);
    cr_expect_eq(valid_script("./ficher.rdr"), 1);
    cr_expect_eq(valid_script("./folder/"), 0);
    cr_expect_eq(valid_script("folder/"), 0);
    cr_expect_eq(valid_script("script_without_legend"), 0);
    cr_expect_eq(valid_script("fichier.script.txt"), 1);
    cr_expect_eq(valid_script("fichier.script."), 0);
}

Test(error_script, check_script_validity)
{
    cr_expect_eq(error_script("A 1 1 10 10 5 0\n"), 0);
    cr_expect_eq(error_script("A\t1\t1\t10\t10\t5\t0\n"), 0);
    cr_expect_eq(error_script("A-1 1 10 10 5 0\n"), 1);
    cr_expect_eq(error_script("a 1 1 10 10 5 0\n"), 1);
    cr_expect_eq(error_script("A 1 1 10 1b 5 0\n"), 1);
    cr_expect_eq(error_script("A 1 1 10 10 0\n"), 1);
    cr_expect_eq(error_script("A 1 1 10 10 5 0 12\n"), 1);
    cr_expect_eq(error_script("T 5 12 9\n"), 0);
    cr_expect_eq(error_script("T 5 12 -9\n"), 1);
    cr_expect_eq(error_script("T 5 9\n"), 1);
    cr_expect_eq(error_script("t 5 12 9\n"), 1);
    cr_expect_eq(error_script(NULL), 1);
}