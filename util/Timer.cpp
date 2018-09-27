//
// Created by Busiu on 27.09.2018.
//

#include "Timer.hpp"

Timer::Timer(int fpsCap)
{
    this->ticksPerFrame = static_cast<Uint32> (1000.0 / fpsCap);
}

void Timer::start()
{
    startTicks = SDL_GetTicks();
}
void Timer::end()
{
    endTicks = SDL_GetTicks();
}
void Timer::wait()
{
    Uint32 frameTicks = endTicks - startTicks;
    if (frameTicks < ticksPerFrame)
    {
        SDL_Delay(ticksPerFrame - frameTicks);
    }
}
