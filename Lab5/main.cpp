#include <iostream>
#include "Complex.h"
#include "ComplexMatrix.h"

using namespace std;

int main()
{
    //  This section will test your Complex class.
    Complex c1(1.0, 5.0);  // this should create Complex object 1.0 + i5.0
    Complex c2, c3, c4;  // these should all be initialized to 0.0 + i0.0
    double d1;
    
    //  Print out c1 and c2 to check them
    cout << "Initial variable values:" << endl;
    cout << "c1 = " << c1 << ", c2 = " << c2 << endl << endl;
    
    //  Prompt user to input a complex number
    cout << "Please enter complex number c3, in the format X + iY, or X - iY: ";
    cin >> c3;
    //  Print out c3 to check it
    cout << "You entered c3 = " << c3 << endl;
    //  Print out the absolute value of c3
    cout << "The absolute value of c3 = " << abs(c3) << endl;
    //  Postdecrement c3.  Decrementing should only affect the real part
    cout << "c3 is postdecremented in this statement.  c3 = " << c3-- << endl;
    //  Predecrement c3.  Decrementing should only affect the real part
    cout << "c3 is predecremented in this statement.  c3 = " << --c3 << endl << endl;
    
    //  Prompt user for double precision number and check the addition operator.
    cout << "Please enter a double precision number d1: ";
    cin >> d1;
    
    cout << "d1 + c3 = " << (d1 + c3) << endl;
    cout << "c3 + d1 = " << (c3 + d1) << endl << endl;
    
    //  Prompt user for complex number and check addition and multiplication.
    cout << "Please enter another complex number c4, in the format X + iY, or X - iY: ";
    cin >> c4;
    
    cout << "c3 + c4 = " << (c3 + c4) << endl;
    cout << "c3 * c4 = " << (c3 * c4) << endl << endl;
    
    
    //  This section will test your ComplexMatrix class
    //   User inputs the square matrix size, and the matrix is created.
    int size, row, column;
    cout << "Please enter an integer size for the complex matrix M1: ";
    cin >> size;
    ComplexMatrix M1(size);
    //   User is prompted to enter each element of the matrix individually.
    cout << "You will now be prompted to enter the complex elements of M1." << endl;
    M1.fillMatrix();
    //   Check that it was entered properly.
    cout << "You entered M1 = " << endl;
    cout << M1 << endl;
    
    //  Make a copy of M1 called M2, and check it.
    ComplexMatrix M2(M1);
    cout << "After copying from M1, M2 = " << endl;
    cout << M2 << endl;
    
    //  Modify a single element of M2, and check it.
    //    User enters the row, column, and new element separately.
    //    Remember that row and column numbering starts at 0.
    cout << "We will now modify a single element of M2." << endl;
    cout << "Please enter the row of the element of M2 to modify, remembering that we are counting from 0 in C++: ";
    cin >> row;
    cout << "Please enter the column of the element of M2 to modify: ";
    cin >> column;
    cout << "Please enter a new complex value for the element: ";
    cin >> M2(row, column);
    cout << "After modifying the element, M2 = " << endl;
    cout << M2 << endl;
    
    //  Check addition and multiplication.
    //  Add M1 and M2
    ComplexMatrix M3 = M1 + M2;
    cout << "M3 = M1 + M2 = " << endl;
    cout << M3;
    
    //  Multiply M2 and M3
    ComplexMatrix M4 = M2 * M3;
    cout << "M4 = M2 * M3 = " << endl;
    cout << M4;
    
}
