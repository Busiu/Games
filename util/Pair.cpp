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

int Pair::getX() const
{
    return x;
}

int Pair::getY() const
{
    return y;
}

Pair& Pair::operator += (const Pair& pair)
{
    this->x += pair.getX();
    this->y += pair.getY();
}

