//
// Created by Busiu on 26.09.2018.
//

#ifndef GAMES_SPEED_HPP
#define GAMES_SPEED_HPP

#include "../Libraries.hpp"

#include "Complex.hpp"

enum class Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

template <class T> class Speed
{
private:
    Complex<T>* vector;

public:
    Speed(Complex<T>* vector);
    Speed(T x, T y);
    ~Speed();

    void turnRight();
    void turnLeft();

    T getX();
    T getY();
    Complex<T>* getVector();
    Direction getDirection();

};

#endif //GAMES_SPEED_HPP
