//
// Created by Busiu on 23.09.2018.
//

#include "Complex.hpp"

template <class T>
Complex<T>::Complex(T x, T y)
{
    this->x = x;
    this->y = y;
}
template <class T>
Complex<T>::Complex()
{
    this->x = 0;
    this->y = 0;
}

template <class T>
Complex<T> Complex<T>::operator+(const Complex& complex)
{
    Complex<T> tmp;
    tmp.x = this->x + complex.x;
    tmp.y = this->y + complex.y;

    return tmp;
}
template <class T>
Complex<T> Complex<T>::operator-(const Complex& complex)
{
    Complex<T> tmp;
    tmp.x = this->x - complex.x;
    tmp.y = this->y - complex.y;

    return tmp;
}
template <class T>
Complex<T> Complex<T>::operator*(const Complex& complex)
{
    Complex<T> tmp;
    tmp.x = this->x * complex.x - this->y * complex.y;
    tmp.y = this->x * complex.y + this->y * complex.x;

    return tmp;
}
template <class T>
Complex<T> Complex<T>::operator/(const Complex& complex)
{
    Complex<T> tmp;
    tmp.x = this->x * complex.x + this->y * complex.y;
    tmp.x /= (complex.x * complex.x + complex.y * complex.y);
    tmp.y = this->y * complex.x - this->x * complex.y;
    tmp.y /= (complex.x * complex.x + complex.y * complex.y);

    return tmp;
}

template <class T>
Complex<T> Complex<T>::operator+=(const Complex& complex)
{
    this->x += complex.x;
    this->y += complex.y;
}
template <class T>
Complex<T> Complex<T>::operator-=(const Complex& complex)
{
    this->x -= complex.x;
    this->y -= complex.y;
}
template <class T>
Complex<T> Complex<T>::operator*=(const Complex& complex)
{
    this->x *= complex.x;
    this->y *= complex.y;
}
template <class T>
Complex<T> Complex<T>::operator/=(const Complex& complex)
{
    this->x /= complex.x;
    this->y /= complex.y;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& complex)
{
    os << "(" << complex.x << " ," << complex.y << ")";
    return os;
}
template <class T>
std::istream& operator>>(std::istream& is, Complex<T>& complex)
{
    is >> complex.x >> complex.y;
    return is;
}
