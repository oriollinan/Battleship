/*
** EPITECH PROJECT, 2023
** send_signal
** File description:
** sends the signal to the other player
*/

#include "navy.h"

void send_signal(char *input)
{
    struct timespec time = {0, 10000000};
    char *b1 = dec_to_base(2, input[0], 8);
    char *b2 = dec_to_base(2, input[1], 8);
    int ret = 0;

    for (int i = 0; b1[i]; i++) {
        nanosleep(&time, NULL);
        if (b1[i] == '0')
            ret = kill(game->pids->opp, SIGUSR1);
        else
            ret = kill(game->pids->opp, SIGUSR2);
    }
    for (int i = 0; b2[i]; i++) {
        nanosleep(&time, NULL);
        if (b2[i] == '0')
            ret = kill(game->pids->opp, SIGUSR1);
        else
            ret = kill(game->pids->opp, SIGUSR2);
    }
}
