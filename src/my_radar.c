/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.c
*/

#include "my_radar.h"

static void analyse_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void my_radar(sfRenderWindow *window)
{
    object_t *world_map = create_object(WORLD_MAP, 1920, 1080);
    object_t *airplane = create_object(AIRPLANE, 40, 40);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        draw_object(window, world_map);
        draw_object(window, airplane);
        analyse_event(window);
        sfRenderWindow_display(window);
    }
    destroy_object(world_map);
    destroy_object(airplane);
}