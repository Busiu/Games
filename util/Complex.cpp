//
// Created by Busiu on 23.09.2018.
//

#include "Complex.hpp"

Complex::Complex(double x, double y)
{
    this->x = x;
    this->y = y;
}
Complex::Complex()
{
    this->x = 0;
    this->y = 0;
}

Complex Complex::operator+(const Complex& complex)
{
    Complex tmp;
    tmp.x = this->x + complex.x;
    tmp.y = this->y + complex.y;

    return tmp;
}
Complex Complex::operator-(const Complex& complex)
{
    Complex tmp;
    tmp.x = this->x - complex.x;
    tmp.y = this->y - complex.y;

    return tmp;
}
Complex Complex::operator*(const Complex& complex)
{
    Complex tmp;
    tmp.x = this->x * complex.x - this->y * complex.y;
    tmp.y = this->x * complex.y + this->y * complex.x;

    return tmp;
}
Complex Complex::operator/(const Complex& complex)
{
    Complex tmp;
    tmp.x = this->x * complex.x + this->y * complex.y;
    tmp.x /= (complex.x * complex.x + complex.y * complex.y);
    tmp.y = this->y * complex.x - this->x * complex.y;
    tmp.y /= (complex.x * complex.x + complex.y * complex.y);

    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
    os << "(" << complex.x << " ," << complex.y << ")";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& complex)
{
    is >> complex.x >> complex.y;
    return is;
}
