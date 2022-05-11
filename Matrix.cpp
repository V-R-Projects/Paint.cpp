#include "Matrix.hpp"

using namespace std;

Matrix::Matrix()
{
    createMatrix();
}

Matrix *Matrix::getInstance()
{
    if (matrix_instance == NULL)
    {
        matrix_instance = new Matrix();
    }

    return matrix_instance;
}

void Matrix::setSize(int h, int w)
{
    height = h;
    width = w;
}

void Matrix::createMatrix()
{
    matrix = (Pixel **) malloc(sizeof(Pixel*) * height);
    for (int j; j < height; j++)
    {
        matrix[j] = (Pixel *)malloc(sizeof(Pixel) * width);
    }

    initializePixels();
}

void Matrix::initializePixels()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; i < width; j++)
        {
            matrix[i][j] = Pixel();
        }
    }
}