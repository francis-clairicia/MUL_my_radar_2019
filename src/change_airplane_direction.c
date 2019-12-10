/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** change_airplane_direction.c
*/

#include "my_radar.h"

void change_airplane_direction(airplane_t *airplane, int angle_direction)
{
    airplane->angle += angle_direction;
    while (airplane->angle < 0)
        airplane->angle += 360;
    while (airplane->angle > 360)
        airplane->angle -= 360;
    airplane->rotate_side = angle_direction / abs(angle_direction);
}