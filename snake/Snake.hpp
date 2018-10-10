//
// Created by Busiu on 27.09.2018.
//

#ifndef GAMES_SNAKE_HPP
#define GAMES_SNAKE_HPP

#include "../Libraries.hpp"

#include "../renderer/Renderable.hpp"
#include "../renderer/RenderAssistant.hpp"

#include "../util/Position.hpp"
#include "../util/Speed.hpp"

#include "SnakeChunk.hpp"

namespace snake
{
    class Snake : public Renderable
    {
    private:
        std::list<SnakeChunk> body;
        Speed<double> speed;

        SDL_Color color;
        int thickness;

    public:
        Snake();

        void update();
        void bendTail(Direction direction);

        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

    private:
        //Update
        void moveHead();
        void shortenTail();

        //Renderable
        std::vector<Renderable*> render(SDL_Renderer* renderer) override;
    };
}



#endif //GAMES_SNAKE_HPP
