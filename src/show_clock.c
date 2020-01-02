/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** show_clock.c
*/

#include "my_radar.h"

void show_clock(sfRenderWindow *window, sfClock *clock, sfText *text)
{
    static char time_elapsed[9] = "00:00:00";
    sfTime time = sfClock_getElapsedTime(clock);
    int elapsed = time.microseconds / 1000000;
    int seconds = elapsed % 60;
    int minuts = elapsed / 60;
    int hours = elapsed / 3600;

    if (text == NULL)
        return;
    time_elapsed[0] = (hours / 10) + 48;
    time_elapsed[1] = (hours % 10) + 48;
    time_elapsed[3] = (minuts / 10) + 48;
    time_elapsed[4] = (minuts % 10) + 48;
    time_elapsed[6] = (seconds / 10) + 48;
    time_elapsed[7] = (seconds % 10) + 48;
    sfText_setString(text, time_elapsed);
    sfText_setPosition(text, (sfVector2f){1750, 10});
    sfRenderWindow_drawText(window, text, NULL);
}