/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** main.c
*/

#include "my_radar.h"

static int print_help(int ac, char **av)
{
    if (ac < 2)
        return (0);
    if (my_strcmp(av[1], "-h") != 0)
        return (0);
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("\t./my_radar [OPTIONS] path_to_script\n");
    my_putstr("\tpath_to_script\tThe path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("\t-h\tPrint the usage and exit\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\t'L' key\t\tenable/disable hitboxes and areas.\n");
    my_putstr("\t'S' key\t\tenable/disable sprites.\n");
    return (1);
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

static int error_handling(int ac, char **av, char **envp)
{
    int error = 0;

    if (!valid_environment(envp)) {
        my_putstr("./my_radar: bad environment\n");
        error = 1;
    } if (ac != 2) {
        my_putstr("./my_radar: bad arguments: ");
        my_put_nbr(ac - 1);
        my_putstr(" given but 1 is required\n");
        error = 1;
    } if (ac == 2 && !valid_script(av[1])) {
        my_putstr("./my_radar: bad arguments: invalid script filepath\n");
        error = 1;
    } if (error)
        my_putstr("retry with -h\n");
    return (error);
}

int main(int ac, char **av, char **envp)
{
    sfRenderWindow *window;
    char *script = NULL;
    int output = 0;

    if (print_help(ac, av))
        return (0);
    if (error_handling(ac, av, envp))
        return (84);
    script = open_file(av[1], &error_script);
    if (script != NULL) {
        window = create_window("My Radar", 1920, 1080);
        my_radar(window, script);
        sfRenderWindow_destroy(window);
    } else {
        my_putstr("./my_radar: bad arguments: invalid script content\n");
        output = 84;
    }
    free(script);
    return (output);
}