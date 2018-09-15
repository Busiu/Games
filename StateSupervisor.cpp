//
// Created by Busiu on 09.09.2018.
//

#include <iostream>
#include "StateSupervisor.h"

bool StateSupervisor::init()
{
    bool success = true;
    success &= initOptionContainer();
    success &= initWindowContainer();

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

bool StateSupervisor::initWindowContainer()
{
    windowContainer = new WindowContainer(optionContainer->getWindowWidth(), optionContainer->getWindowHeight());
    if(windowContainer == nullptr)
    {
        return false;
    }

    return true;
}

void StateSupervisor::run()
{
    currentState = new MenuState(optionContainer, windowContainer);
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
                currentState = new MenuState(optionContainer, windowContainer);
                break;
            }
            case OPTIONS_STATE:
            {
                currentState = new OptionState(optionContainer, windowContainer);
                break;
            }
            case SNAKE_STATE:
            {
                currentState = new snake::SnakeState(optionContainer, windowContainer);
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
    destroyWindowContainer();
    destroyOptionContainer();
}

void StateSupervisor::destroyWindowContainer()
{
    delete windowContainer;
}

void StateSupervisor::destroyOptionContainer()
{
    delete optionContainer;
}
