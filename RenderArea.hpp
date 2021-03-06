#ifndef RenderArea_hpp
#define RenderArea_hpp

#include <QWidget>
#include <QAbstractButton>
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>

#include "Matrix.hpp"
#include "Bitmap.hpp"

class RenderArea : public QAbstractButton
{
    Q_OBJECT

public:
    enum Shape { Pen, Pencil, Eraser, Square, Rectangle, Triangle, Pentagon, Hexagon, Circle, PaintFill, ColorPicker};
    enum Filter { None, BlackAndWhite, Sepia, Negative, Random};

    explicit RenderArea(int width, int heigth, QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    QColor getColor();

public slots:
    void setShape(Shape shape);
    void setFilter(Filter filter);
    void setPenWidth(int pen);
    void setColor(QColor color);
    void setBrush(const QBrush &brush);

    void rotateRight();
    void rotateLeft();
    void flipHorizontal();
    void flipVertical();

    void save(char *name);
    void load(char *path);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void doPencil();
    void doPen();
    void doEraser();
    void doSquare();
    void doRectangle();
    void doTriangle();
    void doPentagon();
    void doHexagon();
    void doCircle();
    void doPaintFill();
    void doColorPicker();
    


private:
    Shape shape;
    Filter filter;
    QPen pen;
    QBrush brush;
    QColor color;
    int penWidth;
    Matrix *matrix;
    QPoint lastPoint;
    QPoint currentPoint;
    bool isSecondPoint;
};

#endif