//
// Created by Busiu on 27.09.2018.
//

#include "SNAKEsnake.hpp"

namespace snake
{
    Snake::Snake() :
    speed(1, 0)
    {
        this->color = {0xFF, 0x00, 0x00, 0xFF};
        this->thickness = 6;
        Position<double> begOfSnake(100, -100);
        Position<double> endOfSnake(50, -100);

        SnakeChunk snakeChunk(endOfSnake, begOfSnake, speed, color, thickness, Direction::EAST);
        body.push_back(snakeChunk);
    }

    void Snake::update()
    {
        moveHead();
        shortenTail();
    }
    void Snake::moveHead()
    {
        auto head = body.begin();
        (*head).move();
    }
    void Snake::shortenTail()
    {
        double distanceLeft = speed.getActualSpeed();
        for(auto tail = body.rbegin(); distanceLeft > 0; tail++)
        {
            double distance = (*tail).getLength();
            if(distance > distanceLeft)
            {
                (*tail).shorten();
            }
            else
            {
                body.pop_back();
            }

            distanceLeft -= distance;
        }
    }

    void Snake::bendTail(Direction direction)
    {
        SnakeChunk head = *body.begin();
        SnakeChunk newHead(head.getBeg(), head.getBeg(), speed, color, thickness, direction);
        body.push_front(newHead);

    }

    void Snake::moveUp()
    {
        Direction direction = speed.getDirection();
        if(direction == Direction::WEST)
        {
            speed.turnRight();
            bendTail(Direction::NORTH);
        }
        else if(direction == Direction::EAST)
        {
            speed.turnLeft();
            bendTail(Direction::NORTH);
        }
    }
    void Snake::moveDown()
    {
        Direction direction = speed.getDirection();
        if(direction == Direction::EAST)
        {
            speed.turnRight();
            bendTail(Direction::SOUTH);
        }
        else if(direction == Direction::WEST)
        {
            speed.turnLeft();
            bendTail(Direction::SOUTH);
        }
    }
    void Snake::moveRight()
    {
        Direction direction = speed.getDirection();
        if(direction == Direction::NORTH)
        {
            speed.turnRight();
            bendTail(Direction::EAST);
        }
        else if(direction == Direction::SOUTH)
        {
            speed.turnLeft();
            bendTail(Direction::EAST);
        }
    }
    void Snake::moveLeft()
    {
        Direction direction = speed.getDirection();
        if(direction == Direction::SOUTH)
        {
            speed.turnRight();
            bendTail(Direction::WEST);
        }
        else if(direction == Direction::NORTH)
        {
            speed.turnLeft();
            bendTail(Direction::WEST);
        }
    }

    Position<double> Snake::getHeadPosition()
    {
        auto head = body.begin();

        return head->getBeg();
    }

    std::vector<Renderable*> Snake::render(SDL_Renderer* renderer)
    {
        std::vector<Renderable*> kids;
        for(auto it = body.begin(); it != body.end(); it++)
        {
            kids.push_back(&(*it));
        }

        return kids;
    }
}
