//
// Created by Busiu on 26.09.2018.
//

#include "Speed.hpp"

template <class T>
Speed<T>::Speed() :
        vector(0, 0)
        {}
template <class T>
Speed<T>::Speed(Complex<T> vector) :
        vector(vector)
        {}
template <class T>
Speed<T>::Speed(T x, T y) :
        vector(x, y)
        {}

template <class T>
void Speed<T>::turnRight()
{
    Complex<T> angle(0, 1);
    vector /= angle;
}
template <class T>
void Speed<T>::turnLeft()
{
    Complex<T> angle(0, 1);
    vector *= angle;
}

template <class T>
T Speed<T>::getX()
{
    return vector.x;
}
template <class T>
T Speed<T>::getY()
{
    return vector.y;
}
template <class T>
Complex<T> Speed<T>::getVector()
{
    return vector;
}
template <class T>
Direction Speed<T>::getDirection()
{
    if(getX() > abs(getY()))
    {
        return Direction::EAST;
    }
    else if(getY() >= abs(getX()))
    {
        return Direction::NORTH;
    }
    else if(abs(getY()) >= abs(getX()))
    {
        return Direction::SOUTH;
    }
    else
    {
        return Direction::WEST;
    }
}
template <class T>
T Speed<T>::getActualSpeed()
{
    return vector.getModule();
}

template class Speed<int>;
template class Speed<double>;