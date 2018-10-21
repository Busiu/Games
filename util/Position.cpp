//
// Created by Busiu on 26.09.2018.
//

#include "Position.hpp"

template <class T>
Position<T>::Position() :
        vector(0,0)
        {}
template <class T>
Position<T>::Position(Complex<T>& vector) :
        vector(vector)
        {}
template <class T>
Position<T>::Position(T x, T y) :
        vector(x, y)
        {}

template <class T>
Position<T>::Position(Resolution resolution, int noObjects, int index) :
        vector((resolution.first / 2), (resolution.second * index / noObjects))
        {}

template <class T>
void Position<T>::update(Speed<T>& speed)
{
    vector += speed.getVector();
}
template <class T>
void Position<T>::shift(Position<T>& position)
{
    vector += position.vector;
}

template <class T>
T Position<T>::getX() const
{
    return vector.x;
}
template <class T>
T Position<T>::getY() const
{
    return vector.y;
}

template <class T>
double Position<T>::getDistance(Position &a, Position &b)
{
    Complex tmp = a.vector - b.vector;

    return tmp.getModule();
}
template <class T>
void Position<T>::sortPositions(Position& a, Position& b)
{
    if(a.vector > b.vector)
    {
        std::swap(a, b);
    }
}

template <class T>
Position<T> Position<T>::operator-(const Position& position)
{
    Complex<T> tmpVec = this->vector - position.vector;
    Position<T> tmpPos(tmpVec);

    return tmpPos;
}

template class Position<int>;
template class Position<double>;