/*
** EPITECH PROJECT, 2023
** show_p.c
** File description:
** placeholder
*/
#include "../my.h"
#include <stdlib.h>

int show_p(va_list args, flag_t *flag)
{
    int char_put = 0;
    unsigned long address = va_arg(args, unsigned long);
    char *str = malloc(sizeof(char) * 15);
    char *ptr = my_inthex(address);

    str[0] = '\0';
    char_put = my_putstr(my_strcat(my_strcat(str, "0x"), ptr));
    free(str);
    free(ptr);
    return (char_put);
}
