/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_state.c
*/

#include "my_radar.h"

int all_airplanes_stopped_flying(list_t *airplanes)
{
    airplane_t *airplane;

    if (airplanes == NULL)
        return  (0);
    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        if (!(airplane->take_off))
            return (0);
        if (!(airplane->land_on) && !(airplane->destroyed))
            return (0);
        airplanes = airplanes->next;
    }
    return (1);
}