#ifndef Window_h
#define Window_h

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QColorDialog>
#include <QSpinBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

#include "RenderArea.hpp"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(int width, int height);

private slots:
    void shapeChanged();
    void penChanged();
    void colorChanged();
    void filterChanged();
    void save();
    void load();

protected:
    void updateColor();

private:
    RenderArea *renderArea;
    QLabel *toolLabel;
    QLabel *filtersLabel;
    QLabel *penWidthLabel;
    QLabel *colorSelectorLabel;
    QLabel *rotateRightLabel;
    QLabel *rotateLeftLabel;
    QLabel *flipHorizontalLabel;
    QLabel *flipVerticalLabel;
    QLineEdit *saveLineEdit;
    QLineEdit *loadLineEdit;

    QComboBox *toolComboBox;
    QComboBox *filtersComboBox;
    QSpinBox *penWidthSpinBox;
    QPushButton *colorSelectorButton;
    QPushButton *rotateRightButton;
    QPushButton *rotateLeftButton;
    QPushButton *flipHorizontalButton;
    QPushButton *flipVerticalButton;
    QPushButton *saveButton;
    QPushButton *loadButton;

};

#endif