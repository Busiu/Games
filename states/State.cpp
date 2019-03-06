//
// Created by Busiu on 09.09.2018.
//

#include "State.hpp"

State::State(const std::shared_ptr<OptionContainer> optionContainer,
             const std::shared_ptr<Renderer> renderer)
{
    this->optionContainer = optionContainer;
    this->renderer = renderer;
    this->fpsCapper = std::make_unique<Timer>(optionContainer->getFpsCap());
}

States State::start()
{
    States nextState;
    load();
    nextState = run();
    close();

    return nextState;
}
