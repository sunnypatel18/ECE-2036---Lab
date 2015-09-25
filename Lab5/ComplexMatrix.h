#include <iostream>
#include <string>
#include "Complex.h"

class ComplexMatrix
{
private:
    unsigned long dimension;
    size_t size;
    //double real;
    //double imaginary;
    //std::string med;
    int r, c;
    Complex *ptr;
    
public:
    //const ComplexMatrix &operator=( const ComplexMatrix & );
    explicit ComplexMatrix();  // constructor, with NO argument
    explicit ComplexMatrix(unsigned long);  // constructor, with  argument default to 0
    explicit ComplexMatrix(int,int);
    size_t getSize() const;
    ComplexMatrix( const ComplexMatrix &); //copy constructor
    ~ComplexMatrix(); // destructor
    void CreateMatrix();
    void fillMatrix();
    Complex& operator()( int ,int  );
    //const ComplexMatrix &operator = ( const ComplexMatrix &);
    friend std::ostream &operator << (std::ostream &, const ComplexMatrix &);
    friend std::istream &operator >> (std::istream &, ComplexMatrix &);
    
    
    
    ComplexMatrix operator + ( ComplexMatrix &); //works with c1 + c2
    ComplexMatrix operator * ( ComplexMatrix &); //works with c1 * c2
};