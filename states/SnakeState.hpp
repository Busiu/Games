//
// Created by Busiu on 15.09.2018.
//

#ifndef GAMES_SNAKESTATE_HPP
#define GAMES_SNAKESTATE_HPP

#include "../Libraries.hpp"

#include "../collisions/SNAKEcollisionDetector.hpp"

#include "../textures/Texture.hpp"
#include "../textures/TextTexture.hpp"

#include "State.hpp"
#include "States.hpp"

#include "../objects/SNAKEmap.hpp"
#include "../containers/SNAKEtextureContainer.hpp"

namespace snake
{
    enum class GameState
    {
        GAME_OVER,
        GAME_CONTINUES
    };

    class SnakeState : public State
    {
    private:
        Map* map;

        CollisionDetector collisionDetector;
        TextureContainer textureContainer;

    public:
        SnakeState(OptionContainer* optionContainer, Renderer* renderer);

    private:
        void load() override;
        States run() override;
        void close() override;

        //Load
        void initMap();

        //Run
        States handleEvents() override;
        void pressUp();
        void pressDown();
        void pressRight();
        void pressLeft();
        void updateObjects();
        GameState checkCollisions();
        void clearScreen() override;
        void renderObjects() override;
        void updateScreen() override;
    };
}





#endif //GAMES_SNAKESTATE_HPP
