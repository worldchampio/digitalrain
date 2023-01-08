/*
Contains a string of random characters,
corresponding to a single column being displayed onscreen.
*/
#include "Raindrop.h"
#include <ncurses.h>
#include <random>

Raindrop::Raindrop(int xPos, bool startAsBlank) :
    rate{rng(1,100)},
    xPos{xPos}
{
    if(startAsBlank)
        blankSpace(rng(1,LINES-LINES/7));
    str.resize(LINES,' ');
}

void Raindrop::update(int randomnum){
    for(int c = 0; c < str.size(); c++)
    {   
        if(c<str.size()-1 && static_cast<char>(mvinch(c+1,xPos))==' ')
            attron(A_BOLD);
        mvaddch(c,xPos,str[str.size()-1-c]);
        attroff(A_BOLD);
    }
    if(rate<randomnum)
    {       
        str.erase(0,1);
        char ch;
        if(blank.empty())
            ch=*int2Str(rng()).c_str();
        else{
            ch=blank[0];
            blank.pop_back();
        }
        str.push_back(ch);
    }
}

std::string Raindrop::int2Str(int i){
    return std::move((char*)(&i));
}

void Raindrop::blankSpace(int length){
    if(blank.empty())
        blank.resize(length,' ');
}

int Raindrop::rng(int min, int max) 
{
    std::random_device  dev;
    std::mt19937        rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
    return dist6(rng);
}