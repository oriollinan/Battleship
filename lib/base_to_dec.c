/*
** EPITECH PROJECT, 2023
** 64_to_dec.c
** File description:
** from base 64 to dec
*/

#include "my_num.h"
#include "my_string.h"

const char s_d[65] =
"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

int base_to_dec(int base, char *nb)
{
    int i = 0;
    int dec = 0;
    int iter = 0;

    for (int x = my_strlen(nb) - 1; x >= 0; x--) {
        i = 0;
        while (s_d[i] && s_d[i] != nb[x])
            i++;
        if (s_d[i])
            dec += i * my_compute_power_rec(base, iter);
        iter++;
    }
    return (dec);
}
