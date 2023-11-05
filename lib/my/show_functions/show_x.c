/*
** EPITECH PROJECT, 2023
** show_x.c
** File description:
** placeholder
*/
#include "../my.h"

int show_x(va_list args, flag_t *flag)
{
    unsigned int nb = va_arg(args, unsigned int);

    return (my_putstr(my_inthex(nb)));
}
