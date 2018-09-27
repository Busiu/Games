//
// Created by Busiu on 15.09.2018.
//

#include "SnakeState.hpp"

namespace snake
{
    void SnakeState::load()
    {
        initMap();
    }

    void SnakeState::initMap()
    {
        this->map = new Map(20, renderer->getRenderer());
    }



    int SnakeState::run()
    {
        while(true)
        {
            fpsCapper->start();

            int NEXT_STATE = handleEvents();
            if(NEXT_STATE != CURRENT_STATE)
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

    int SnakeState::handleEvents()
    {
        while (SDL_PollEvent(&event) != 0)
        {
            //User requests quit
            if (event.type == SDL_QUIT)
            {
                return EXIT_STATE;
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
                return MENU_STATE;
            }
        }

        //No state-change request
        return CURRENT_STATE;
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
}