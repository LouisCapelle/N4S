/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** return lenght of a string
*/

#include "n4s.h"

int	my_strlen(char *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0'){
        i = i +  1;
    }
    return i;
}
