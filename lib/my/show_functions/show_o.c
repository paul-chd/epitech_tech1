/*
** EPITECH PROJECT, 2023
** show_o.c
** File description:
** placeholder
*/
#include "../my.h"

int show_o(va_list args, flag_t *flag)
{
    unsigned int nb = va_arg(args, unsigned int);

    return (my_putstr(my_intoct(nb)));
}
