/*
** EPITECH PROJECT, 2019
** initscr function
** File description:
** Inits ncurses screen
*/

#include "NcursesDisplay.hpp"
#include <ncurses.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h>
#include <cstring>
void initCurses()
{
    /*int startx, starty = 0;
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    WINDOW **board = new WINDOW*[6];
    initscr();
    cbreak();
    keypad(stdscr, true);
    board = initWindows(board);
    for (int i = 0; i < 6; i++) {
        box(board[i], 0, 0);
        wrefresh(board[i]);
    }
    mvwprintw(board[0], 1, (size.ws_col / 3) - strlen("USER@HOST") / 3, "USER@HOST");
    mvwprintw(board[0], 1, (size.ws_col / 3) * 1.5 - strlen("USER@HOST") / 3, "USER@HOST");
    mvwprintw(board[0], 1, (size.ws_col / 3) * 2 - strlen("USER@HOST") / 3, "USER@HOST");
    //mvwprintw(board[0], 1, (size.ws_col / 3), "USER@HOST");

    wrefresh(board[0]);
    getch();
    noecho();*/

}

WINDOW **initWindows(WINDOW **board)
{
    int startx = 0, starty = 0;
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    board[0] = newwin(4, size.ws_col, startx, starty);
    starty += 4;
    refresh();
    board[1] = newwin((size.ws_row / 2) - 4, size.ws_col / 2, starty, startx);
    startx = size.ws_col / 2;
    refresh();
    board[2] = newwin((size.ws_row / 2) - 4, size.ws_col / 2, starty, startx);
    startx = 0;
    starty += size.ws_row / 2 - 4 ;
    refresh();
    board[3] = newwin((size.ws_row / 2), size.ws_col / 3, starty, startx);
    startx += size.ws_col / 3;
    refresh();
    board[4] = newwin((size.ws_row / 2), size.ws_col / 3, starty, startx);
    startx += size.ws_col / 3;
    refresh();
    board[5] = newwin((size.ws_row / 2), size.ws_col / 3, starty, startx);
    startx += size.ws_col / 3;
    refresh();
    return (board);
}
