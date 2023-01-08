#include "Raindrop.h"
#include <ncurses.h>

Raindrop::Raindrop(int xPosition, int refreshRate, int length){
    str.resize(length,' ');
}

void Raindrop::update(int i, int rng){
    for(int c = 0; c < str.size(); c++){
        mvaddch(c,i,str[str.size()-1-c]);
        refresh();
    }
    str.erase(0,1);
    str.push_back(*int2Str(rng).c_str());
}

std::string Raindrop::int2Str(int i){
    return std::move((char*)(&i));
}