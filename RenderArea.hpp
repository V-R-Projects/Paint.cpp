#ifndef RenderArea_hpp
#define RenderArea_hpp

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
};

#endif