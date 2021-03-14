#include "ComplexNumber.h"
#include <iostream>


ComplexNumber::ComplexNumber() {
    this -> Real = 0;
    this -> Imaginary = 0;
}

ComplexNumber::ComplexNumber(double Real, double Imaginary) {
    this -> Real = Real;
    this -> Imaginary = Imaginary;
}

void ComplexNumber::setReal(double Real) {
    this -> Real = Real;
}

void ComplexNumber::setImaginary(double Imaginary) {
    this ->Imaginary = Imaginary;
}

double ComplexNumber::getReal() {
    return (this -> Real);
}

double ComplexNumber::getImaginary() {
    return (this -> Imaginary);
}

ComplexNumber ComplexNumber::operator+ (const ComplexNumber &complexObject) {
    ComplexNumber result;
    result.setReal(Real + complexObject.Real);
    result.setImaginary(Imaginary + complexObject.Imaginary);
    return result;
}

ComplexNumber ComplexNumber::operator- (const ComplexNumber &complexObject) {
    ComplexNumber result;
    result.setReal(Real - complexObject.Real);
    result.setImaginary(Imaginary - complexObject.Imaginary);
    return result;
}

bool operator==(const ComplexNumber &complexObject1, const ComplexNumber &complexObject2) {
    if(complexObject1.Real == complexObject2.Real && complexObject1.Imaginary == complexObject2.Imaginary){
        return true;
    }else{
        return false;
    }
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &complexObject) {
    ComplexNumber result;
    result.setReal(Real * complexObject.Real - Imaginary * complexObject.Imaginary);
    result.setImaginary(Real * complexObject.Imaginary + Imaginary * complexObject.Real);
    return result;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &complexObject) {
    ComplexNumber result;
    if(complexObject.Imaginary == 0 && complexObject.Real == 0){
        throw std::invalid_argument("zero division");
    }else {

        result.setReal((Real * complexObject.Real + Imaginary * complexObject.Imaginary) /
                       (complexObject.Real * complexObject.Real + complexObject.Imaginary * complexObject.Imaginary));
        result.setImaginary((-1 * Real * complexObject.Imaginary + Imaginary * complexObject.Real) /
                            (complexObject.Real * complexObject.Real +
                             complexObject.Imaginary * complexObject.Imaginary));
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const ComplexNumber &complexObject) {
    if(complexObject.Imaginary < 0){
        os << "(" << complexObject.Real << complexObject.Imaginary << "i)";
    }else{
        os << "(" << complexObject.Real << "+" << complexObject.Imaginary << "i)";
    }
    return os;
}

std::istream &operator>>(std::istream &ist, ComplexNumber &complexObject) {

    double real, imaginary;
    char oper, i, bra, ket;

    ist >> bra >> real >> oper >> imaginary >> i >> ket;
    if ((bra != '(') || (ket != ')') || (i != 'i')|| ((oper != '-') && (oper != '+'))){
        throw std::invalid_argument("unknown argument");
    }
    if(oper == '-'){
        complexObject.Real = real;
        complexObject.Imaginary = imaginary * (-1);
    }else{
        complexObject.Real = real;
        complexObject.Imaginary = imaginary;
    }

    return ist;
}


