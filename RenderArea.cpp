#include "RenderArea.hpp"

using namespace std;

RenderArea::RenderArea(int width, int heigth, QWidget *parent)
    : QWidget(parent)
{
    shape = Pencil;
    filter = None;
    isSecondPoint = false;


    this->matrix = new Matrix(width, heigth);

    setBackgroundRole(QPalette::Window);
    setAutoFillBackground(true);
    color = Qt::black;
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 400);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(this->matrix->getWidth(), this->matrix->getHeight());
}

void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    isSecondPoint = false;
    update();
}

void RenderArea::setFilter(Filter filter)
{
    this->filter = filter;
    switch (filter)
    {
    case BlackAndWhite:
        matrix->grayScaleFilter();
        break;
    case Sepia:
        matrix->sepiaFilter();
        break;
    case Negative:
        matrix->negativeFilter();
        break;
    case Random:
        matrix->ramFilter();
        break;
    }
    update();
}

void RenderArea::setPenWidth(int pen)
{
    this->penWidth = pen + 2;
}

void RenderArea::setColor(QColor color)
{
    this->color = color;
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::rotateRight()
{
    this->matrix->rotate();
    update();
}

void RenderArea::rotateLeft()
{
    this->matrix->rotate();
    this->matrix->rotate();
    this->matrix->rotate();
    update();
}

void RenderArea::flipHorizontal()
{
    this->matrix->flipY();
    update();
}

void RenderArea::flipVertical()
{
    this->matrix->flipX();
    update();
}

void RenderArea::save(char *name)
{
    Bitmap *bitmap = new Bitmap(matrix->getMatrix(), matrix->getWidth(), matrix->getHeight(), name);
}

void RenderArea::load(char *path)
{
    Bitmap *bitmap = new Bitmap(path);
    cout << "hola 1" << endl;
    Pixel ***pixel_pointers = bitmap->pixelArrayToMatrix();
    cout << "hola 2" << endl;
    Matrix *read_matrix = new Matrix(bitmap->getHeight(), bitmap->getWidth());
    cout << "hola 3" << endl;
    read_matrix->setMatrix(pixel_pointers);
    cout << "hola 4" << endl;
    // read_matrix->printMatrix(read_matrix->getMatrix());
    this->matrix = new Matrix(bitmap->getHeight(), bitmap->getWidth());
    matrix->setMatrix(pixel_pointers);

    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    int x = width() / 2 - matrix->getWidth() / 2;
    int y = height() / 2 - matrix->getHeight() / 2;
    QPainter painter(this);

    painter.translate(x, y);
    {
        for (int i = 0; i < matrix->getHeight(); i++)
        {
            for (int j = 0; j < matrix->getWidth(); j++)
            {
                pen.setColor(QColor(
                    matrix->getPixel(i, j)->getRed(),
                    matrix->getPixel(i, j)->getGreen(),
                    matrix->getPixel(i, j)->getBlue()));
                painter.setPen(pen);
                painter.save();
                painter.drawPoint(j, i);
            }
        }
        painter.restore();
    }
}

void RenderArea::mousePressEvent(QMouseEvent *event)
{
    int x_margin = width() / 2 - matrix->getWidth() / 2;
    int y_margin = height() / 2 - matrix->getHeight() / 2;

    int x = event->x() - x_margin;
    int y = event->y() - y_margin;

    lastPoint = currentPoint;
    currentPoint = QPoint(x, y);

    switch (shape)
    {
    case Pencil:
        // doPencil();
        break;
    case Pen:
        if (isSecondPoint)
        {
            doPen();
            isSecondPoint = false;
        }
        else
        {
            isSecondPoint = true;
        }
        break;
    case Eraser:
        doEraser();
        break;
    case Square:
        if (isSecondPoint)
        {
            doSquare();
            isSecondPoint = false;
        }
        else
        {
            isSecondPoint = true;
        }
        break;
    case Rectangle:
        if (isSecondPoint)
        {
            doRectangle();
            isSecondPoint = false;
        }
        else
        {
            isSecondPoint = true;
        }
        break;
    case Triangle:
        if (isSecondPoint)
        {
            doTriangle();
            isSecondPoint = false;
        }
        else
        {
            isSecondPoint = true;
        }
        break;
    case Pentagon:
        if (isSecondPoint)
        {
            doPentagon();
            isSecondPoint = false;
        }
        else
        {
            isSecondPoint = true;
        }
        break;
    case Hexagon:
        if (isSecondPoint)
        {
            doHexagon();
            isSecondPoint = false;
        }
        else
        {
            isSecondPoint = true;
        }
        break;
    case Circle:
        if (isSecondPoint)
        {
            doCircle();
            isSecondPoint = false;
        }
        else
        {
            isSecondPoint = true;
        }
        break;
    case PaintFill:
        doPaintFill();
        break;
    case ColorPicker:
        doColorPicker();
        break;
    }

    update();
}

void RenderArea::mouseMoveEvent(QMouseEvent *event)
{
    int x_margin = width() / 2 - matrix->getWidth() / 2;
    int y_margin = height() / 2 - matrix->getHeight() / 2;

    int x = event->x() - x_margin;
    int y = event->y() - y_margin;

    lastPoint = currentPoint;
    currentPoint = QPoint(x, y);
    switch (shape)
    {
    case Pencil:
        doPen();
        break;
    case Eraser:
        doEraser();
        break;
    default:
        break;
    }

    update();
    
}

void RenderArea::mouseReleaseEvent(QMouseEvent * /* event */)
{
    update();
}

void RenderArea::doPencil()
{
    matrix->pencil(CurrentColor(color.red(), color.green(), color.blue()), currentPoint.y(), currentPoint.x(), penWidth);
}

void RenderArea::doPen()
{
    matrix->pen(CurrentColor(color.red(), color.green(), color.blue()), lastPoint.x(), lastPoint.y(), currentPoint.x(), currentPoint.y(), penWidth);
}

void RenderArea::doEraser()
{
    matrix->pen(CurrentColor(255, 255, 255), lastPoint.x(), lastPoint.y(), currentPoint.x(), currentPoint.y(), penWidth);
}

void RenderArea::doSquare()
{
    matrix->rectangle(CurrentColor(color.red(), color.green(), color.blue()), lastPoint.x(), lastPoint.y(), currentPoint.x() - lastPoint.x(), currentPoint.x() - lastPoint.x(), penWidth);
}

void RenderArea::doRectangle()
{
    matrix->rectangle(CurrentColor(color.red(), color.green(), color.blue()), lastPoint.x(), lastPoint.y(), currentPoint.x() - lastPoint.x(), currentPoint.y() - lastPoint.y(), penWidth);
}

void RenderArea::doTriangle()
{
    matrix->polygon(CurrentColor(color.red(), color.green(), color.blue()), lastPoint.x(), lastPoint.y(), currentPoint.x() - lastPoint.x(), 3, penWidth);
}

void RenderArea::doPentagon()
{
    matrix->polygon(CurrentColor(color.red(), color.green(), color.blue()), lastPoint.x(), lastPoint.y(), currentPoint.x() - lastPoint.x(), 5, penWidth);
}

void RenderArea::doHexagon()
{
    matrix->polygon(CurrentColor(color.red(), color.green(), color.blue()), lastPoint.x(), lastPoint.y(), currentPoint.x() - lastPoint.x(), 6, penWidth);
}

void RenderArea::doCircle()
{
    matrix->circle(CurrentColor(color.red(), color.green(), color.blue()), lastPoint.y(), lastPoint.x(), currentPoint.x() - lastPoint.x(), penWidth);
}

void RenderArea::doPaintFill()
{
    matrix->paintFill(matrix->getPixel(currentPoint.y(), currentPoint.x())->getColor(), CurrentColor(color.red(), color.green(), color.blue()), currentPoint.y(), currentPoint.x());
}

QColor RenderArea::doColorPicker()
{
    CurrentColor c = matrix->getPixel(currentPoint.x(), currentPoint.y())->getColor();
}



