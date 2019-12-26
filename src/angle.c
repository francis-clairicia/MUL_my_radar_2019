/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** angle.c
*/

#include "my_radar.h"

float set_angle_to_range(float angle, float min, float max)
{
    while (angle < min)
        angle += 360.0;
    while (angle >= max)
        angle -= 360.0;
    return (angle);
}