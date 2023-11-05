/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Shows text in the terminal
*/
#include "../my.h"
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
