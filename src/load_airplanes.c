/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane.c
*/

#include "my_radar.h"

static void init_airplane_shape(airplane_t *airplane)
{
    sfVector2f shape_size = {20, 20};
    sfVector2f origin = {10, 10};
    sfColor color = sfColor_fromRGB(46, 173, 46);

    sfRectangleShape_setSize(airplane->shape, shape_size);
    airplane->show_sprite = sfTrue;
    sfRectangleShape_setOrigin(airplane->shape, origin);
    sfRectangleShape_setPosition(airplane->shape, airplane->departure);
    airplane->outline = sfTrue;
    sfRectangleShape_setFillColor(airplane->shape, sfTransparent);
    sfRectangleShape_setOutlineColor(airplane->shape, color);
    sfRectangleShape_setOutlineThickness(airplane->shape, 2);
}

static void init_default_airplane_value(airplane_t *airplane)
{
    airplane->angle = 0;
    airplane->rotate_offset = 0;
    airplane->rotation_clock = sfClock_create();
    airplane->delay_clock = sfClock_create();
    airplane->move_clock = sfClock_create();
    airplane->head_for_arrival_clock = sfClock_create();
    airplane->delay_before_readjustement = 0;
    airplane->rotate_side = 0;
    airplane->take_off = sfFalse;
    airplane->land_on = sfFalse;
    airplane->destroyed = sfFalse;
    airplane->head_for_arrival = sfTrue;
}

static airplane_t *create_airplane(char * const *infos)
{
    airplane_t *airplane = malloc(sizeof(airplane_t));

    if (airplane == NULL)
        return (NULL);
    airplane->object = create_object(AIRPLANE);
    airplane->shape = sfRectangleShape_create();
    airplane->departure.x = my_getnbr(infos[1]);
    airplane->departure.y = my_getnbr(infos[2]);
    airplane->arrival.x = my_getnbr(infos[3]);
    airplane->arrival.y = my_getnbr(infos[4]);
    airplane->speed = (float)my_getnbr(infos[5]) / 100;
    airplane->delay = my_getnbr(infos[6]);
    init_airplane_shape(airplane);
    init_default_airplane_value(airplane);
    set_direction_to_arrival(airplane);
    return (airplane);
}

list_t *load_airplanes(char const *script)
{
    list_t *airplanes = NULL;
    char **infos;
    char *line;
    int n;

    while ((n = my_find_char(script, '\n')) >= 0) {
        line = my_strndup(script, n);
        infos = my_str_to_word_array(line);
        free(line);
        if (my_strcmp(infos[0], "A") == 0)
            my_append_to_list(&airplanes, (long)create_airplane(infos));
        my_free_word_array(infos);
        script = &script[n + 1];
    }
    return (airplanes);
}