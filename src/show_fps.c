/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** show_fps.c
*/

#include "my_radar.h"

void show_fps(sfRenderWindow *window, sfClock *clock, sfText *text)
{
    static char str_fps[7] = "00 FPS";
    static int fps = 0;
    static int count = 0;

    if (elapsed_time(1000, clock)) {
        fps = count;
        count = 0;
    } else
        count += 1;
    if (text == NULL)
        return;
    str_fps[0] = (fps / 10) + 48;
    str_fps[1] = (fps % 10) + 48;
    sfText_setString(text, str_fps);
    sfText_setPosition(text, (sfVector2f){20, 10});
    sfRenderWindow_drawText(window, text, NULL);
}