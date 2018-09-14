//
// Created by Busiu on 14.09.2018.
//

#include "WindowContainer.h"

WindowContainer::WindowContainer(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    bool success = true;
    success &= initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    success &= initRenderer();

    if(!success)
    {
        throw Exception("Window Container Initialization");
    }
}

bool WindowContainer::initWindow(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    window = SDL_CreateWindow("GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
        return false;
    }

    return true;
}

bool WindowContainer::initRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        return false;
    }

    return true;
}

WindowContainer::~WindowContainer()
{
    destroyWindow();
    destroyRenderer();
}

void WindowContainer::destroyWindow()
{
    SDL_DestroyWindow(window);
}

void WindowContainer::destroyRenderer()
{
    SDL_DestroyRenderer(renderer);
}


SDL_Window* WindowContainer::getWindow()
{
    return window;
}

SDL_Renderer* WindowContainer::getRenderer()
{
    return renderer;
}

void WindowContainer::setWindow(SDL_Window* window)
{
    this->window = window;
}
void WindowContainer::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}
void WindowContainer::setResolution(Pair* resolution)
{
    SDL_SetWindowSize(window, resolution->getX(), resolution->getY());
    SDL_RenderSetLogicalSize(renderer, resolution->getX(), resolution->getY());
}