#ifndef InitWindow_hpp
#define InitWindow_hpp

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QCheckBox>
#include <QGridLayout>

#include "Window.hpp"

class InitWindow : public QWidget
{
    Q_OBJECT

public:
    InitWindow();

private slots:
    void okButtonClicked();

private:
    QLabel *instructionLabel;
    QLabel *widthLabel;
    QLabel *heightLabel;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;
    QPushButton *okButton;
};

#endif // InitWindow_hpp