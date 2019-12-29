/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** show_fps.c
*/

#include "my_radar.h"

static char *get_fps(int fps)
{
    char *str_fps = malloc(sizeof(char) * 7);

    if (str_fps == NULL)
        return (NULL);
    str_fps[0] = (fps / 10) + 48;
    str_fps[1] = (fps % 10) + 48;
    str_fps[2] = ' ';
    str_fps[3] = 'F';
    str_fps[4] = 'P';
    str_fps[5] = 'S';
    str_fps[6] = '\0';
    return (str_fps);
}

static void print_fps(sfRenderWindow *window, int fps)
{
    char *str_fps = get_fps(fps);
    sfText *text;
    sfFont *font;
    sfVector2f pos = {20, 10};

    if (str_fps == NULL)
        return;
    text = sfText_create();
    font = sfFont_createFromFile("./fonts/Darks_Calibri_Remix.ttf");
    if (text != NULL && font != NULL) {
        sfText_setFont(text, font);
        sfText_setString(text, str_fps);
        sfText_setCharacterSize(text, 50);
        sfText_setPosition(text, pos);
        sfRenderWindow_drawText(window, text, NULL);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
    free(str_fps);
}

void show_fps(sfRenderWindow *window, sfClock *clock)
{
    static int fps = 0;
    static int count = 0;

    if (elapsed_time(1000, clock)) {
        fps = count;
        count = 0;
    } else
        count += 1;
    print_fps(window, fps);
}