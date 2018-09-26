//
// Created by Busiu on 23.09.2018.
//

#ifndef GAMES_COMPLEX_HPP
#define GAMES_COMPLEX_HPP

#include "../Libraries.hpp"

template <class Type> class Complex {
private:
    Type x;
    Type y;

public:
    Complex(Type x, Type y);
    Complex();

    Complex operator+(const Complex& complex);
    Complex operator-(const Complex& complex);
    Complex operator*(const Complex& complex);
    Complex operator/(const Complex& complex);

    Complex operator+=(const Complex& complex);
    Complex operator-=(const Complex& complex);
    Complex operator*=(const Complex& complex);
    Complex operator/=(const Complex& complex);

    template<class T> friend std::ostream& operator << (std::ostream& os, const Complex<T>& complex);
    template<class T> friend std::istream& operator >> (std::istream& is, Complex<T>& complex);

    Complex& operator++() = delete;
    const Complex operator++(int) = delete;

};


#endif //GAMES_COMPLEX_HPP
