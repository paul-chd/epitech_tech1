/*
** EPITECH PROJECT, 2023
** force_show_sign.c
** File description:
** changes value in flag_t var
*/
#include "../my.h"

void force_show_sign(flag_t *flag)
{
    flag->flags.force_show_sign = true;
    return;
}
