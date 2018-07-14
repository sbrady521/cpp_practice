#include "complex.h"

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other): real(other.real), imaginary(other.imaginary) {}

Complex::~Complex() {}

bool Complex::operator==(const Complex &other) const 
{
    return (real == other.real) && (imaginary == other.imaginary);
}

bool Complex::operator!=(const Complex &other) const 
{
    return !(*this==other);
}

const Complex &Complex::operator=(const Complex &other)
{
    real = other.real;
    imaginary = other.imaginary;

    return *this;
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << "(" << c.getReal() << ", " << c.getImaginary() << ")";
    return out;
}

Complex operator+(Complex &a, const Complex &b)
{
    return Complex(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
}

Complex operator+(double d, const Complex &b) 
{
    return Complex(d + b.getReal(), b.getImaginary());
}

Complex operator+(Complex &a, const double d) 
{
    return Complex(a.getReal() + d, a.getImaginary());
}
