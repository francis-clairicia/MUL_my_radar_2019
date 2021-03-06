/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** csfml_spritesheet.h
*/

#ifndef CSFML_SPRITESHEET
#define CSFML_SPRITESHEET

#include <SFML/Graphics.h>

typedef struct info
{
    char const *filepath;
    sfIntRect rect;
    sfVector2f position;
    int nb_sprites;
} info_t;

enum OBJECTS
{
    WORLD_MAP,
    AIRPLANE,
    TOWER
};

static const info_t spritesheet[] = {
    {"img/world_map.jpg", {0, 0, 0, 0}, {0, 0}, 1},
    {"img/airplane.png", {0, 0, 0, 0}, {0, 0}, 1},
    {"img/tower.png", {0, 0, 0, 0}, {0, 0}, 1}
};

#endif