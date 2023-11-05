/*
** EPITECH PROJECT, 2023
** my_intoct
** File description:
** changes an unsigned int into its hex value
*/
#include "../my.h"
#include <stdlib.h>

char *my_intoct(unsigned long num)
{
    char *result = malloc(sizeof(char) * 10);
    int remainder;
    const char values[] = {
        '0', '1', '2', '3',
        '4', '5', '6', '7'
    };
    int i = 0;

    for (num; num > 0; num = num / 8) {
        remainder = num % 8;
        result[i] = values[remainder];
        i++;
    }
    result[i] = '\0';
    my_revstr(result);
    return (result);
}
