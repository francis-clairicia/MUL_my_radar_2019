/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.c
*/

#include "my_radar.h"
#include "csfml_spritesheet.h"

static void draw_all(sfRenderWindow *window, object_t *bg,
    list_t *airplanes, list_t *towers)
{
    draw_object(window, bg);
    draw_towers(window, towers);
    draw_airplanes(window, airplanes);
    sfRenderWindow_display(window);
}

static void analyse_event(sfRenderWindow *window, list_t *airplanes)
{
    sfView *view = sfView_copy(sfRenderWindow_getView(window));
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfBool use_default = 0;
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed
        || (event.type == sfEvtKeyReleased
        && (event.key.code == sfKeyQ || event.key.code == sfKeyEscape)))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased)
            event_switch_sprite(event.key, airplanes);
        use_default = handle_view(event, view, mouse_pos);
    }
    if (!use_default)
        sfRenderWindow_setView(window, view);
    else
        sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    sfView_destroy(view);
}

void my_radar(sfRenderWindow *window, char const *script)
{
    object_t *world_map = create_object(WORLD_MAP, 0, 0);
    list_t *airplanes = load_airplanes(script);
    list_t *towers = load_towers(script);
    sfClock *clock = sfClock_create();
    int rotated = 0;

    while (sfRenderWindow_isOpen(window)) {
        draw_all(window, world_map, airplanes, towers);
        analyse_event(window, airplanes);
        move_airplanes(airplanes);
        if (elapsed_time(4000, clock) && !rotated) {
            change_airplane_direction((airplane_t *)(my_node(airplanes, 0)->data), -180, 2);
            change_airplane_direction((airplane_t *)(my_node(airplanes, 1)->data), 45, 3);
            change_airplane_direction((airplane_t *)(my_node(airplanes, 2)->data), -72, 3);
            rotated = 1;
        }
    }
    destroy_object(world_map);
    destroy_airplanes(&airplanes);
    destroy_towers(&towers);
    sfClock_destroy(clock);
}