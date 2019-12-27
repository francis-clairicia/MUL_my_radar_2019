/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.c
*/

#include "my_radar.h"
#include "csfml_spritesheet.h"

static void print_result(list_t *airplanes)
{
    airplane_t *airplane;
    int nb_airplanes_landed_on = 0;
    int nb_airplanes_destroyed = 0;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        nb_airplanes_landed_on += airplane->land_on;
        nb_airplanes_destroyed += airplane->destroyed;
        airplanes = airplanes->next;
    }
    my_putstr("Airplanes landed on: ");
    my_put_nbr(nb_airplanes_landed_on);
    my_putstr("\nAirplanes destroyed: ");
    my_put_nbr(nb_airplanes_destroyed);
    my_putchar('\n');
}

static void draw_all(sfRenderWindow *window, object_t *bg,
    list_t *airplanes, list_t *towers)
{
    draw_object(window, bg);
    draw_towers(window, towers);
    draw_airplanes(window, airplanes);
}

static void analyse_event(sfRenderWindow *window,
    list_t *airplanes, list_t *towers)
{
    sfEvent event;

    move_airplanes(airplanes);
    check_airplane_collision(airplanes);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed
        || (event.type == sfEvtKeyReleased
        && (event.key.code == sfKeyQ || event.key.code == sfKeyEscape)))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased)
            event_switch_sprite(event.key, airplanes, towers);
    }
}

void my_radar(sfRenderWindow *window, char const *script)
{
    object_t *world_map = create_object(WORLD_MAP);
    list_t *airplanes = load_airplanes(script);
    list_t *towers = load_towers(script);
    sfClock *chrono = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        draw_all(window, world_map, airplanes, towers);
        show_clock(window, chrono);
        sfRenderWindow_display(window);
        analyse_event(window, airplanes, towers);
        if (all_airplanes_stopped_flying(airplanes)) {
            print_result(airplanes);
            sfRenderWindow_close(window);
        }
    }
    destroy_object(world_map);
    destroy_airplanes(&airplanes);
    destroy_towers(&towers);
    sfClock_destroy(chrono);
}