/*
** EPITECH PROJECT, 2023
** game
** File description:
** runs the game
*/

#include "navy.h"

game_t *game = NULL;

game_t *game_init(int ac, char **av, char *path)
{
    game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->pids = pids_ini(ac, av);
    if (!game->pids)
        return (NULL);
    if (!is_connected(ac, av))
        return (NULL);
    game->board = create_board(path);
    if (!game->board)
        return (NULL);
    if (ac == 2)
        game->turn = true;
    else
        game->turn = false;
    game->finished = false;
    return (game);
}

int game_start(void)
{
    char *input = NULL;
    bool first = true;

    display_board(game->board->my_map, game->board->opp_map);
    while (game->finished == false && !end(game->board->my_map)) {
        if (attack(&first) == 84)
            return (84);
        wait(first);
    }
    kill(game->pids->opp, SIGINT);
    while (!game->finished) {}
    return (0);
}

int game_set(int ac, char **av, char *path)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &get_signal;
    sigaction(SIGPID, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    game_t *game = game_init(ac, av, path);

    if (!game)
        return (84);
    return (game_start());
}
