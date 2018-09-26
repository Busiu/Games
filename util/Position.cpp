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
Position<T>::~Position()
{
    delete(vector);
}

template <class T>
void Position<T>::update(Speed<T>* speed)
{
    *vector += *speed->getVector();
}