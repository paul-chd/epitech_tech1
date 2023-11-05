/*
** EPITECH PROJECT, 2023
** my_put_unsignedint.c
** File description:
** Prints an unsigned int
*/
#include "../my.h"

static int power(int a, int b)
{
    int result = 1;

    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return (result);
}

static int digit_to_ascii(int dig)
{
    dig += 48;
    return (dig);
}

static int show_int(long num)
{
    long num2 = num;
    int num_o_d = 0;

    while (num != 0) {
        num = num / 10;
        num_o_d += 1;
    }
    for (num_o_d; num_o_d != 0; num_o_d -= 1) {
        my_putchar(digit_to_ascii(num2 / power(10, (num_o_d - 1))));
        num2 -= (num2 / power(10, num_o_d - 1)) * power(10, num_o_d - 1);
    }
    return (num_o_d);
}

int my_put_uint(unsigned int nb)
{
    long cp_nb = nb;

    if (cp_nb < 0) {
        my_putchar(45);
        cp_nb *= -1;
    }
    if (cp_nb == 0) {
        my_putchar(48);
    } else {
        show_int(cp_nb);
    }
    return (0);
}
