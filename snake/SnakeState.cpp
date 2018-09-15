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
        this->map = new Map(new Pair(30,20), windowContainer->getRenderer());
    }



    int SnakeState::run()
    {
        while(true)
        {
            int NEXT_STATE = handleEvents();
            if(NEXT_STATE != CURRENT_STATE)
            {
                return NEXT_STATE;
            }

            clear();
            render();
            update();
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
            if(currentKeyStates[SDL_SCANCODE_ESCAPE])
            {
                return MENU_STATE;
            }
        }

        //No state-change request
        return CURRENT_STATE;
    }

    void SnakeState::clear()
    {
        SDL_SetRenderDrawColor(windowContainer->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(windowContainer->getRenderer());
    }

    void SnakeState::render()
    {
        map->render(windowContainer->getRenderer());
    }

    void SnakeState::update()
    {
        SDL_RenderPresent(windowContainer->getRenderer());
    }



    void SnakeState::close()
    {
        delete(map);
    }
}