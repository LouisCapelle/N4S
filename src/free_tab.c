/*
** EPITECH PROJECT, 2019
** free tab
** File description:
** free a char **
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    int incre = 0;

    while (tab[incre] != NULL)
        free(tab[incre++]);
}
