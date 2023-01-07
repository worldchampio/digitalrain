#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <random>

int rng(int min=44, int max=123) 
{
    std::random_device  dev;
    std::mt19937        rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
    return dist6(rng);
}

std::string int2Str(){
    auto i = rng();
    return std::move((char*)(&i));
}

int main(int argc, char* argv[])
{
    initscr();
    curs_set(0);
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    auto linePrev{0}, colPrev{0};
    std::vector<std::string> headers;
    headers.resize(COLS);
    for(int column=0; column<COLS; column++){
        headers[column].resize(LINES);
        for(int line=0; line<LINES; line++)
            headers[column][line]=(*int2Str().c_str());
    }

    for(int count=0; count < 20; count++){
        for(int column=0; column<COLS; column++){
            colPrev = column;
            for(int line=0; line<LINES; line++){
                mvaddch(line,column,headers[column][line]);
                const char c{static_cast<char>(mvinch(line,column))};
                mvprintw(linePrev,colPrev,&c);
                refresh();
                linePrev = line;
                headers[column].erase(0,1);
                headers[column].push_back(*int2Str().c_str());
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }    
    getch();
    return endwin();
}
/*

*/