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
        destroy_object(airplane->object);
        sfRectangleShape_destroy(airplane->shape);
        sfClock_destroy(airplane->delay_clock);
        sfClock_destroy(airplane->move_clock);
        node = node->next;
    }
    my_free_list(airplanes, 1);
}