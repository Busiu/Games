//
// Created by Busiu on 26.09.2018.
//

#ifndef GAMES_SPEED_HPP
#define GAMES_SPEED_HPP

#include "../Libraries.hpp"

#include "Complex.hpp"

template <class T> class Speed
{
private:
    Complex<T>* vector;

public:
    Speed(Complex<T>* vector);
    ~Speed();

    Complex<T>* getVector();

};

#endif //GAMES_SPEED_HPP
