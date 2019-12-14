/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** main.c
*/

#include "my_radar.h"

static int valid_script(char const *script_path)
{
    int dot = my_find_char(script_path,  '.');

    if (dot < 0)
        return (0);
    return (my_strlen(&script_path[dot + 1]) > 0);
}

static int valid_environment(char **envp)
{
    int i = 0;

    if (envp[0] == NULL)
        return (0);
    while (envp[i] != NULL) {
        if (my_strncmp(envp[i], "DISPLAY", my_strlen("DISPLAY")) == 0)
            return (1);
        i += 1;
    }
    return (0);
}

int main(int ac, char **av, char **envp)
{
    sfRenderWindow *window;
    char *script = NULL;
    int output = 0;

    if ((ac != 2) || !valid_environment(envp) || !valid_script(av[1]))
        return (84);
    script = open_file(av[1], &error_script);
    if (script != NULL) {
        window = create_window("My Radar", 1920, 1080);
        my_radar(window, script);
        sfRenderWindow_destroy(window);
    } else
        output = 84;
    free(script);
    return (output);
}