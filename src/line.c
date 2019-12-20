/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** line.c
*/

#include "my_radar.h"

int point_on_line(sfVector2f p_a, sfVector2f u, sfVector2f point_to_check)
{
    float a = u.y;
    float b = -u.x;
    float c = (-1) * (a * p_a.x + b * p_a.y);
    float output = a * point_to_check.x + b * point_to_check.y + c;

    return (abs_float(output) <= 0.5);
}

int point_on_segment(sfVector2f p_a, sfVector2f p_b, sfVector2f p_c)
{
    sfVector2f vector_ab = vector(p_a, p_b);
    sfVector2f vector_ac = vector(p_a, p_c);
    float K_ab;
    float K_ac;

    if (abs_float(vector_product(vector_ab, vector_ac)) > 0.5)
        return (0);
    K_ab = scalar_product(vector_ab, vector_ab);
    K_ac = scalar_product(vector_ab, vector_ac);
    return (K_ac >= 0 && K_ac <= K_ab);
}