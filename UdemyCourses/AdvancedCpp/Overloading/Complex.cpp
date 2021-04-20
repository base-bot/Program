#include "Complex.h"

ostream &operator<<(ostream &out, const Complex &c){
    out << "(" << c.getReal() << " , " << c.getImm() << ")" <<endl;
    return out; 
}

Complex::Complex(const Complex &other){
    // *this = other;
    real = other.real;
    imm = other.imm;
}

Complex::Complex(): real(0), imm(0){

}

Complex::Complex(double real, double imm): real(real), imm(imm){


}

const Complex &Complex::operator=(const Complex &other){
    real = other.real;
    imm = other.imm;
    return *this;
}

Complex operator+(const Complex &c1, const Complex &c2){
    return Complex(c1.getReal()+c2.getReal(), c1.getImm()+c2.getImm());
}

Complex operator+(const Complex &c1, double d){
    return Complex(c1.getReal()+d, c1.getImm());
}

Complex operator+(double d, const Complex &c1){
    return Complex(c1.getReal()+d, c1.getImm());
}


bool Complex::operator==(const Complex &c1) const{
    return real == c1.real && imm == c1.imm;
}
bool Complex::operator!=(const Complex &c1) const{
    return !(*this==c1);
}
