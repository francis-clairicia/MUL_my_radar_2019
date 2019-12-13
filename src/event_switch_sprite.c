/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** event_switch_sprite.c
*/

#include "my_radar.h"

void event_switch_sprite(sfKeyEvent event, list_t *airplanes)
{
    airplane_t *airplane;
    int outline;
    sfColor f_color;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        if (event.code == sfKeyL)
            airplane->outline = !(airplane->outline);
        if (event.code == sfKeyS)
            airplane->show_sprite = !(airplane->show_sprite);
        f_color = (airplane->show_sprite) ? sfWhite : sfTransparent;
        outline = 2 * (airplane->outline);
        sfRectangleShape_setFillColor(airplane->shape, f_color);
        sfRectangleShape_setOutlineThickness(airplane->shape, outline);
        airplanes = airplanes->next;
    }
}