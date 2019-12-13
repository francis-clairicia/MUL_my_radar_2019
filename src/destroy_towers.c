/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** destroy_towers.c
*/

#include "my_radar.h"

void destroy_towers(list_t **towers)
{
    list_t *node = *towers;
    tower_t *tower;

    while (node != NULL) {
        tower = (tower_t *)(node->data);
        sfCircleShape_destroy(tower->area);
        destroy_object(tower->object);
        node = node->next;
    }
    my_free_list(towers, 1);
}