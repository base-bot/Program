#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex{
private:
    double real;
    double imm;

public:
    Complex(); //Empty Constructor
    Complex(double real, double imm); //Constructor
    Complex(const Complex &other); //Copy Constructor
    const Complex &operator=(const Complex &other);

    double getReal() const{
        return real;
    }
    double getImm() const{
        return imm;
    }

    bool operator==(const Complex &c1) const;
    bool operator!=(const Complex &c1) const;
};

ostream &operator<<(ostream &out, const Complex &c);

Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

#endif