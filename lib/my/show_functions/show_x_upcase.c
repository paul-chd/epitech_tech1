/*
** EPITECH PROJECT, 2023
** show_X.c
** File description:
** placeholder
*/
#include "../my.h"

int show_x_upcase(va_list args, flag_t *flag)
{
    unsigned int nb = va_arg(args, unsigned int);

    return (my_putstr(my_strupcase(my_inthex(nb))));
}
