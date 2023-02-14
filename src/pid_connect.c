/*
** EPITECH PROJECT, 2023
** pid_connect
** File description:
** deals with the connection of the program
*/

#include "navy.h"

bool is_connection_valid(pid_t pid)
{
    if (kill(pid, 0) == -1)
        return (false);
    return (true);
}

bool player1_pid(void)
{
    write(1, "waiting for enemy connection...\n\n", 33);
    while (!game->pids->connected) {
    }
    kill(game->pids->opp, SIGPID);
    write(1, "enemy connected\n", 16);
    return (true);
}

bool player2_pid(char **av)
{
    game->pids->opp = (pid_t) my_getnbr(av[1]);

    if (!is_connection_valid(game->pids->opp))
        return (false);
    kill(game->pids->opp, SIGPID);
    while (!game->pids->connected) {}
    write(1, "successfully connected\n", 24);
    return (true);
}

bool is_connected(int ac, char **av)
{
    if (ac == 2)
        return (player1_pid());
    else
        return (player2_pid(av));
}

pids_t *pids_ini(int ac, char **av)
{
    pids_t *pids = malloc(sizeof(pids_t));

    if (!pids)
        return (NULL);
    pids->my = getpid();
    pids->connected = false;
    write(1, "my_pid: ", 8);
    my_put_nbr((int) pids->my);
    write(1, "\n", 1);
    return (pids);
}
