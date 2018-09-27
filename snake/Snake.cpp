//
// Created by Busiu on 27.09.2018.
//

#include "Snake.hpp"

namespace snake
{
    Snake::Snake()
    {
        this->position = new Position<double>(100, 100);
        this->speed = new Speed<double>(0.1, 0);
    }
    Snake::~Snake()
    {
        delete(position);
        delete(speed);
    }

    void Snake::update()
    {
        position->update(speed);
    }

    std::vector<Renderable*> Snake::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;

        SDL_Rect fillRect = {static_cast<int> (position->getX()), static_cast<int> (position->getY()), 10, 10};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);

        return kids;
    }
}
