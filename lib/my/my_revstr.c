/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** A function that reverses a string
*/
#include "my.h"

char *my_revstr(char *str)
{
    int j;
    int start;
    int end;
    int temp;

    start = 0;
    end = my_strlen(str) - 1;
    for (j = 0; j < my_strlen(str) / 2; j++) {
        temp = str[start + j];
        str[start + j] = str[end - j];
        str[end - j] = temp;
    }
    return str;
}
