/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char buffer[4096] = {0};

    dprintf(1, "START_SIMULATION\n");
    read(0, buffer, 4095);
    dprintf(2, "%s", buffer);
    dprintf(1, "GET_INFO_LIDAR\n");
    read(0, buffer, 4095);
    dprintf(2, "%s", buffer);
    dprintf(1, "CAR_FORWARD:1\n");
    read(0, buffer, 4095);
    dprintf(2, "%s", buffer);
    sleep(5);
    dprintf(1, "GET_INFO_LIDAR\n");
    read(0, buffer, 4095);
    dprintf(2, "%s", buffer);
    dprintf(1, "STOP_SIMULATION\n");
    read(0, buffer, 4095);
    dprintf(2, "%s", buffer);
    return 0;
}