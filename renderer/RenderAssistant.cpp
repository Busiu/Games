//
// Created by Busiu on 30.09.2018.
//

#include "RenderAssistant.hpp"

SDL_Rect RenderAssistant::getRenderRect(Position<double> positionA, Position<double> positionB, int thickness)
{
    int Ax = static_cast<int> (positionA.getX());
    int Bx = static_cast<int> (positionB.getX());
    if(Ax == Bx)
    {
        return getVerticalRect(positionA, positionB, thickness);
    }
    else
    {
        return getHorizontalRect(positionA, positionB, thickness);
    }
}

SDL_Rect RenderAssistant::getVerticalRect(Position<double> positionA, Position<double> positionB, int thickness)
{
    if(positionA.getY() < positionB.getY())
    {
        Position<double> tmp = positionA;
        positionA = positionB;
        positionB = tmp;
    }

    SDL_Rect rect = {
            static_cast<int> (positionA.getX()) - thickness,
            -(static_cast<int> (positionA.getY()) -  thickness),
            2 * thickness + 1,
            2 * thickness + 1 + abs(static_cast<int> (positionB.getY() - positionA.getY()))
    };

    return rect;
}
SDL_Rect RenderAssistant::getHorizontalRect(Position<double> positionA, Position<double> positionB, int thickness)
{
    if(positionA.getX() > positionB.getX())
    {
        Position<double> tmp = positionA;
        positionA = positionB;
        positionB = tmp;
    }

    SDL_Rect rect = {
            static_cast<int> (positionA.getX()) - thickness,
            -(static_cast<int> (positionA.getY()) -  thickness),
            2 * thickness + 1 + abs(static_cast<int> (positionB.getX() - positionA.getX())),
            2 * thickness + 1,
    };

    return rect;
}
