#include "Matrix.h"
#include <iostream>
#include <string>

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
            int value = 0;
            layer[i][j] = value;
        }
    }
}

void Matrix::destroyMatrix()
{
    cout << "MATRIX ANNHILATIONS\n";
    for(int i = 0; i < rows; i++)
    {
        delete[] layer[i];
    }
    delete[] layer;
}

unsigned int Matrix::getRows() const
{
    return rows;
}

unsigned int Matrix::getColumns() const
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

int Matrix::getElement(unsigned i, unsigned j)
{
    int x = i, y = j; 
    int output = 0;
    output = layer[x][y];
    return output;
}

void Matrix::setElement(unsigned i, unsigned j, int value)
{
    layer[i][j] = value;
    cout << "Value changed to " << value << endl;
}

std::string Matrix::toString()
{
    std::string output;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            output += std::to_string(layer[i][j]);

            if (j < columns - 1)
                output += ", ";
        }
        output += "\n";
    }

    return output;
}


//All the operator overloading will be here
Matrix Matrix::operator+(const Matrix& mat)
{
    Matrix result(rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.layer[i][j] = this->layer[i][j] + mat.layer[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& mat)
{

    Matrix result(rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.layer[i][j] = this->layer[i][j] - mat.layer[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& mat)
{

    Matrix result(rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.layer[i][j] = this->layer[i][j] * mat.layer[i][j];
        }
    }

    return result;
}

bool Matrix::operator==(const Matrix& mat)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (this->layer[i][j] != mat.layer[i][j])
                return false;
        }
    }

    return true;
}/*
*/