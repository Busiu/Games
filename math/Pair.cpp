//
// Created by Busiu on 13.09.2018.
//

#include "Pair.hpp"

Pair::Pair(int x, int y)
{
    this->x = x;
    this->y = y;
}

Pair::Pair(Pair* resolution, int noObjects, int index)
{
    this->x = resolution->getX() / 2;
    this->y = resolution->getY() * index / noObjects;
}

int Pair::getX()
{
    return x;
}

int Pair::getY()
{
    return y;
}

void Pair::shift(Pair& shift)
{
    this->x += shift.getX();
    this->y += shift.getY();
}