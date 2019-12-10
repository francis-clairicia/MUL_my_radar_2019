/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.c
*/

#include "my_radar.h"
#include "csfml_spritesheet.h"

static void analyse_event(sfRenderWindow *window, list_t *airplanes)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased)
            event_switch_sprite(event.key, airplanes);
    }
}

void my_radar(sfRenderWindow *window, char const *script)
{
    object_t *world_map = create_object(WORLD_MAP, 0, 0);
    list_t *airplanes = load_airplanes(script);
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        draw_object(window, world_map);
        draw_airplanes(window, airplanes);
        sfRenderWindow_display(window);
        analyse_event(window, airplanes);
        move_airplanes(airplanes);
    }
    destroy_object(world_map);
    destroy_airplanes(&airplanes);
    sfClock_destroy(clock);
}