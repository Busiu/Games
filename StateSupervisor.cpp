//
// Created by Busiu on 09.09.2018.
//

#include <iostream>
#include "StateSupervisor.hpp"

bool StateSupervisor::init()
{
    bool success = true;
    success &= initOptionContainer();
    success &= initRenderer();

    return success;
}

bool StateSupervisor::initOptionContainer()
{
    optionContainer = std::make_shared<OptionContainer>();
    if(optionContainer == nullptr)
    {
        return false;
    }

    return true;
}

bool StateSupervisor::initRenderer()
{
    renderer = std::make_shared<Renderer>(optionContainer->getWindowResolution());
    if(renderer == nullptr)
    {
        return false;
    }

    return true;
}

void StateSupervisor::run()
{
    bool quit = false;
    currentState = std::make_unique<MenuState>(optionContainer, renderer);
    States whichState;

    while(!quit)
    {
        whichState = currentState->start();

        switch(whichState)
        {
            case States::EXIT_STATE:
            {
                quit = true;
                break;
            }
            case States::MENU_STATE:
            {
                currentState.reset(new MenuState(optionContainer, renderer));
                break;
            }
            case States::OPTIONS_STATE:
            {
                currentState.reset(new OptionState(optionContainer, renderer));
                break;
            }
            case States::SNAKE_STATE:
            {
                currentState.reset(new snake::SnakeState(optionContainer, renderer));
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
