/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.c
*/

#include "my_radar.h"
#include "csfml_spritesheet.h"

static void init_text(sfText *text, sfFont *font)
{

    if (text == NULL || font == NULL)
        return;
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
}

static void mainloop(sfRenderWindow *window, object_t *world_map,
    list_t *airplanes, list_t *towers)
{
    sfClock *chrono = sfClock_create();
    sfClock *clock_for_fps = sfClock_create();
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./fonts/Darks_Calibri_Remix.ttf");

    init_text(text, font);
    while (sfRenderWindow_isOpen(window)) {
        draw_object(window, world_map);
        draw_towers(window, towers);
        draw_airplanes(window, airplanes);
        show_clock(window, chrono, text);
        show_fps(window, clock_for_fps, text);
        sfRenderWindow_display(window);
        analyse_event(window, airplanes, towers);
    }
    sfClock_destroy(chrono);
    sfClock_destroy(clock_for_fps);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void my_radar(sfRenderWindow *window, char const *script)
{
    object_t *world_map = create_object(WORLD_MAP);
    list_t *airplanes = NULL;
    list_t *towers = NULL;

    load_airplanes_towers(&airplanes, &towers, script);
    mainloop(window, world_map, airplanes, towers);
    destroy_object(world_map);
    destroy_airplanes(&airplanes);
    destroy_towers(&towers);
}