//
// Created by Busiu on 26.09.2018.
//

#include "Position.hpp"

template <class T>
Position<T>::Position(Complex<T>* vector)
{
    this->vector = vector;
}
template <class T>
Position<T>::Position(T x, T y)
{
    this->vector = new Complex<T>(x, y);
}
template <class T>
Position<T>::Position(Position<T>* resolution, int noObjects, int index)
{
    this->vector = new Complex<T>((resolution->getX() / 2), (resolution->getY() * index / noObjects));
}

template <class T>
Position<T>::~Position()
{
    delete(vector);
}

template <class T>
void Position<T>::update(Speed<T>* speed)
{
    *vector += *speed->getVector();
}
template <class T>
void Position<T>::shift(Position<T>* position)
{
    *vector += *position->vector;
}

template <class T>
T Position<T>::getX()
{
    return vector->x;
}
template <class T>
T Position<T>::getY()
{
    return vector->y;
}

template class Position<int>;
template class Position<double>;