/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** print_result.c
*/

#include "my_radar.h"

void print_result(list_t *airplanes)
{
    airplane_t *airplane;
    int nb_airplanes_landed_on = 0;
    int nb_airplanes_destroyed = 0;

    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        nb_airplanes_landed_on += airplane->land_on;
        nb_airplanes_destroyed += airplane->destroyed;
        airplanes = airplanes->next;
    }
    my_putstr("Airplanes landed on: ");
    my_put_nbr(nb_airplanes_landed_on);
    my_putstr("\nAirplanes destroyed: ");
    my_put_nbr(nb_airplanes_destroyed);
    my_putchar('\n');
}