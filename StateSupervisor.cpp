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
    optionContainer = new OptionContainer();
    if(optionContainer == nullptr)
    {
        return false;
    }

    return true;
}

bool StateSupervisor::initRenderer()
{
    renderer = new Renderer(optionContainer->getWindowResolution());
    if(renderer == nullptr)
    {
        return false;
    }

    return true;
}

void StateSupervisor::run()
{
    currentState = new MenuState(optionContainer, renderer);
    int whichState = MENU_STATE;

    while(whichState)
    {
        whichState = currentState->start();
        delete currentState;

        switch(whichState)
        {
            case EXIT_STATE:
            {
                break;
            }
            case MENU_STATE:
            {
                currentState = new MenuState(optionContainer, renderer);
                break;
            }
            case OPTIONS_STATE:
            {
                currentState = new OptionState(optionContainer, renderer);
                break;
            }
            case SNAKE_STATE:
            {
                currentState = new snake::SnakeState(optionContainer, renderer);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}



void StateSupervisor::free()
{
    destroyRenderer();
    destroyOptionContainer();
}

void StateSupervisor::destroyRenderer()
{
    delete renderer;
}

void StateSupervisor::destroyOptionContainer()
{
    delete optionContainer;
}
