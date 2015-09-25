#include "ComplexMatrix.h"
#include "Complex.h"
#include <stdexcept>
#include <iomanip>
#include <iostream>

ComplexMatrix::ComplexMatrix()
:dimension(0)
{
    
}

ComplexMatrix::ComplexMatrix(unsigned long MatrixSize)

{
    if(MatrixSize == 0)
        std::cout<<"Matrix size must be greater than 0\n";
    else
    {
        dimension = MatrixSize;
        ptr = new Complex[dimension*dimension];
    }
    
    /*for (size_t i = 0; i < size; ++i){
     for (size_t j = 0; j < size; ++j){
     ptr[ i * size + j].real = 3;
     ptr[ i * size + j].imaginary = 3;
     }
     }*/
}





ComplexMatrix::ComplexMatrix( const ComplexMatrix &MatrixToCopy )
: dimension( MatrixToCopy.dimension)
{
    ptr = new Complex[dimension*dimension]; // create space for pointer-based Matrix
    
    for (size_t i = 0; i < dimension; ++i){
        for (size_t j = 0; j < dimension; ++j){
            ptr[ i * dimension + j] = MatrixToCopy.ptr[ i * dimension + j];
            //ptr[ i * size + j].imaginary = MatrixToCopy.ptr[ i * size + j].imaginary;
        }
    }
    
}

ComplexMatrix::~ComplexMatrix()
{
    delete [] ptr;
    std::cout<<"The memory allocated for the matrix has been deleted.\n";
}

size_t ComplexMatrix::getSize() const
{
    return size;
}

std::ostream &operator << (std::ostream &output, const ComplexMatrix &a)
{
    
    for (size_t i = 0; i < a.dimension; ++i){
        for (size_t j = 0; j < a.dimension; ++j){
            
            
            output << std::setw(10) << a.ptr[ i * a.dimension + j];
            
            
        }
        output << std::endl;
    }
    return output;
}



void ComplexMatrix::fillMatrix()
{
    for (unsigned i = 0; i < dimension; ++i){
        for (unsigned j = 0; j < dimension; ++j){
            std::cout << "Element " << "(" << i << ", " << j << "): ";
            std::cin >> ptr[ i * dimension + j];/*.real;
                                            std::cin.ignore(1);
                                            std::cin >> ptr[ i * size + j].med;
                                            std::cin.ignore(2);
                                            std::cin >> ptr[ i * size + j].imaginary;
                                            if (ptr[ i * size + j].med =="-"){
                                            ptr[ i * size + j].imaginary = ptr[ i * size + j].imaginary * -1;*/
        }
    }
}


std::istream &operator >> (std::istream &input, ComplexMatrix &number)
{
    return input;
}

Complex& ComplexMatrix::operator()( int r,int c )
{
    // check for subscript out-of-range error
    /*std::cin >> ptr[ r * size + c].real;
     std::cin.ignore(1);
     std::cin >> ptr[ r * size + c].med;
     std::cin.ignore(2);
     std::cin >> ptr[ r * size + c].imaginary;
     if (ptr[ r * size + c].med =="-"){
     ptr[ r * size + c].imaginary = ptr[ r * size + c].imaginary * -1;
     }*/
    
    return ptr[r * dimension + c]; // reference return
}

/*ComplexMatrix::ComplexMatrix ( int a, int b )
 :r(a),c(b)
 {
 
 }*/

ComplexMatrix ComplexMatrix::operator + ( ComplexMatrix &op1)
{
    
    ComplexMatrix B(dimension);
    for (unsigned i = 0; i < dimension; ++i){
        for (unsigned j = 0; j < dimension; ++j){
            B.ptr[ i * dimension + j] = ptr[ i * dimension + j] + op1.ptr[ i * dimension + j];
        }
    }

    return B;
}





ComplexMatrix ComplexMatrix::operator * ( ComplexMatrix &obj2)
{
    
    ComplexMatrix C(dimension);
    for (unsigned i = 0; i < dimension; ++i){
        for (unsigned j = 0; j < dimension; ++j){
            for (unsigned k = 0; k < dimension; ++k){

                C.ptr[ i * dimension + j] = C.ptr[ i * dimension + j] +
                (ptr[ i * dimension + k] * obj2.ptr[ k * dimension + j]);
            }
            
        }
    }
    //std::cout<<C<<std::endl;
    return C;
}

