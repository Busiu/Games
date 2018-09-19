//
// Created by Busiu on 09.09.2018.
//

#ifndef GAMES_STATE_HPP
#define GAMES_STATE_HPP

#include "../Libraries.hpp"

#include "../containers/OptionContainer.hpp"
#include "../renderer/Renderer.hpp"

class State {
protected:
    SDL_Event event;

    OptionContainer* optionContainer;
    Renderer* renderer;

public:
    State(OptionContainer* optionContainer, Renderer* windowContainer);

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


#endif //GAMES_STATE_HPP
