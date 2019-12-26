/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** test_line.c
*/

#include <criterion/criterion.h>
#include "my_radar.h"

Test(point_on_line, check_if_a_point_is_on_line)
{
    sfVector2f origin = {0, 0};
    sfVector2f director = {1, 1};
    sfVector2f test_1 = {2, 2};
    sfVector2f test_2 = {-4, -4};
    sfVector2f test_3 = {8, -2};

    cr_expect_eq(point_on_line(origin, director, test_1), 1);
    cr_expect_eq(point_on_line(origin, director, test_2), 1);
    cr_expect_eq(point_on_line(origin, director, test_3), 0);
}

Test(point_on_segment, check_if_a_point_is_on_segment)
{
    sfVector2f point_a = {2, 2};
    sfVector2f point_b = {5, 5};
    sfVector2f test_1 = {3, 3};
    sfVector2f test_2 = {-4, -4};
    sfVector2f test_3 = {124, 124};
    sfVector2f test_4 = {12, 6};

    cr_expect_eq(point_on_segment(point_a, point_b, test_1), 1);
    cr_expect_eq(point_on_segment(point_a, point_b, test_2), 0);
    cr_expect_eq(point_on_segment(point_a, point_b, test_3), 0);
    cr_expect_eq(point_on_segment(point_a, point_b, test_4), 0);
}