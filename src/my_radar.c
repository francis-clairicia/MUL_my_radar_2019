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

static void analyse_event(sfRenderWindow *window,
    list_t *airplanes, list_t *towers)
{
    sfView *view = sfView_copy(sfRenderWindow_getView(window));
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfBool use_default_view = 0;
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed
        || (event.type == sfEvtKeyReleased
        && (event.key.code == sfKeyQ || event.key.code == sfKeyEscape)))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyReleased)
            event_switch_sprite(event.key, airplanes, towers);
        use_default_view = handle_view(event, view, mouse_pos);
    }
    if (!use_default_view)
        sfRenderWindow_setView(window, view);
    else
        sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    sfView_destroy(view);
}

void my_radar(sfRenderWindow *window, char const *script)
{
    object_t *world_map = create_object(WORLD_MAP);
    list_t *airplanes = load_airplanes(script);
    list_t *towers = load_towers(script);
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        draw_all(window, world_map, airplanes, towers);
        analyse_event(window, airplanes, towers);
        move_airplanes(airplanes);
        if (all_airplanes_stopped_flying(airplanes))
            sfRenderWindow_close(window);
    }
    destroy_object(world_map);
    destroy_airplanes(&airplanes);
    destroy_towers(&towers);
    sfClock_destroy(clock);
}