#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
namespace Numbers
{
    class Matrix
    {
        int rows;
        int columns;
        int **layer;

        public:     
            Matrix();
            Matrix(unsigned int m, unsigned int n);
            unsigned int rows() const;
            unsigned int columns() const;
            void destroyMatrix();
            void printMatrix();
    };
}
#endif