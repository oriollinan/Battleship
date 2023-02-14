/*
** EPITECH PROJECT, 2023
** board
** File description:
** creates and initiates the board struct
*/

#include "navy.h"

void mark_guess(int x, int y)
{
    OPP_MAP(x, y) = 7;
}

void mark_me(int x, int y)
{
    if (MY_MAP(x, y) > 0 && MY_MAP(x, y) < 6)
        MY_MAP(x, y) = 1;
    else
        MY_MAP(x, y) = 6;
}

char *find_mark(int mark)
{
    char *pos = my_malloc_ini(2);
    char *letter = NULL;
    char *number = NULL;

    for (int j = 0; OPP_MAP(0, j) != -2; j++) {
        for (int i = 0; OPP_MAP(i, j) != -1; i++) {
            letter = (OPP_MAP(i, j) == 7) ? my_int_to_str(i + 1) : letter;
            number = (OPP_MAP(i, j) == 7) ? my_int_to_str(j + 1) : number;
            OPP_MAP(i, j) = (OPP_MAP(i, j) == 7) ? mark : OPP_MAP(i, j);
        }
    }
    letter[0] += 16;
    pos = my_strcat(pos, letter);
    pos = my_strcat(pos, number);
    return (pos);
}

bool is_hit(int x, int y)
{
    if (MY_MAP(x, y) > 0 && MY_MAP(x, y) < 6)
        return (true);
    return (false);
}

board_t *create_board(char *path)
{
    board_t *board = malloc(sizeof(board_t));

    if (!board)
        return (NULL);
    board->my_map = parsing(path);
    if (!board->my_map)
        return (NULL);
    board->opp_map = my_intarr_ini(8, 8);
    if (!board->opp_map)
        return (NULL);
    return (board);
}
