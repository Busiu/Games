//
// Created by Busiu on 23.09.2018.
//

#ifndef GAMES_COMPLEX_HPP
#define GAMES_COMPLEX_HPP

#include <math.h>

#include "../Libraries.hpp"

template <class T> class Complex
{
    template <class U> friend class Position;
    template <class U> friend class Speed;

private:
    T x;
    T y;

public:
    Complex(T x, T y);
    Complex();

    Complex operator+(const Complex& complex);
    Complex operator-(const Complex& complex);
    Complex operator*(const Complex& complex);
    Complex operator/(const Complex& complex);

    Complex operator+=(const Complex& complex);
    Complex operator-=(const Complex& complex);
    Complex operator*=(const Complex& complex);
    Complex operator/=(const Complex& complex);

    bool operator>(const Complex& complex) const;
    bool operator<(const Complex& complex) const;

    T getModule() const;

    template<class Type> friend std::ostream& operator << (std::ostream& os, const Complex<Type>& complex);
    template<class Type> friend std::istream& operator >> (std::istream& is, Complex<Type>& complex);

    Complex& operator++() = delete;
    const Complex operator++(int) = delete;

};


#endif //GAMES_COMPLEX_HPP
