#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>
#include <string>

class Complex
{
private:

    double real;
    double imaginary;
    std::string med;

public:

    
    explicit Complex();  // constructor, with NO argument
    explicit Complex(float, float);  // constructor, with  argument
    friend std::ostream &operator << (std::ostream &, const Complex &);
    friend std::istream &operator >> (std::istream &, Complex &);
    friend double abs(Complex &);

    Complex &operator++ ();    // prefix ++
    Complex  operator++ (int); // postfix ++
    Complex &operator-- ();    // prefix --
    Complex  operator-- (int); // postfix --
    
    
    Complex operator + (const Complex &); //works with c1 + c2
    Complex operator + (double &); //works with c1 + 10.0
    friend Complex operator + (double &, const Complex &); //works with 10.0 + c1
    Complex operator * (const Complex &); //works with c1 * c2

    void helpIncrement();
    void helpDecrement();
    
};
#endif



