#ifndef MATRIX_H
#define MATRIX_H
#include <string>

using namespace std;
namespace Numbers
{
    class Matrix
    {
        int rows;
        int columns;
        int **layer;

        public:     
            //Constructor, by default, fill in with values with just 0
            //Uses a nested for loop
            //m represents how much rows which will be an array of pointers
            //n represents the columns which has pointers to the values
            Matrix(unsigned int m, unsigned int n);

            /*
            * Simply returns how much rows there are in the matrix
            */
            unsigned int getRows() const;

            /*
            * Simply returns how much columns there are in the matrix
            */
            unsigned int getColumns() const;


            /*
            * Simply returns the element in row i and column j
            */
            int getElement(unsigned i, unsigned j);

            /*
            * Simply replaces the element in row i and column j with the new value
            */
            void setElement(unsigned i, unsigned j, int value);

            /*
            * Overrides the + operator to add 2 matrices to make a new matrix
            */
            Matrix operator+(const Matrix& mat);

            /*
            * Overrides the - operator to take 2 matrices away from each other to make a new matrix
            */
            Matrix operator-(const Matrix& mat);

            /*
            * Overrides the * operator to multiply 2 matrices with each other to make a new matrix
            */
            Matrix operator*(const Matrix& mat);

            /*
            * Overrides the ~ operatir to return the transpose of the current matrix
            */
            //Matrix operator~();

            /*
            * Overrides the == operator to return a booleoan value if all values in each matrix are the same
            */
            bool operator==(const Matrix& mat);

            /*
            * Simply concatonates the entire matrix into 1 string, separated by ','
            */
            string toString();

            /*
            * Simply destroys the matrix properly to keep things clean
            */
            void destroyMatrix();

            /*
            * Simply prints out the matrix
            */
            void printMatrix();
    };
}
#endif