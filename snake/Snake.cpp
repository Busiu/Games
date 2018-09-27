//
// Created by Busiu on 27.09.2018.
//

#include "Snake.hpp"

namespace snake
{
    Snake::Snake()
    {
        this->position = new Position<double>(100, -100);
        this->speed = new Speed<double>(1, 0);
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

    void Snake::moveUp()
    {
        Direction direction = speed->getDirection();
        if(direction == Direction::WEST)
        {
            speed->turnRight();
        }
        else if(direction == Direction::EAST)
        {
            speed->turnLeft();
        }
    }
    void Snake::moveDown()
    {
        Direction direction = speed->getDirection();
        if(direction == Direction::EAST)
        {
            speed->turnRight();
        }
        else if(direction == Direction::WEST)
        {
            speed->turnLeft();
        }
    }
    void Snake::moveRight()
    {
        Direction direction = speed->getDirection();
        if(direction == Direction::NORTH)
        {
            speed->turnRight();
        }
        else if(direction == Direction::SOUTH)
        {
            speed->turnLeft();
        }
    }
    void Snake::moveLeft()
    {
        Direction direction = speed->getDirection();
        if(direction == Direction::SOUTH)
        {
            speed->turnRight();
        }
        else if(direction == Direction::NORTH)
        {
            speed->turnLeft();
        }
    }

    std::vector<Renderable*> Snake::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;

        SDL_Rect fillRect = {static_cast<int> (position->getX()), static_cast<int> (-position->getY()), 10, 10};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);

        return kids;
    }
}
