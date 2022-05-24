#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(int height, int width)
{
    this->height = height;
    this->width = width;
    createMatrix();
}

void Matrix::setSize(int h, int w)
{
    height = h;
    width = w;
}

void Matrix::createMatrix()
{
    matrix = (Pixel ***)malloc(sizeof(Pixel **) * height);
    for (int i = 0; i < height; i++)
    {
        matrix[i] = (Pixel **)malloc(sizeof(Pixel *) * width);
    }
    initializePixels();
}

void Matrix::printMatrix()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << i << "," << j << ": ";
            matrix[i][j]->print();
        }
    }
}

void Matrix::initializePixels()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            matrix[i][j] = new Pixel();
        }
    }
}

Pixel ***Matrix::getMatrix()
{
    return matrix;
}

int Matrix::getHeight()
{
    return height;
}

int Matrix::getWidth()
{
    return width;
}

void Matrix::pencil(CurrentColor color, int i, int j, int line_width)
{
    int line_width_limit = line_width - 1;

    for (int m = i - line_width_limit; m <= i + line_width_limit; m++)
    {
        for (int n = j - line_width_limit; n <= j + line_width_limit; n++)
        {
            if ((m >= 0) && (m < width) && (n >= 0) && (n < height))
            {
                setColor(matrix[m][n], color);
                // matrix[m][n]->setColor(color.getR(), color.getG(), color.getB());
            }
        }
    }
}

void Matrix::pen(CurrentColor color, int x1, int y1, int x2, int y2, int line_width)
{
    if (x2 - x1 == 0)
    {
        if (y2 < y1)
        {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }
        for (int i = y1; i <= y2; i++)
        {
            pencil(color, i, x1, line_width);
        }
    }
    else
    {

        float m = (float)(y2 - y1) / (float)(x2 - x1);
        float b = y1 - (m * x1);

        if (x2 < x1)
        {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }

        int old_y = round(m * x1 + b);

        for (int i = x1; i <= x2; i++)
        {
            int new_y = round(m * i + b);

            if (new_y == old_y)
            {
                pencil(color, new_y, i, line_width);
            }

            else
            {
                if (m >= 0)
                {
                    for (int j = old_y + 1; j <= new_y; j++)
                    {
                        pencil(color, j, i, line_width);
                    }
                }
                else
                {
                    for (int j = old_y - 1; j >= new_y; j--)
                    {
                        pencil(color, j, i, line_width);
                    }
                }
            }
            old_y = new_y;
        }
    }
}

void Matrix::setColor(Pixel *pixel, CurrentColor color)
{
    pixel->setPixelColor(color.getR(), color.getG(), color.getB());
}

Pixel *Matrix::getPixel(int i, int j)
{
    return matrix[i][j];
}

void Matrix::grayScaleFilter()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel *pixel = getPixel(i, j);
            float formula = 0.3 * (pixel->getRed()) + 0.59 * (pixel->getGreen()) + 0.11 * (pixel->getBlue());
            setColor(matrix[i][j], CurrentColor(formula, formula, formula));
        }
    }
}

void Matrix::negativeFilter()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel *pixel = getPixel(i, j);
            setColor(matrix[i][j], CurrentColor(255 - (pixel->getRed()), 255 - (pixel->getGreen()), 255 - (pixel->getBlue())));
        }
    }
}

void Matrix::rotate()
{
    // hacer que las filas sean columnas y viceversa
}

void Matrix::deleteMatrix()
{
    for (int i = 0; i < height; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::switchDimentions()
{
    int temp = width;
    width = height;
    height = temp;
}

void Matrix::eraser(int i, int j, int eraserWidth)
{
    CurrentColor white = CurrentColor(255, 255, 255);
    pencil(white, i, j, eraserWidth);
}