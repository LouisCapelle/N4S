/*
** EPITECH PROJECT, 2020
** com
** File description:
** communication
*/

#include "n4s.h"

void start_simulation(void)
{
    dprintf(1, "START_SIMULATION\n");
}

void end_simulation(void)
{
    dprintf(1, "STOP_SIMULATION\n");
}

void move_forward(float speed)
{
    dprintf(1, "CAR_FORWARD:%.1f\n", speed);
}

void change_wheel(float value)
{
    dprintf(1, "WHEELS_DIR:%.1f\n", value);
}

void parse_lidar(char *result, data_t *car)
{
    float speed = 0.5;
    size_t len = 0;
    char **tab = NULL;

    tab = my_str_to_word_array(result);
    car->front = atof(tab[19]);
    car->front_left = atof(tab[3]);
    car->front_right = atof(tab[34]);
    car->end = (strcmp(tab[35], "Track Cleared") == 0) ? 1 : 0;
    free_tab(tab);
    free(result);
}

void get_info_lidar(data_t *car)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    dprintf(1, "GET_INFO_LIDAR\n");
    parse_lidar(line, car);
}