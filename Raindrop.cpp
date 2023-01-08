/*
Contains a string of random characters,
corresponding to a single column being displayed onscreen.
*/
#include "Raindrop.h"
#include <ncurses.h>
#include <random>

Raindrop::Raindrop(int xPos) :
    rate{rng(1,100)},
    xPos{xPos}
{
    str.resize(LINES,' ');
}

void Raindrop::update(){
    for(int c = 0; c < str.size(); c++)
        mvaddch(c,xPos,str[str.size()-1-c]);
    if(rate<50)
    {       
        str.erase(0,1);
        str.push_back(*int2Str(rng()).c_str());
    }
    rate = rng(1,100);
}

std::string Raindrop::int2Str(int i){
    return std::move((char*)(&i));
}

int Raindrop::rng(int min, int max) 
{
    std::random_device  dev;
    std::mt19937        rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
    return dist6(rng);
}