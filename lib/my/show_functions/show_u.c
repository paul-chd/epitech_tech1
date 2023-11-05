/*
** EPITECH PROJECT, 2023
** show_u.c
** File description:
** placeholder
*/
#include "../my.h"

int show_u(va_list args, flag_t *flag)
{
    unsigned int arg = va_arg(args, unsigned int);

    return (my_put_uint(arg));
}
