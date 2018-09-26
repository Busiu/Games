//
// Created by Busiu on 26.09.2018.
//

#ifndef GAMES_POSITION_HPP
#define GAMES_POSITION_HPP

#include "../Libraries.hpp"

#include "Complex.hpp"
#include "Speed.hpp"

template <class T> class Position
{
private:
    Complex<T>* vector;

public:
    Position(Complex<T>* vector);
    Position(T x, T y);
    //Special constructor for Text Objects
    Position(Position<T>* resolution, int noObjects, int index);
    ~Position();

    void update(Speed<T>* speed);
    void shift(Position<T>* position);

    T getX();
    T getY();

};


#endif //GAMES_POSITION_HPP
