/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** load_airplanes_towers.c
*/

#include "my_radar.h"

void load_airplanes_towers(list_t **airplanes, list_t **towers,
    char const *script)
{
    char **infos;
    char *line;
    int n;

    while ((n = my_find_char(script, '\n')) >= 0) {
        line = my_strndup(script, n);
        infos = my_str_to_word_array(line);
        free(line);
        if (my_strcmp(infos[0], "A") == 0)
            my_append_to_list(airplanes, (long)create_airplane(infos));
        else
            my_append_to_list(towers, (long)create_tower(infos));
        my_free_word_array(infos);
        script = &script[n + 1];
    }
}