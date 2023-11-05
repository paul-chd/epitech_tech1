/*
** EPITECH PROJECT, 2023
** test
** File description:
** dblstr
*/
#include <criterion/criterion.h>
#include "../lib/my/my.h"

Test(normal, precision_two)
{
    double nb = 3.453789;
    int precision = 2;
    char *str = my_dblstr(nb, precision);

    my_putstr(str);
    cr_assert_str_eq(str, "3.45");
}

Test(normal, specific_case)
{
    double nb = 4.2;
    int precision = 2;
    char *str = my_dblstr(nb, precision);

    my_putstr(str);
    cr_assert_str_eq(str, "4.20");
}
