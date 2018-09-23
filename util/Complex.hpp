//
// Created by Busiu on 23.09.2018.
//

#ifndef GAMES_COMPLEX_HPP
#define GAMES_COMPLEX_HPP

#include "../Libraries.hpp"

class Complex {
private:
    double x;
    double y;

public:
    Complex(double x, double y);
    Complex();

    Complex operator+(const Complex& complex);
    Complex operator-(const Complex& complex);
    Complex operator*(const Complex& complex);
    Complex operator/(const Complex& complex);

    friend std::ostream& operator << (std::ostream& os, const Complex& complex);
    friend std::istream& operator >> (std::istream& is, Complex& complex);

    Complex& operator++() = delete;
    const Complex operator++(int) = delete;

};


#endif //GAMES_COMPLEX_HPP
