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

void Matrix::printMatrix(Pixel ***matrix, bool traspose)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << i << "," << j << ": " << endl;
            if (traspose)
            {
                matrix[j][i]->print();
            }
            else
            {
                matrix[i][j]->print();
            }
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
            if ((m >= 0) && (m < height) && (n >= 0) && (n < width))
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
void Matrix::polygon(CurrentColor color, int x, int y, int l, int n, int line_width)
{
    const double pi = std::acos(-1);
    float outer_angle = 2*pi / n;
    for (int i = 0; i < n; i++)
    {
        pen(color, x, y, x + (l * cos(outer_angle * i)), y + (l * sin(outer_angle * i)), line_width);
        x = x + l * cos(outer_angle * i);
        y = y + l * sin(outer_angle * i);
    }
}

void Matrix::rectangle(CurrentColor color, int x, int y, int b, int h, int line_width)
{
    pen(color, x, y, x+b, y, line_width);
    pen(color, x+b, y, x+b, y+h, line_width);
    pen(color, x+b, y+h, x, y+h, line_width);
    pen(color, x, y+h, x, y, line_width);
}

void Matrix::circle(CurrentColor color, int h, int k, int r, int line_width)
{
    const double pi = std::acos(-1);
    int x1 = h -r;
    int x2 = h + r;
    
    for (float x = h-r; x <= h+r; x = x + 0.001)
    {
        int r2 = r*r;
        float y1 = (float)sqrt((r2)-((x-h)*(x-h)))+k;
        float y2 = (-1)*(float)sqrt((r2)-((x-h)*(x-h)))+k;

        pencil(color, x, y1, line_width);
        pencil(color, x, y2, line_width);
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
void Matrix::traspose()
{
    Pixel ***temp_matrix = (Pixel ***)malloc(sizeof(Pixel **) * width);
    for (int i = 0; i < width; i++)
    {
        temp_matrix[i] = (Pixel **)malloc(sizeof(Pixel *) * height);
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_matrix[j][i] = matrix[i][j];
        }
    }
    Pixel ***matrix_to_delete = nullptr;
    matrix_to_delete = matrix;
    matrix = temp_matrix;
    switchDimentions();

    deleteMatrix(matrix_to_delete);
}

void Matrix::flipX()
{
    for (int i = 0; i < height / 2; i++)
    {
        // make copy of row
        Pixel **tmp = matrix[i];
        matrix[i] = matrix[height - 1 - i];
        matrix[height - 1 - i] = tmp;
    }
}

void Matrix::flipY()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixels
            Pixel *tmp = matrix[i][j];
            matrix[i][j] = matrix[i][width - 1 - j];
            matrix[i][width - 1 - j] = tmp;
        }
    }
}

void Matrix::rotate()
{
    traspose();
    flipY();
}

void Matrix::BFS(CurrentColor picked_color, CurrentColor new_color, int x, int y)
{
    memoryFlag++;
    if (x < width && y < height && x >= 0 && y >= 0 && memoryFlag < 350*350)
    {
        int picked_red = picked_color.getR();
        int picked_green = picked_color.getG();
        int picked_blue = picked_color.getB();

        CurrentColor current_color = getPixel(x, y)->getColor();
        int current_red = current_color.getR();
        int current_green = current_color.getG();
        int current_blue = current_color.getB();

        if (current_blue == picked_blue && current_green == picked_green && current_red == picked_red)
        {
            setColor(getPixel(x, y), new_color);
            BFS(picked_color, new_color, x-1, y);
            BFS(picked_color, new_color, x+1, y);
            BFS(picked_color, new_color, x, y-1);
            BFS(picked_color, new_color, x, y+1);
        }
    
    }
}

void Matrix::paintFill(CurrentColor picked_color, CurrentColor new_color, int x, int y)
{
    setMemoryFlag(0);
    
    int picked_red = picked_color.getR();
    int picked_green = picked_color.getG();
    int picked_blue = picked_color.getB();

    int new_red = new_color.getR();
    int new_green = new_color.getG();
    int new_blue = new_color.getB();

    if (picked_red != new_red && picked_green != new_green && picked_blue != new_blue)
    {
        BFS(picked_color, new_color, x, y);
    }
}

void Matrix::setMemoryFlag(int flag)
{
    memoryFlag = flag;
}

void Matrix::deleteMatrix(Pixel ***temp_matrix)
{
    for (int i = 0; i < width; i++)
    {
        delete[] temp_matrix[i];
    }
    delete[] temp_matrix;
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

void Matrix::ramFilter()
{
    srand(time(NULL));
    int add = rand() % 255;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            matrix[i][j]->setPixelColor(matrix[i][j]->getColor().addToColor(add));
        }
    }
}

void Matrix::sepiaFilter()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            CurrentColor color_temp = getPixel(i, j)->getColor();
            float newR = 0.393 * color_temp.getR() + 0.769 * color_temp.getG() + 0.189 * color_temp.getB();
            float newG = 0.349 * color_temp.getR() + 0.686 * color_temp.getG() + 0.168 * color_temp.getB();
            float newB = 0.272 * color_temp.getR() + 0.534 * color_temp.getG() + 0.131 * color_temp.getB();
            setColor(getPixel(i, j), CurrentColor(newR, newG, newB));
        }
    }
}