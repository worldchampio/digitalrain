#include "DigitalRain.h"
#include <ncurses.h>
#include <iostream>

int main(int argc, char* argv[])
{
    initscr();
    curs_set(0);
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    
    attron(COLOR_PAIR(1));
    DigitalRain(400, 10);
    getch();
    return endwin();
}