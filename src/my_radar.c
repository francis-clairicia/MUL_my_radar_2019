/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.c
*/

#include "my_radar.h"
#include "csfml_spritesheet.h"

static void draw_all(sfRenderWindow *window, object_t *bg, list_t *airplanes)
{
    draw_object(window, bg);
    draw_airplanes(window, airplanes);
    sfRenderWindow_display(window);
}

static void analyse_event(sfRenderWindow *window, list_t *airplanes)
{
    sfView *view = sfView_copy(sfRenderWindow_getView(window));
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased)
            event_switch_sprite(event.key, airplanes);
        handle_view(event, view, mouse_pos);
    }
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}

void my_radar(sfRenderWindow *window, char const *script)
{
    object_t *world_map = create_object(WORLD_MAP, 0, 0);
    list_t *airplanes = load_airplanes(script);
    sfClock *clock = sfClock_create();
    int rotate = 0;

    while (sfRenderWindow_isOpen(window)) {
        draw_all(window, world_map, airplanes);
        analyse_event(window, airplanes);
        move_airplanes(airplanes);
        if (elapsed_time(4000, clock) && !rotate) {
            change_airplane_direction((airplane_t *)(my_node(airplanes, 0)->data), -180);
            change_airplane_direction((airplane_t *)(my_node(airplanes, 1)->data), 45);
            change_airplane_direction((airplane_t *)(my_node(airplanes, 2)->data), -72);
            rotate = 1;
        }
    }
    destroy_object(world_map);
    destroy_airplanes(&airplanes);
    sfClock_destroy(clock);
}