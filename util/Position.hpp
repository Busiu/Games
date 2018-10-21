//
// Created by Busiu on 26.09.2018.
//

#ifndef GAMES_POSITION_HPP
#define GAMES_POSITION_HPP

#include "../Libraries.hpp"

#include "Complex.hpp"
#include "Speed.hpp"
#include "Types.hpp"

template <class T> class Position
{
private:
    Complex<T> vector;

public:
    Position();
    explicit Position(Complex<T>& vector);
    Position(T x, T y);
    //Special constructor for Text Objects
    Position(Resolution resolution, int noObjects, int index);

    void update(Speed<T>& speed);
    void shift(Position<T>& position);

    T getX() const;
    T getY() const;

    static double getDistance(Position& a, Position& b);
    static void sortPositions(Position& a, Position& b);

    Position operator-(const Position<T>& position);
};


#endif //GAMES_POSITION_HPP
