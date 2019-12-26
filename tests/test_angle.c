/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** test_angle.c
*/

#include <criterion/criterion.h>
#include "my_radar.h"

Test(set_angle_to_range, put_an_angle_into_a_given_range)
{
    cr_expect_eq(set_angle_to_range(5, 0, 360), 5.f);
    cr_expect_eq(set_angle_to_range(365, 0, 360), 5.f);
    cr_expect_eq(set_angle_to_range(-90, 0, 360), 270.f);
}