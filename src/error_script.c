/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** error_script.c
*/

#include "my_radar.h"

static int check_numbers_in_line(char type, char const *line)
{
    int i = 0;
    int nb_space = 0;
    int max_space = (type == 'A') ? 5 : 2;

    while (line[i] != '\0') {
        if (line[i] == ' ' || line[i] == '\t')
            nb_space += 1;
        else if (my_find_char("0123456789", line[i]) < 0)
            return (0);
        i += 1;
    }
    return (nb_space == max_space);
}

static int check_line(char const *line)
{
    if (line[0] != 'A' && line[0] != 'T')
        return (0);
    if (line[1] != ' ' && line[1] != '\t')
        return (0);
    return (check_numbers_in_line(line[0], &line[2]));
}

int error_script(char const *script)
{
    char *line;
    int nb_lines = 0;
    int output;
    int n;

    if (script == NULL)
        return (1);
    while ((n = my_find_char(script, '\n')) >= 0) {
        nb_lines += 1;
        line = my_strndup(script, n);
        output = check_line(line);
        free(line);
        if (output == 0)
            return (1);
        script = &script[n + 1];
    }
    return (!(nb_lines > 0));
}