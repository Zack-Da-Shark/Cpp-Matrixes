#include <iostream>
#include "Matrix.h"
#include <string>
using namespace Numbers;
int main()
{
    cout << "Trying to create Matrix";
    Matrix *test = new Matrix(3,3);
    test->printMatrix();
    test->destroyMatrix();
    return 0;
}