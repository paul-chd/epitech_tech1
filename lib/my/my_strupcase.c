/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** Changes all lower case letters to upper case
*/
#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 96 && str[i] < 123) {
            str[i] -= 32;
        }
        i ++;
    }
    return (str);
}
