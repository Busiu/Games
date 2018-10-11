//
// Created by Busiu on 15.09.2018.
//

#include "SnakeState.hpp"

SnakeState::SnakeState(OptionContainer* optionContainer, Renderer* renderer) :
State(optionContainer, renderer),
textureContainer(renderer)
{}

void SnakeState::load()
{
    initMap();
}

void SnakeState::initMap()
{
    this->map = new snake::Map(20, renderer, textureContainer);
}



States SnakeState::run()
{
    while(true)
    {
        fpsCapper->start();

        States NEXT_STATE = handleEvents();
        if(NEXT_STATE != States::CURRENT_STATE)
        {
            return NEXT_STATE;
        }

        updateObjects();
        clearScreen();
        renderObjects();
        updateScreen();

        fpsCapper->end();
        fpsCapper->wait();
    }
}

States SnakeState::handleEvents()
{
    while (SDL_PollEvent(&event) != 0)
    {
        //User requests quit
        if (event.type == SDL_QUIT)
        {
            return States::EXIT_STATE;
        }

        //User's keyboard requests
        const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
        if(currentKeyStates[SDL_SCANCODE_UP])
        {
            pressUp();
        }
        else if(currentKeyStates[SDL_SCANCODE_DOWN])
        {
            pressDown();
        }
        else if(currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            pressRight();
        }
        else if(currentKeyStates[SDL_SCANCODE_LEFT])
        {
            pressLeft();
        }
        else if(currentKeyStates[SDL_SCANCODE_ESCAPE])
        {
            return States::MENU_STATE;
        }
    }

    //No state-change request
    return States::CURRENT_STATE;
}

void SnakeState::pressUp()
{
    map->moveSnakeUp();
}

void SnakeState::pressDown()
{
    map->moveSnakeDown();
}

void SnakeState::pressRight()
{
    map->moveSnakeRight();
}

void SnakeState::pressLeft()
{
    map->moveSnakeLeft();
}

void SnakeState::updateObjects()
{
    map->update();
}

void SnakeState::clearScreen()
{
    SDL_SetRenderDrawColor(renderer->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer->getRenderer());
}

void SnakeState::renderObjects()
{
    renderer->render(map);
}

void SnakeState::updateScreen()
{
    SDL_RenderPresent(renderer->getRenderer());
}



void SnakeState::close()
{
    delete(map);
}
