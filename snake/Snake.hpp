//
// Created by Busiu on 27.09.2018.
//

#ifndef GAMES_SNAKE_HPP
#define GAMES_SNAKE_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"

#include "../textures/FileTexture.hpp"

#include "../util/Position.hpp"
#include "../util/Speed.hpp"

namespace snake
{
    class Snake : public Renderable
    {
    private:
        Position<double>* position;
        Speed<double>* speed;

    public:
        Snake();
        ~Snake();

        void update();

        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

    private:
        //Renderable
        std::vector<Renderable*> render(SDL_Renderer* renderer) override;
    };
}



#endif //GAMES_SNAKE_HPP
