/*
** EPITECH PROJECT, 2023
** arr_to_int
** File description:
** takes a char ** and turns it into a int **
*/

#include "my_arr.h"
#include "my_string.h"

int biggest_length(char **arr)
{
    int length = 0;
    int tmp = 0;

    for (int j = 0; arr[j]; j++) {
        tmp = my_strlen(arr[j]);
        length = (tmp > length) ? tmp : length;
    }
    return (length);
}

int **arr_to_int(char **arr)
{
    int y = my_arrlen(arr);
    int x = biggest_length(arr);

    int **intarr = my_intarr_ini(x, y);
    for (int j = 0; intarr[j][0] != -2; j++) {
        for (int i = 0; i < x; i++)
            intarr[j][i] = 0;
    }
    return (intarr);
}
