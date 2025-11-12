#include "Matrix.h"
#include <iostream>
#include <string>

using namespace Numbers;

//Matrix constryctor
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

//Matrx copier
Matrix::Matrix(const Matrix& mat)
{
    //Copy mat to this
    this->rows = mat.rows;
    this->columns = mat.columns;

    layer = new int* [rows];
    //Make arrays of pointers (rows)
    //Pointers go to columns
    for (int i = 0; i < rows; i++)
    {
        layer[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            layer[i][j] = mat.layer[i][j];
        }
    }
}

void Matrix::destroyMatrix()
{
    cout << "MATRIX ANNHILATIONS\n";
    for(int i = 0; i < rows; i++)
        delete[] layer[i];
    delete[] layer;
}
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] layer[i];
    delete[] layer;
    //cout << "MATRIX ANNHILATIONS\n";
    //Much better way
    //Will need an = operator now
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
    //cout << "Value changed to " << value << endl;
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

Matrix Matrix::operator~()
{
    //Here we go, transposing time and not murder everything
    Matrix result(this->getColumns(), this->getRows());

    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = 0; j < this->getColumns(); j++)
        {
            int element = 0;
            element = this->getElement(i, j);
            result.layer[j][i] = element;
        }
    }

    //FIRST FUCKING TRY LETS GOOOOOOOOOOO
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
}

Matrix Matrix::operator=(const Matrix& mat)
{
    for (int i = 0; i < rows; i++)
        delete[] layer[i];
    delete[] layer;


    rows = mat.rows;
    columns = mat.columns;

    layer = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        layer[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            layer[i][j] = mat.layer[i][j];
    }

    return *this;
}
