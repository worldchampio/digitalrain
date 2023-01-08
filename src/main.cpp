#include "DigitalRain.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    initscr();
    curs_set(0);
    start_color();
    int color{COLOR_GREEN}; 
    if(argc == 2)
        color = std::atoi(argv[1]);
    init_pair(1,color >= 0 ? color : COLOR_GREEN,COLOR_BLACK);

    timeout(20);
    attron(COLOR_PAIR(1));
    DigitalRain();
    return endwin();
}