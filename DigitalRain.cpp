// Local
#include "DigitalRain.h"
#include "Raindrop.h"
#include "ncurses.h"
#include <random>
#include <thread>
#include <chrono>

DigitalRain::DigitalRain(){

    std::vector<Raindrop*> raindrops;
    for(int column=0; column<COLS; column++)
        raindrops.push_back(new Raindrop(column,LINES));

    for(int refreshes=0; refreshes < 100; refreshes++){
        for(int i=0; i<raindrops.size(); i+=2)
            raindrops[i]->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        refresh();
    }
}