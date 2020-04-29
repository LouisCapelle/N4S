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

void change_wheel(float value)
{
    dprintf(1, "WHEELS_DIR:%.1f\n", value);
    ignore_line();
}

void parse_lidar(char *line, data_t *car)
{
    char **tab = NULL;

    tab = my_str_to_word_array(line);
    car->front = atof(tab[19]);
    car->front_left = atof(tab[3]);
    car->front_right = atof(tab[34]);
    car->middle = (car->front_left + car->front_right) / 2;
    free_tab(tab);
    free(line);
    line = NULL;
}

void get_info_lidar(data_t *car)
{
    char *line = NULL;
    size_t len = 0;

    dprintf(1, "GET_INFO_LIDAR\n");
    getline(&line, &len, stdin);
    parse_lidar(line, car);
}