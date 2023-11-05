/*
** EPITECH PROJECT, 2023
** show_c.c
** File description:
** Prints a character in stdout depending on the va_list given
*/
#include "../my.h"

int show_c(va_list args, flag_t *flag)
{
    char x = 0;

    x = va_arg(args, int);
    return (my_putchar(x));
}
