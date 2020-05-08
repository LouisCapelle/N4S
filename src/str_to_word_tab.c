/*
** EPITECH PROJECT, 2018
** strtowordtab
** File description:
** take str as paramater and give tab
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *my_strnstr(char *str_given, int leng_word)
{
    char *str = NULL;
    int incre = 0;
    int incre_file = 0;

    str = malloc(sizeof(char) * leng_word + 1);
    if (str == NULL)
        return (NULL);
    while (incre_file <= leng_word) {
        str[incre_file] = '\0';
        ++incre_file;
    }
    while (incre != leng_word) {
        str[incre] = str_given[incre];
        ++incre;
    }
    str[incre] = '\0';
    return (str);
}

int separation(char c)
{
    char separation_choose[4] = ":\n;\0";
    int incre_tab_step = 0;

    while (incre_tab_step != 4) {
        if (separation_choose[incre_tab_step] == c) {
            return (1);
        }
        ++incre_tab_step;
    }
    return (0);
}

int compt_nbr_of_word(char *str)
{
    int i = 0;
    int nbr_of_word = 0;

    while (str != NULL && str[i] != '\0') {
        if (separation(str[i]) == 0 && separation(str[i + 1]) == 1) {
            ++nbr_of_word;
        }
        ++i;
    }
    return (nbr_of_word);
}

char **my_str_to_word_array(char *str)
{
    char **tab =  malloc(sizeof(char *) * (compt_nbr_of_word(str) + 1));
    int incre_tab = 0;
    int leng_word = 0;
    int incre = 0;

    if (tab == NULL)
        return (NULL);
    while (str != NULL && str[incre] != '\0') {
        if (separation(str[incre]) == 0)
            leng_word = leng_word + 1;
        if (separation(str[incre]) == 0 && separation(str[incre + 1]) == 1) {
            tab[incre_tab] = my_strnstr(&str[incre - leng_word + 1],
                leng_word);
            ++incre_tab;
            leng_word = 0;
        }
        ++incre;
    }
    tab[incre_tab] = NULL;
    return (tab);
}
