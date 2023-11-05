/*
** EPITECH PROJECT, 2023
** show_b.c
** File description:
** placeholder
*/
#include "../my.h"

int show_b(va_list args, flag_t *flag)
{
    unsigned int nb = va_arg(args, unsigned int);

    return (my_putstr(my_intbin(nb)));
}
