/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane.c
*/

#include <math.h>
#include "my_radar.h"

void calculate_airplane_direction(airplane_t *airplane)
{
    sfVector2f director_v = {
        airplane->arrival.x - airplane->departure.x,
        airplane->arrival.y - airplane->departure.y
    };
    double norm_v = sqrt(pow(director_v.x, 2) + pow(director_v.y, 2));
    double angle = acos(director_v.x / norm_v);
    int angle_in_degrees = angle * 180 / acos(-1);

    airplane->direction.x = cos(angle);
    airplane->direction.y = sin(angle);
    airplane->angle = angle_in_degrees;
    while (sfRectangleShape_getRotation(airplane->shape) != angle_in_degrees)
        sfRectangleShape_rotate(airplane->shape, 1);
}

static void init_airplane_shape(airplane_t *airplane)
{
    sfVector2u sprite_size = sfTexture_getSize(airplane->texture);
    sfVector2f shape_size = {sprite_size.x, sprite_size.y};
    sfVector2f origin = {sprite_size.x / 2, sprite_size.y / 2};

    sfRectangleShape_setSize(airplane->shape, shape_size);
    sfRectangleShape_setTexture(airplane->shape, airplane->texture, sfFalse);
    airplane->show_sprite = sfTrue;
    sfRectangleShape_setOrigin(airplane->shape, origin);
    sfRectangleShape_setPosition(airplane->shape, airplane->departure);
    airplane->outline_color = sfColor_fromRGB(46, 173, 46);
    airplane->outline = sfTrue;
    sfRectangleShape_setOutlineColor(airplane->shape, airplane->outline_color);
    sfRectangleShape_setOutlineThickness(airplane->shape, 2);
}

static airplane_t *create_airplane(char * const *infos)
{
    airplane_t *airplane = malloc(sizeof(airplane_t));
    char const *img = spritesheet[AIRPLANE].filepath;

    if (airplane == NULL)
        return (NULL);
    airplane->shape = sfRectangleShape_create();
    airplane->texture = sfTexture_createFromFile(img, NULL);
    airplane->departure.x = my_getnbr(infos[1]);
    airplane->departure.y = my_getnbr(infos[2]);
    airplane->arrival.x = my_getnbr(infos[3]);
    airplane->arrival.y = my_getnbr(infos[4]);
    airplane->speed = my_getnbr(infos[5]);
    init_airplane_shape(airplane);
    calculate_airplane_direction(airplane);
    airplane->delay = my_getnbr(infos[6]) * 1000;
    airplane->rotation_clock = sfClock_create();
    airplane->delay_clock = sfClock_create();
    airplane->rotate_side = 0;
    airplane->fly = sfFalse;
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