/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** event_switch_sprite.c
*/

#include "my_radar.h"

static void switch_tower(sfKeyEvent event, list_t *towers)
{
    tower_t *tower;

    while (towers != NULL) {
        tower = (tower_t *)(towers->data);
        if (event.code == sfKeyL)
            tower->show_area = !(tower->show_area);
        if (event.code == sfKeyS)
            tower->show_sprite = !(tower->show_sprite);
        towers = towers->next;
    }
}

static void switch_airplane(sfKeyEvent event, list_t *airplanes)
{
    airplane_t *airplane;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        if (event.code == sfKeyL)
            airplane->outline = !(airplane->outline);
        if (event.code == sfKeyS)
            airplane->show_sprite = !(airplane->show_sprite);
        airplanes = airplanes->next;
    }
}

void event_switch_sprite(sfKeyEvent event, list_t *airplanes, list_t *towers)
{
    switch_airplane(event, airplanes);
    switch_tower(event, towers);
}