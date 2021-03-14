#include <iostream>

#ifndef COMPLEXNUMBER_COMPLEXNUMBERS_H
#define COMPLEXNUMBER_COMPLEXNUMBERS_H

class ComplexNumber {
private:
    double Real;
    double Imaginary;
public:
    ComplexNumber();
    ComplexNumber(double Real, double Imaginary = 0);
    void setReal(double Real);
    void setImaginary(double Imaginary);
    double getReal();
    double getImaginary();
    ComplexNumber operator+ (const ComplexNumber &complexObject);
    ComplexNumber operator- (const ComplexNumber &complexObject);
    ComplexNumber operator* (const ComplexNumber &complexObject);
    ComplexNumber operator/ (const ComplexNumber &complexObject);
    friend bool operator==(const ComplexNumber &complexObject1, const ComplexNumber &complexObject2);
    friend std::ostream & operator<<(std::ostream &os, const ComplexNumber &complexObject);
    friend std::istream & operator>>(std::istream &ist, ComplexNumber &complexObject);
};

#endif //COMPLEXNUMBER_COMPLEXNUMBERS_H