//
// Created by Busiu on 05.10.2018.
//

#include "SNAKEsnakeChunk.hpp"

namespace snake
{
    SnakeChunk::SnakeChunk(Position<double> positionA,
                           Position<double> positionB,
                           Speed<double> speed,
                           SDL_Color& color,
                           int& thickness,
                           Direction direction) :
    positionA(positionA),
    positionB(positionB),
    speed(speed),
    color(color),
    thickness(thickness)
    {
        this->direction = direction;
    }

    void SnakeChunk::move()
    {
        positionB.update(speed);
    }
    void SnakeChunk::shorten()
    {
        positionA.update(speed);
    }

    Position<double> SnakeChunk::getPosA()
    {
        return positionA;
    }
    Position<double> SnakeChunk::getPosB()
    {
        return positionB;
    }
    double SnakeChunk::getLength()
    {
        return Position<double>::getDistance(positionA, positionB);
    }

    std::vector<Renderable*> SnakeChunk::render(SDL_Renderer* renderer)
    {
        std::vector <Renderable*> kids;
        Position tmpA(positionA);
        Position tmpB(positionB);
        Position<double>::sortPositions(tmpA, tmpB);

        SDL_Rect fillRect = RenderAssistant::getRenderRect(tmpA, tmpB, thickness);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &fillRect);

        return kids;
    }
}
