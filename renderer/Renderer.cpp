//
// Created by Busiu on 14.09.2018.
//
#include "Renderer.hpp"

Renderer::Renderer(Resolution windowSize)
{
    bool success = true;
    success &= initWindow(windowSize);
    success &= initRenderer();

    if(!success)
    {
        throw Exception("Window Container Initialization");
    }
}

bool Renderer::initWindow(Resolution windowSize)
{
    window = SDL_CreateWindow("GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              windowSize.first, windowSize.second, SDL_WINDOW_SHOWN);
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

void Renderer::setResolution(Resolution resolution)
{
    SDL_SetWindowSize(window, resolution.first, resolution.second);
    SDL_RenderSetLogicalSize(renderer, resolution.first, resolution.second);
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