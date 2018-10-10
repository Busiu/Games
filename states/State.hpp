//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_STATE_HPP
#define GAMES_STATE_HPP

#include "../Libraries.hpp"

#include "../containers/OptionContainer.hpp"
#include "../renderer/Renderer.hpp"

#include "../util/Timer.hpp"

#include "States.hpp"

class State {
protected:
    SDL_Event event;

    OptionContainer* optionContainer;
    Renderer* renderer;
    Timer* fpsCapper;

public:
    State(OptionContainer* optionContainer, Renderer* renderer);
    ~State();

    States start();

protected:
    virtual void load() = 0;
    virtual States run() = 0;
    virtual void close() = 0;

    virtual States handleEvents() = 0;
    virtual void clearScreen() = 0;
    virtual void renderObjects() = 0;
    virtual void updateScreen() = 0;
};


#endif //GAMES_STATE_HPP
