/*
** EPITECH PROJECT, 2020
** com
** File description:
** communication
*/

#include "n4s.h"

void move_forward(float speed)
{
    dprintf(1, "CAR_FORWARD:%.1f\n", speed);
    ignore_line();
}

void move_backward(float speed)
{
    dprintf(1, "CAR_BACKWARDS:%.1f\n", speed);
    ignore_line();
}

void change_wheel(float value)
{
    dprintf(1, "WHEELS_DIR:%.1f\n", value);
    ignore_line();
}