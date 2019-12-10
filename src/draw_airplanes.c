/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** draw_airplanes.c
*/

#include "my_radar.h"

void draw_airplanes(sfRenderWindow *window, list_t *airplanes)
{
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        sfRenderWindow_drawRectangleShape(window, airplane->shape, NULL);
        airplanes = airplanes->next;
    }
}