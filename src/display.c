/*
** EPITECH PROJECT, 2023
** display
** File description:
** handles the display of my_navy
*/

#include "navy.h"

void display_line(int nb, int i)
{
    switch (nb) {
        case 0:
            write(1, ".", 1);
            break;
        case 1:
            write(1, "x", 1);
            break;
        case 6:
            write(1, "o", 1);
            break;
        case 7:
            write(1, ".", 1);
            break;
        default:
            my_put_nbr(nb);
    }
    if (i != 7)
        write(1, " ", 1);
    else
        write(1, "\n", 1);
}

void display_map(int **map)
{
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int j = 0; map[j][0] != -2; j++) {
        my_put_nbr(j + 1);
        write(1, "|", 1);
        for (int i = 0; map[j][i] != -1; i++)
            display_line(map[j][i], i);
    }
}

void display_board(int **your_map, int **opponent_map)
{
    write(1, "my positions:\n", 14);
    display_map(your_map);
    write(1, "\nenemy's positions:\n", 21);
    display_map(opponent_map);
    write(1, "\n", 1);
}
