/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** airplane_state.c
*/

#include "my_radar.h"

sfBool all_airplanes_stopped_flying(list_t *airplanes)
{
    airplane_t *airplane;

    if (airplanes == NULL)
        return (sfFalse);
    while (airplanes != NULL) {
        airplane = (airplane_t *)(airplanes->data);
        airplanes = airplanes->next;
        if (airplane == NULL)
            continue;
        if (!(airplane->take_off))
            return (sfFalse);
        if (!(airplane->land_on) && !(airplane->destroyed))
            return (sfFalse);
    }
    return (sfTrue);
}