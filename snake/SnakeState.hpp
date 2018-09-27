//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_SNAKESTATE_HPP
#define GAMES_SNAKESTATE_HPP

#include "../Libraries.hpp"

#include "../textures/Texture.hpp"
#include "../textures/TextTexture.hpp"

#include "../states/State.hpp"
#include "../states/States.hpp"

#include "Map.hpp"

namespace snake
{
    class SnakeState : public State
    {
    private:
        Map* map;

    public:
        SnakeState(OptionContainer* optionContainer, Renderer* renderer) :
        State(optionContainer, renderer){}

    private:
        void load() override;
        int run() override;
        void close() override;

        //Load
        void initMap();

        //Run
        int handleEvents() override;
        void pressUp();
        void pressDown();
        void pressRight();
        void pressLeft();
        void updateObjects();
        void clearScreen() override;
        void renderObjects() override;
        void updateScreen() override;
    };
}



#endif //GAMES_SNAKESTATE_HPP
