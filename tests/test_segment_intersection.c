/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** test_segment_intersection.c
*/

#include <criterion/criterion.h>
#include "my_radar.h"

Test(segment_intersection, check_if_two_segments_intersect)
{
    sfVector2f p[2] = {{1, 1}, {10, 10}};
    sfVector2f q[2] = {{-5, -5}, {0, 0}};
    sfVector2f u[2] = {{5, 0}, {5, 15}};

    cr_expect_eq(segment_intersection(p, q), 0);
    cr_expect_eq(segment_intersection(p, u), 1);
}