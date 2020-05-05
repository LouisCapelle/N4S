/*
** EPITECH PROJECT, 2020
** com
** File description:
** communication
*/

#include "n4s.h"

void ignore_line()
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    free(line);
    line = NULL;
}

void start_simulation(void)
{
    dprintf(1, "START_SIMULATION\n");
    ignore_line();
}

void end_simulation(void)
{
    dprintf(1, "STOP_SIMULATION\n");
    ignore_line();
}

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