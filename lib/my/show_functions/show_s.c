/*
** EPITECH PROJECT, 2023
** show_s.c
** File description:
** Prints given str arg
*/
#include "../my.h"

int show_s(va_list args, flag_t *flag)
{
    char *str = va_arg(args, char *);

    return (my_putstr(str));
}
