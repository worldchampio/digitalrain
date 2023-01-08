// Local
#include "DigitalRain.h"
#include "Raindrop.h"
// Lib
#include <ncurses.h>
// STL
#include <iostream>
#include <random>

DigitalRain::DigitalRain(){

    std::vector<Raindrop*> raindrops;
    for(int column=0; column<COLS; column++)
        raindrops.push_back(new Raindrop(column,rng(1,10),LINES));

    for(int count=0; count < 100; count++){
        for(int i=0; i<raindrops.size(); i+=2)
            raindrops[i]->update(i,rng());
    }
}

int DigitalRain::rng(int min, int max) 
{
    std::random_device  dev;
    std::mt19937        rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
    return dist6(rng);
}