//
// Created by Busiu on 14.09.2018.
//

#include "Renderer.hpp"

Renderer::Renderer(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    bool success = true;
    success &= initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    success &= initRenderer();

    if(!success)
    {
        throw Exception("Window Container Initialization");
    }
}

bool Renderer::initWindow(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    window = SDL_CreateWindow("GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
        return false;
    }

    return true;
}

bool Renderer::initRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        return false;
    }

    return true;
}

Renderer::~Renderer()
{
    destroyWindow();
    destroyRenderer();
}

void Renderer::destroyWindow()
{
    SDL_DestroyWindow(window);
}

void Renderer::destroyRenderer()
{
    SDL_DestroyRenderer(renderer);
}


SDL_Window* Renderer::getWindow()
{
    return window;
}

SDL_Renderer* Renderer::getRenderer()
{
    return renderer;
}

void Renderer::setWindow(SDL_Window* window)
{
    this->window = window;
}
void Renderer::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}
void Renderer::setResolution(Pair* resolution)
{
    SDL_SetWindowSize(window, resolution->getX(), resolution->getY());
    SDL_RenderSetLogicalSize(renderer, resolution->getX(), resolution->getY());
}

void Renderer::render(Renderable* renderable)
{
    renderable->render(renderer);
};