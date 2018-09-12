//
// Created by Busiu on 09.09.2018.
//

#include <iostream>
#include "Window.h"

bool Window::init()
{
    bool success = true;
    success &= initOptionContainer();
    success &= initWindow();
    success &= initRenderer();

    return success;
}

bool Window::initOptionContainer()
{
    optionContainer = new OptionContainer();
    if(optionContainer == nullptr)
    {
        return false;
    }

    return true;
}

bool Window::initWindow()
{
    window = SDL_CreateWindow("GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              optionContainer->getWindowHeight(), optionContainer->getWindowWidth(), SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
        return false;
    }

    return true;
}

bool Window::initRenderer()
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        return false;
    }

    optionContainer->setRenderer(renderer);

    return true;
}



void Window::run()
{
    currentState = new MenuState(optionContainer->getRenderer());
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
                currentState = new MenuState(optionContainer);
                break;
            }
            case OPTIONS_STATE:
            {
                currentState = new OptionState(optionContainer);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}



void Window::free()
{
    destroyWindow();
    destroyOptionContainer();
}

void Window::destroyWindow()
{
    SDL_DestroyWindow(window);
}

void Window::destroyOptionContainer()
{
    SDL_DestroyRenderer(optionContainer->getRenderer());
    delete optionContainer;
}