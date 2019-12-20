/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** load_towers.c
*/

#include "my_radar.h"

static void init_default_values(tower_t *tower, sfVector2f pos)
{
    sfColor color = {0, 0, 155, 255};
    sfVector2f origin = {tower->radius, tower->radius};

    sfCircleShape_setRadius(tower->area, tower->radius);
    sfCircleShape_setOrigin(tower->area, origin);
    set_pos_object(tower->object, pos);
    move_object(tower->object, -25, -50);
    sfCircleShape_setPosition(tower->area, pos);
    sfCircleShape_setOutlineColor(tower->area, color);
    sfCircleShape_setFillColor(tower->area, sfTransparent);
    sfCircleShape_setOutlineThickness(tower->area, 2);
}

static tower_t *create_tower(char * const *infos)
{
    tower_t *tower = malloc(sizeof(tower_t));
    sfVector2f pos;

    if (tower == NULL)
        return (NULL);
    tower->object = create_object(TOWER);
    pos.x = my_getnbr(infos[1]);
    pos.y = my_getnbr(infos[2]);
    tower->radius = 1920.0 * ((float)my_getnbr(infos[3]) / 100.0);
    tower->area = sfCircleShape_create();
    tower->show_area = sfTrue;
    tower->show_sprite = sfTrue;
    init_default_values(tower, pos);
    return (tower);
}

list_t *load_towers(char const *script)
{
    list_t *towers = NULL;
    char **infos;
    char *line;
    int n;

    while ((n = my_find_char(script, '\n')) >= 0) {
        line = my_strndup(script, n);
        infos = my_str_to_word_array(line);
        free(line);
        if (my_strcmp(infos[0], "T") == 0)
            my_append_to_list(&towers, (long)create_tower(infos));
        my_free_word_array(infos);
        script = &script[n + 1];
    }
    return (towers);
}