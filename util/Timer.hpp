//
// Created by Busiu on 27.09.2018.
//

#ifndef GAMES_TIMER_HPP
#define GAMES_TIMER_HPP

#include "../Libraries.hpp"

class Timer {
private:
    Uint32 ticksPerFrame;
    Uint32 startTicks;
    Uint32 endTicks;

public:
    Timer(int fpsCap);

    void start();
    void end();
    void wait();

};


#endif //GAMES_TIMER_HPP
