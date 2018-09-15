//
// Created by Busiu on 09.09.2018.
//

#include "State.hpp"

State::State(OptionContainer* optionContainer, WindowContainer* windowContainer)
{
    this->optionContainer = optionContainer;
    this->windowContainer = windowContainer;
}

int State::start()
{
    int nextState;
    load();
    nextState = run();
    close();

    return nextState;
}
