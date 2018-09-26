//
// Created by Busiu on 26.09.2018.
//

#ifndef GAMES_SPEED_HPP
#define GAMES_SPEED_HPP

#include "../Libraries.hpp"

#include "Complex.hpp"

template <class Type> class Speed {
private:
    Complex<Type>* vector;

public:
    Speed(Complex<Type>* vector);
    ~Speed();

    Complex<Type>* getVector();

};

#endif //GAMES_SPEED_HPP
