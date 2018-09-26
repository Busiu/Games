//
// Created by Busiu on 26.09.2018.
//

#ifndef GAMES_POSITION_HPP
#define GAMES_POSITION_HPP

#include "../Libraries.hpp"

#include "Complex.hpp"
#include "Speed.hpp"

template <class Type> class Position {
private:
    Complex<Type>* vector;

public:
    Position(Complex<Type>* vector);
    ~Position();

private:
    void update(Speed<Type>* speed);

};


#endif //GAMES_POSITION_HPP
