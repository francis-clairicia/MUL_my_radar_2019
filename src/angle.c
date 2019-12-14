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

float set_angle_to_range(float angle, float min, float max)
{
    while (angle < min)
        angle += 360.0;
    while (angle >= max)
        angle -= 360.0;
    return (angle);
}

float abs_float(float x)
{
    return ((x < 0) ? -x : x);
}