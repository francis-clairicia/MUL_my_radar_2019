/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** destroy_airplanes.c
*/

#include "my_radar.h"

void destroy_airplanes(list_t **airplanes)
{
    list_t *node = *airplanes;
    airplane_t *airplane;

    while (node != NULL) {
        airplane = (airplane_t *)(node->data);
        sfRectangleShape_destroy(airplane->shape);
        sfTexture_destroy(airplane->texture);
        sfClock_destroy(airplane->rotation_clock);
        sfClock_destroy(airplane->delay_clock);
        node = node->next;
    }
    my_free_list(airplanes, 1);
}