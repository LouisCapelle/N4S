/*
** EPITECH PROJECT, 2020
** get info
** File description:
** get info
*/

#include "n4s.h"

void parse_lidar(char *line, data_t *car)
{
    char **tab = NULL;

    tab = my_str_to_word_array(line);
    car->front = atof(tab[19]);
    car->front_left = atof(tab[3]);
    car->front_right = atof(tab[34]);
    car->end = (strcmp(tab[35], "Track Cleared") == 0) ? 1 : 0;
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