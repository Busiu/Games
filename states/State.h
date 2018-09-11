//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_STATE_H
#define GAMES_STATE_H

#include "../Libraries.h"
#include "States.h"


class State {
protected:
    SDL_Renderer* renderer;
    SDL_Event event;

public:
    int start();

protected:
    virtual void load() = 0;
    virtual int run() = 0;
    virtual void close() = 0;

    virtual int handleEvents() = 0;
    virtual void clear() = 0;
    virtual void render() = 0;
    virtual void update() = 0;
};


#endif //GAMES_STATE_H