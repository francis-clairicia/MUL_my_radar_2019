/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** my_radar.h
*/

#ifndef HEADER_MY_RADAR
#define HEADER_MY_RADAR

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "csfml.h"
#include "my.h"
#include "mylist.h"

typedef struct airplane_infos
{
    sfVector2f departure;
    sfVector2f arrival;
    unsigned int speed;
    unsigned int delay;
} airplane_infos_t;

typedef struct control_tower_infos
{
    sfVector2f position;
    unsigned int radius;
} tower_infos_t;

void my_radar(sfRenderWindow *window);
int error_script(char const *script);

#endif