//
// Created by Busiu on 14.09.2018.
//
#include "Renderer.hpp"

Renderer::Renderer(Position<int>* windowSize)
{
    bool success = true;
    success &= initWindow(windowSize);
    success &= initRenderer();

    if(!success)
    {
        throw Exception("Window Container Initialization");
    }
}

bool Renderer::initWindow(Position<int>* windowSize)
{
    window = SDL_CreateWindow("GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              windowSize->getX(), windowSize->getY(), SDL_WINDOW_SHOWN);
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

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void Renderer::update()
{
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getRenderer()
{
    return renderer;
}

void Renderer::setResolution(Position<int>* resolution)
{
    SDL_SetWindowSize(window, resolution->getX(), resolution->getY());
    SDL_RenderSetLogicalSize(renderer, resolution->getX(), resolution->getY());
}

void Renderer::render(Renderable* renderable)
{
    std::stack<Renderable*> renderables;
    Renderable* rendered;
    std::vector<Renderable*> renderableKids;

    renderables.push(renderable);
    while(!renderables.empty())
    {
        rendered = renderables.top();
        renderables.pop();
        renderableKids = rendered->render(renderer);
        for(int j = 0; j < renderableKids.size(); j++)
        {
            renderables.push(renderableKids[j]);
        }
    }
}