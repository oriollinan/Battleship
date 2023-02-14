/*
** EPITECH PROJECT, 2022
** my_int_to_str.c
** File description:
** converts an integer to a string
*/

#include "my_string.h"
#include "my_num.h"

char *my_int_to_str(int nb)
{
    int num = 1;
    int count = 0;
    char *str = malloc(my_intlen(nb) + 1);

    if (nb < 0 && nb >= -2147483648) {
        str[count] = '-';
        nb = (-1) * nb;
    } else if (nb == 0) {
        str[count] = '0';
        count++;
    }
    while ((nb / num) >= 10 && nb <= 214748364)
        num = num * 10;
    while (num >= 1) {
        str[count] = (nb / num) % 10 + 48;
        num = num / 10;
        count++;
    }
    str[count] = '\0';
    return (str);
}
