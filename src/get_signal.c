/*
** EPITECH PROJECT, 2023
** receive_signal
** File description:
** receives the signal from the other player
*/

#include "navy.h"

void hit_miss_me(char bytes[])
{
    if (is_hit(bytes[0] - 'A', bytes[1] - '0' -1)) {
        mark_me(bytes[0] - 'A', bytes[1] - '0' -1);
        send_signal(my_strdup("hh"));
        my_putstr(bytes);
        write(1, ": hit\n\n", 7);
        game->received_pos = true;
        return;
    } else {
        mark_me(bytes[0] - 'A', bytes[1] - '0' -1);
        send_signal(my_strdup("mm"));
        my_putstr(bytes);
        write(1, ": missed\n\n", 10);
        game->received_pos = true;
        return;
    }
}

void hit_or_miss(char bytes[])
{
    char *pos = NULL;

    if (bytes[0] == 'h') {
        pos = find_mark(1);
        my_putstr(pos);
        write(1, ": hit\n\n", 7);
        game->received_ans = true;
        return;
    }
    if (bytes[0] == 'm') {
        pos = find_mark(6);
        my_putstr(pos);
        write(1, ": missed\n\n", 10);
        game->received_ans = true;
        return;
    }
    hit_miss_me(bytes);
}

void sigusr(int bit)
{
    static int bits = 0;
    static int pos = 0;
    static char bytes[2] = "\0\0";

    if (bit != 0)
        bytes[pos] = bytes[pos] | my_compute_power_rec(2, 7 - bits);
    bits++;
    if (bits > 7) {
        pos++;
        bits = 0;
    }
    if (pos == 2) {
        pos = 0;
        hit_or_miss(bytes);
        bytes[0] = '\0';
        bytes[1] = '\0';
    }
}

void sigint(void)
{
    display_board(game->board->my_map, game->board->opp_map);
    if (end(game->board->my_map))
        write(1, "Enemy won\n", 10);
    else
        write(1, "I won\n", 6);
    game->finished = true;
}

void get_signal(int sig, siginfo_t *info, void *ucontext)
{
    switch (sig) {
        case SIGPID:
            game->pids->opp = info->si_pid;
            game->pids->connected = true;
            break;
        case SIGUSR1:
            sigusr(0);
            break;
        case SIGUSR2:
            sigusr(1);
            break;
        case SIGINT:
            sigint();
            break;
        default:
            break;
    }
}
