/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** vector.c
*/

#include "my_radar.h"

sfVector2f vector(sfVector2f point_a, sfVector2f point_b)
{
    sfVector2f v;

    v.x = point_b.x - point_a.x;
    v.y = point_b.y - point_a.y;
    return (v);
}

int is_colinear(sfVector2f u, sfVector2f v)
{
    float colinear_factor = (u.x * v.y) - (u.y * v.x);
    float marge = 0.7;

    return (colinear_factor >= -marge && colinear_factor <= marge);
}

int point_on_line(sfVector2f p_a, sfVector2f u, sfVector2f point_to_check)
{
    float a = u.y;
    float b = -u.x;
    float c = (-1) * (a * p_a.x + b * p_a.y);
    float output = a * point_to_check.x + b * point_to_check.y + c;
    float marge = 10;

    return (output >= -marge && output <= marge);
}