/*
** EPITECH PROJECT, 2023
** status
** File description:
** check game status
*/

#include "navy.h"

bool is_boat(int *row)
{
    for (int i = 0; row[i] != -1; i++) {
        if (row[i] > 1 && row[i] < 6)
            return (true);
    }
    return (false);
}

bool end(int **map)
{
    for (int j = 0; map[j][0] != -2; j++) {
        if (is_boat(map[j]))
            return (false);
    }
    return (true);
}

int attack(bool *first)
{
    char *input = NULL;

    if (game->turn && !game->finished) {
        write(1, "attack: ", 8);
        input = get_input();
        if (!input)
            return (84);
        if (in_bounds(input[0] - 'A' + 1, 0) &&
        in_bounds(input[1] - '0' + 1, 0)) {
            mark_guess(input[0] - 'A', input[1] - '0' -1);
            send_signal(input);
            game->turn = false;
            *first = false;
        } else
            write(1, "wrong position\n", 15);
    }
    return (0);
}

void not_first(void)
{
    struct timespec time = {0, 10000000};

    game->received_ans = false;
    while (!game->received_ans && !game->finished) {}
    nanosleep(&time, NULL);
    if (!game->finished)
        display_board(game->board->my_map, game->board->opp_map);
}

void wait(bool first)
{
    if (!game->turn && !game->finished) {
        if (!first && !game->finished)
            not_first();
        if (!game->finished)
            write(1, "waiting for enemy's attack...\n", 30);
        game->received_pos = false;
        while (!game->received_pos && !game->finished) {}
        game->turn = true;
    }
}
