/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** show_clock.c
*/

#include "my_radar.h"

static char *get_time(int elapsed)
{
    int seconds = elapsed % 60;
    int minuts = elapsed / 60;
    int hours = elapsed / 3600;
    char *time_elapsed = malloc(sizeof(char) * 9);

    if (time_elapsed == NULL)
        return (NULL);
    time_elapsed[0] = (hours / 10) + 48;
    time_elapsed[1] = (hours % 10) + 48;
    time_elapsed[2] = ':';
    time_elapsed[3] = (minuts / 10) + 48;
    time_elapsed[4] = (minuts % 10) + 48;
    time_elapsed[5] = ':';
    time_elapsed[6] = (seconds / 10) + 48;
    time_elapsed[7] = (seconds % 10) + 48;
    time_elapsed[8] = '\0';
    return (time_elapsed);
}

static sfBool text_width(sfText *text)
{
    int nb_chars = my_strlen(sfText_getString(text));
    int char_size = sfText_getCharacterSize(text);

    return ((nb_chars * char_size) - (nb_chars * 30));
}

static void init_text(sfText *text, sfFont *font, char const *str)
{
    sfVector2f origin = {0, 0};
    sfVector2f pos = {1920, 10};

    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 50);
    origin.x = text_width(text);
    sfText_setOrigin(text, origin);
    sfText_setPosition(text, pos);
}

void show_clock(sfRenderWindow *window, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    sfText *text;
    sfFont *font;
    char *time_elapsed = get_time(time.microseconds / 1000000);

    if (time_elapsed == NULL)
        return;
    text = sfText_create();
    font = sfFont_createFromFile("./fonts/Darks_Calibri_Remix.ttf");
    if (text != NULL && font != NULL) {
        init_text(text, font, time_elapsed);
        sfRenderWindow_drawText(window, text, NULL);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
    free(time_elapsed);
}