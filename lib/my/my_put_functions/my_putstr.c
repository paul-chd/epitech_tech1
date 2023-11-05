/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** A function that displays the characters of a string one-by-one.
*/
#include "../my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (i);
}
