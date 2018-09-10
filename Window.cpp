//
// Created by Busiu on 09.09.2018.
//

#include "Window.h"

bool Window::init()
{
    bool success = true;
    success &= initWindow();
    success &= initRenderer();

    return success;
}

bool Window::initWindow()
{
    window = SDL_CreateWindow("GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              width, height, SDL_WINDOW_SHOWN);

    if(window == nullptr)
    {
        return false;
    }

    return true;
}

bool Window::initRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == nullptr)
    {
        return false;
    }

    return true;
}



void Window::run()
{
    currentState = new MenuState(renderer);
    int whichState = MENU_STATE;

    while(whichState)
    {
        whichState = currentState->start();
        delete(currentState);

        switch(whichState)
        {
            case EXIT_STATE:
            {
                break;
            }
            case MENU_STATE:
            {
                currentState = new MenuState(renderer);
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
    destroyRenderer();
}

void Window::destroyWindow()
{
    SDL_DestroyWindow(window);
}

void Window::destroyRenderer()
{
    SDL_DestroyRenderer(renderer);
}