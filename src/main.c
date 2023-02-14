/*
** EPITECH PROJECT, 2023
** main
** File description:
** main file for navy
*/

#include "navy.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av))
        return (84);
    if (ac == 3)
        return (game_set(ac, av, av[2]));
    else
        return (game_set(ac, av, av[1]));
}
