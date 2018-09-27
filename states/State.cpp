//
// Created by Busiu on 09.09.2018.
//

#include "State.hpp"

State::State(OptionContainer* optionContainer, Renderer* renderer)
{
    this->optionContainer = optionContainer;
    this->renderer = renderer;
    this->fpsCapper = new Timer(optionContainer->getFpsCap());
}
State::~State()
{
    delete(fpsCapper);
}

int State::start()
{
    int nextState;
    load();
    nextState = run();
    close();

    return nextState;
}
