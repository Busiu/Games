//
// Created by Busiu on 26.09.2018.
//

#include "Speed.hpp"

template <class T>
Speed<T>::Speed(Complex<T>* vector)
{
    this->vector = vector;
}
template <class T>
Speed<T>::Speed(T x, T y)
{
    this->vector = new Complex<T>(x, y);
}
template <class T>
Speed<T>::~Speed()
{
    delete(vector);
}

template <class T>
Complex<T>* Speed<T>::getVector()
{
    return vector;
}

template class Speed<int>;
template class Speed<double>;