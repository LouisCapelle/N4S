/*
** EPITECH PROJECT, 2019
** ai
** File description:
** need4stek projet
*/

#include "n4s.h"

float get_speed(data_t *tesla)
{

}

void found_virage(data_t *tesla)
{
    if (tesla->front_left < 100 || tesla->front_right < 100)
        return;
    if (tesla->front_left > tesla->front_right) {
        tesla->direction = 1;
        change_wheel(0.5);
    } else if (tesla->front_right > tesla->front_left) {
        tesla->direction = -1;
        change_wheel(-0.5);
    }
}

void speed_change(data_t *tesla)
{
    float speed = get_speed(tesla);

    move_forward(speed);
    found_virage(tesla);
}