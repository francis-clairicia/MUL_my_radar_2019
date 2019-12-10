/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** csfml_spritesheet.h
*/

#ifndef CSFML_SPRITESHEET
#define CSFML_SPRITESHEET

#include "csfml_object.h"

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
    AIRPLANE
};

static const info_t spritesheet[] = {
    {"img/world_map.jpg", {0, 0, 0, 0}, {0, 0}, 1},
    {"img/airplane.png", {0, 0, 0, 0}, {0, 0}, 1}
};

#endif