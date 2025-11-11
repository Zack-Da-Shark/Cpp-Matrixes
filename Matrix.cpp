#include "Matrix.h"
#include <iostream>
using namespace Numbers;

Matrix::Matrix(unsigned int m, unsigned int n)
{

    this -> rows = m;
    this -> columns = n;
    
    layer = new int*[rows];
    //Make arrays of pointers (rows)
    //Pointers go to columns
    for(int i = 0; i < rows; i++)
    {
        layer[i] = new int[columns];
        for(int j = 0; j < columns; j++)
        {
            int value = i + j;
            layer[i][j] = value;
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            int value;
            value = layer[i][j];
            cout << value;
        }
    }
}

void Matrix::destroyMatrix()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] layer[i];
    }
    delete[] layer;
}

unsigned int Matrix::rows() const
{
    return rows;
}

unsigned int Matrix::columns() const
{
    return columns;
}

void Matrix::printMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int value;
            value = layer[i][j];
            cout << value;
        }
    }
}