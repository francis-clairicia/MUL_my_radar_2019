/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** load_towers.c
*/

#include "my_radar.h"

static sfBool handle_creation_error(tower_t **tower)
{
    if ((*tower)->object == NULL || (*tower)->area == NULL) {
        if ((*tower)->object != NULL)
            destroy_object((*tower)->object);
        if ((*tower)->area != NULL)
            sfCircleShape_destroy((*tower)->area);
        free(*tower);
        *tower = NULL;
    }
    return (*tower != NULL);
}

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

tower_t *create_tower(char * const *infos)
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
    if (handle_creation_error(&tower))
        init_default_values(tower, pos);
    return (tower);
}