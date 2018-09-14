//
// Created by Busiu on 09.09.2018.
//

#include "State.h"

State::State(OptionContainer* optionContainer, WindowContainer* windowContainer)
{
    this->optionContainer = optionContainer;
    this->windowContainer = windowContainer;
}

State::~State()
{
    delete optionContainer;
    delete windowContainer;
}

int State::start()
{
    int nextState;
    load();
    nextState = run();
    close();

    return nextState;
}
