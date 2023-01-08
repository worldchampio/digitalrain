#include "DigitalRain.h"
#include <ncurses.h>
#include <iostream>

int main(int argc, char* argv[])
{
    initscr();
    curs_set(0);
    start_color();
    int color{COLOR_GREEN}; 
    if(argc == 2){
        try
        {
            color = std::atoi(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            color = COLOR_GREEN;
        }
        
    }
    init_pair(1,color,COLOR_BLACK);

    timeout(20);

    attron(COLOR_PAIR(1));
    DigitalRain();
    return endwin();
}