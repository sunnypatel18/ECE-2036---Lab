#include "Complex.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>

Complex::Complex(float a, float b)
    :real(a), imaginary(b)
{

}

Complex::Complex()
    :real(0), imaginary(0)
{
    
}

std::ostream &operator << (std::ostream &output, const Complex &number)
{
    if (number.imaginary >= 0){
        output << number.real << " + i" << number.imaginary;
    }
    else if (number.imaginary < 0){
        output << number.real << " - i" << number.imaginary * -1;
    }
    return output;
}

std::istream &operator >> (std::istream &input, Complex &number)
{
    input >> number.real;
    input.ignore(1);
    input >> number.med;
    input.ignore(2);
    input >> number.imaginary;
    if (number.med =="-"){
        number.imaginary = number.imaginary * -1;
    }
    return input; 
}

double abs(Complex &obj1)
{
    return sqrt(obj1.real * obj1.real + obj1.imaginary * obj1.imaginary);
}

Complex &Complex::operator++ ()
{
    helpIncrement();
    return *this;
}

Complex Complex::operator++ (int)
{
    Complex temp = *this;
    helpIncrement();
    return temp;
}

Complex &Complex::operator-- ()
{
    helpDecrement();
    return *this;
}

Complex Complex::operator-- (int)
{
    Complex temp = *this;
    helpDecrement();
    return temp;
}

void Complex::helpIncrement()
{
    ++real;
}

void Complex::helpDecrement()
{
    --real;
}

Complex Complex::operator + (const Complex &obj1)
{
    double result_real = real + obj1.real;
    double result_imaginary = imaginary + obj1.imaginary;
    return Complex( result_real, result_imaginary );
}

Complex Complex::operator * (const Complex &obj1)
{
    double result_real = real * obj1.real - imaginary * obj1.imaginary;
    double result_imaginary = real * obj1.imaginary + imaginary * obj1.real;
    return Complex( result_real, result_imaginary );
}

Complex Complex::operator + (double &op2)
{
    return Complex( real + op2 , this->imaginary );
}

Complex operator + (double &op1, const Complex &op2)
{
   return Complex( op2.real + op1 , op2.imaginary );
}


