/*
** EPITECH PROJECT, 2020
** communication
** File description:
** communication
*/

#include "n4s.h"

void ignore_line(void)
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