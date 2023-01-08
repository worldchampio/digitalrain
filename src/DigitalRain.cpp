#include "DigitalRain.h"
#include "Raindrop.h"
#include "ncurses.h"
#include <random>
#include <thread>
#include <chrono>

DigitalRain::DigitalRain(int iterations, int delay){
    for(int column=0; column<COLS; column++)
        rain.push_back(new Raindrop(column));

    for(int i=0; i < iterations; i++){
        for(const auto& raindrop : rain)
            raindrop->update();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        refresh();
    }
}

DigitalRain::~DigitalRain(){
    for(const auto& raindrop : rain)
        delete raindrop;
}