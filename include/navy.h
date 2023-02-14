/*
** EPITECH PROJECT, 2023
** navy
** File description:
** h file for navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <stdio.h>
    #include <time.h>
    #include "my_string.h"
    #include "my_num.h"
    #include "my_arr.h"

    #define SIGPID 11
    #define MY_MAP(x, y) game->board->my_map[y][x]
    #define OPP_MAP(x, y) game->board->opp_map[y][x]

    typedef struct pids_s {
        pid_t my;
        pid_t opp;
        bool connected;
    } pids_t;

    typedef struct board_s {
        int **my_map;
        int **opp_map;
    } board_t;

    typedef struct game_s {
        pids_t *pids;
        board_t *board;
        bool turn;
        bool received_pos;
        bool received_ans;
        bool finished;
    } game_t;

    extern game_t *game;

    int my_getnbr(char const *str);
    char *my_malloc_ini(int nb);
    int my_put_nbr(int nb);
    int my_putstr(char const *str);
    int my_putchar(char c);
    bool error_handling(int ac, char **av);
    int **parsing(char *str);
    void display_board(int **your_map, int **opponent_map);
    bool is_connected(int ac, char **av);
    ssize_t count_bytes(char *path);
    char *read_file(char *path, int size);
    long int file_size(char *file);
    bool in_bounds(int start, int size);
    char *get_input(void);
    board_t *create_board(char *path);
    bool is_hit(int x, int y);
    void send_signal(char *input);
    char *find_mark(int mark);
    void mark_me(int x, int y);
    void mark_guess(int x, int y);
    void get_signal(int sig, siginfo_t *info, void *ucontext);
    pids_t *pids_ini(int ac, char **av);
    bool is_boat(int *row);
    bool end(int **map);
    void wait(bool first);
    int attack(bool *first);
    int game_set(int ac, char **av, char *path);

#endif
