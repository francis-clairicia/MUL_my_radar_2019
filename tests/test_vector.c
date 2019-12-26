/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** test_vector.c
*/

#include <criterion/criterion.h>
#include "my_radar.h"

Test(vector, give_the_vector_formed_by_two_points)
{
    sfVector2f point_a = {1, 1};
    sfVector2f point_b = {12, -5};
    sfVector2f vector_ab = vector(point_a, point_b);

    cr_expect_eq(vector_ab.x, 11);
    cr_expect_eq(vector_ab.y, -6);
}

Test(vector_norm, give_the_norm_of_a_vector)
{
    sfVector2f vector = {10, 10};
    float norm = vector_norm(vector);

    cr_expect_gt(norm, 14.14);
    cr_expect_lt(norm, 14.15);
}

Test(cross_product, calculate_the_product_of_two_vectors)
{
    sfVector2f vector_a = {1, 1};
    sfVector2f vector_b = {-1, -1};

    cr_expect_eq(cross_product(vector_a, vector_b), 0);
}

Test(dot_product, calculate_the_dot_product_of_two_vectors)
{
    sfVector2f vector_a = {5, 3};
    sfVector2f vector_b = {9, 12};

    cr_expect_eq(dot_product(vector_a, vector_b), 81);
}

Test(angle_formed_by_vector, calcualte_the_angle_of_two_vectors)
{
    sfVector2f vector_a = {5, 3};
    sfVector2f vector_b = {9, -15};
    float angle = angle_formed_by_vector(vector_a, vector_b);

    cr_expect_eq((int)(DEGREES(angle)), 90);
}