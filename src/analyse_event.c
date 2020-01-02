/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** analyse_event.c
*/

#include "my_radar.h"

void analyse_event(sfRenderWindow *window, list_t *airplanes, list_t *towers)
{
    sfEvent event;

    move_airplanes(airplanes);
    check_airplane_on_tower(airplanes, towers);
    check_airplane_collision(airplanes);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed
        || (event.type == sfEvtKeyReleased
        && (event.key.code == sfKeyQ || event.key.code == sfKeyEscape)))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased)
            event_switch_sprite(event.key, airplanes, towers);
    }
    if (all_airplanes_stopped_flying(airplanes)) {
        print_result(airplanes);
        sfRenderWindow_close(window);
    }
}