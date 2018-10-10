//
// Created by Busiu on 26.09.2018.
//

#ifndef GAMES_SPEED_HPP
#define GAMES_SPEED_HPP

#include "../Libraries.hpp"

#include "Complex.hpp"
#include "Direction.hpp"

template <class T> class Speed
{
private:
    Complex<T> vector;

public:
    Speed();
    Speed(Complex<T> vector);
    Speed(T x, T y);

    void turnRight();
    void turnLeft();

    T getX();
    T getY();
    Complex<T> getVector();
    Direction getDirection();
    T getActualSpeed();

};

#endif //GAMES_SPEED_HPP
