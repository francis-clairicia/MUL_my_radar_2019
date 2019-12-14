/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** angle.c
*/

#include "my_radar.h"

float to_degrees(float radians)
{
    return (radians * 180 / M_PI);
}

float to_radians(float degrees)
{
    return (degrees * M_PI / 180);
}

float conditionate_angle(float angle)
{
    while (angle < 0)
        angle += 360;
    while (angle >= 360)
        angle -= 360;
    return (angle);
}

float abs_float(float x)
{
    return ((x < 0) ? -x : x);
}