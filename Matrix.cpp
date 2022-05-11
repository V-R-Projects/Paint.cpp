#include "Matrix.hpp"

using namespace std;

Matrix::Matrix()
{
    printf("Prueba cons \n");
    createMatrix();
}

// Matrix *Matrix::getInstance()
// {
//     if (matrix_instance == NULL)
//     {
//         matrix_instance = new Matrix();
//     }

//     return matrix_instance;
// }

void Matrix::setSize(int h, int w)
{
    height = h;
    width = w;
}

void Matrix::createMatrix()
{
    matrix = new Pixel *;
    printf("Prueba 2\n");
    for (int j; j < height; j++)
    {
        matrix[j] = new Pixel;
    }
    printf("Prueba 3\n");

    initializePixels();
}

void Matrix::initializePixels()
{
    printf("prueba 4\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; i < width; j++)
        {
            *(*(matrix + i) + j) = Pixel();
            printf("prueba 5\n");
        }
    }
}