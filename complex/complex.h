#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double real, double imaginary);
    Complex(const Complex &other);
    ~Complex();

    double getReal() const {return real;}
    double getImaginary() const {return imaginary;}

    bool operator==(const Complex &other) const;
    bool operator!=(const Complex &other) const;
    const Complex &operator=(const Complex &other);
};

ostream &operator<<(ostream &out, const Complex &c);
Complex operator+(Complex &a, const Complex &b);
Complex operator+(double d, const Complex &b);
Complex operator+(Complex &a, const double d);