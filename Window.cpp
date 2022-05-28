#include "Window.hpp"

Window::Window(int width, int height)
{
        renderArea = new RenderArea(width, height, this);

        toolComboBox = new QComboBox;
        toolComboBox->addItem(tr("Pencil"), RenderArea::Pencil);
        toolComboBox->addItem(tr("Pen"), 
        RenderArea::Pen);
        toolComboBox->addItem(tr("Eraser"), RenderArea::Eraser);
        toolComboBox->addItem(tr("Square"), RenderArea::Square);
        toolComboBox->addItem(tr("Rectangle"), RenderArea::Rectangle);
        toolComboBox->addItem(tr("Triangle"), RenderArea::Triangle);
        toolComboBox->addItem(tr("Pentagon"), RenderArea::Pentagon);
        toolComboBox->addItem(tr("Hexagon"), RenderArea::Hexagon);
        toolComboBox->addItem(tr("Circle"), RenderArea::Circle);
        toolComboBox->addItem(tr("Paint Fill"), RenderArea::PaintFill);
        toolComboBox->addItem(tr("Color Picker"), RenderArea::ColorPicker);

        filtersComboBox = new QComboBox;
        filtersComboBox->addItem(tr("None"), RenderArea::None);
        filtersComboBox->addItem(tr("Black & White"), RenderArea::BlackAndWhite);
        filtersComboBox->addItem(tr("Sepia"), RenderArea::Sepia);
        filtersComboBox->addItem(tr("Negative"), RenderArea::Negative);
        filtersComboBox->addItem(tr("Random"), RenderArea::Random);

        toolLabel = new QLabel(tr("Tool:"));
        toolLabel->setBuddy(toolComboBox);

        filtersLabel = new QLabel(tr("Filter:"));
        filtersLabel->setBuddy(filtersComboBox);

        penWidthSpinBox = new QSpinBox;
        penWidthSpinBox->setRange(0, 5);
        penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

        penWidthLabel = new QLabel(tr("Line Width:"));
        penWidthLabel->setBuddy(penWidthSpinBox);

        colorSelectorButton = new QPushButton(tr(""));
        colorSelectorButton->setFixedSize(30, 30);
        colorSelectorButton->setStyleSheet("background-color: black");
        
        colorSelectorLabel = new QLabel(tr("Color:"));
        colorSelectorLabel->setBuddy(colorSelectorButton);

        rotateRightButton = new QPushButton(tr("Right"));
        rotateLeftButton = new QPushButton(tr("Left"));
        flipHorizontalButton = new QPushButton(tr("Horizontal"));
        flipVerticalButton = new QPushButton(tr("Vertical"));

        rotateRightLabel = new QLabel(tr("Rotate:"));
        rotateLeftLabel = new QLabel(tr("Rotate:"));
        flipHorizontalLabel = new QLabel(tr("Flip:"));
        flipVerticalLabel = new QLabel(tr("Flip:"));

        saveButton = new QPushButton(tr("Save"));

        saveLineEdit = new QLineEdit;

        connect(toolComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &Window::shapeChanged);
        connect(penWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                this, &Window::penChanged);
        connect(filtersComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &Window::filterChanged);
        connect(colorSelectorButton, &QPushButton::clicked, 
                this, &Window::colorChanged);
        connect(rotateRightButton, &QPushButton::clicked, 
                renderArea, &RenderArea::rotateRight);
        connect(rotateLeftButton, &QPushButton::clicked,
                renderArea, &RenderArea::rotateLeft);
        connect(flipHorizontalButton, &QPushButton::clicked,
                renderArea, &RenderArea::flipHorizontal);
        connect(flipVerticalButton, &QPushButton::clicked,
                renderArea, &RenderArea::flipVertical);
        connect(saveButton, &QPushButton::clicked,
                this, &Window::save);

        

        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->setColumnStretch(0, 3);
        mainLayout->setColumnStretch(2, 1);
        mainLayout->addWidget(renderArea, 0, 0, 8, 1);
        mainLayout->addWidget(toolLabel, 0, 1, Qt::AlignRight);
        mainLayout->addWidget(toolComboBox, 0, 2);
        mainLayout->addWidget(penWidthLabel, 1, 1, Qt::AlignRight);
        mainLayout->addWidget(penWidthSpinBox, 1, 2);
        mainLayout->addWidget(filtersLabel, 2, 1, Qt::AlignRight);
        mainLayout->addWidget(filtersComboBox, 2, 2);
        mainLayout->addWidget(colorSelectorLabel, 3, 1, Qt::AlignRight);
        mainLayout->addWidget(colorSelectorButton, 3, 2);
        mainLayout->addWidget(rotateRightLabel, 4, 1, Qt::AlignRight);
        mainLayout->addWidget(rotateRightButton, 4, 2);
        mainLayout->addWidget(rotateLeftLabel, 5, 1, Qt::AlignRight);
        mainLayout->addWidget(rotateLeftButton, 5, 2);
        mainLayout->addWidget(flipHorizontalLabel, 6, 1, Qt::AlignRight);
        mainLayout->addWidget(flipHorizontalButton, 6, 2);
        mainLayout->addWidget(flipVerticalLabel, 7, 1, Qt::AlignRight);
        mainLayout->addWidget(flipVerticalButton, 7, 2);
        mainLayout->addWidget(saveLineEdit, 8, 1, Qt::AlignRight);
        mainLayout->addWidget(saveButton, 8, 2);
        setLayout(mainLayout);

        shapeChanged();
        penChanged();

        setWindowTitle(tr("Paint++"));
}

const int IdRole = Qt::UserRole;

void Window::shapeChanged()
{
        RenderArea::Shape shape = RenderArea::Shape(toolComboBox->itemData(
                                                                     toolComboBox->currentIndex(), IdRole)
                                                        .toInt());
        renderArea->setShape(shape);
}

void Window::penChanged()
{
        renderArea->setPenWidth(penWidthSpinBox->value());
}

void Window::colorChanged()
{
        QColor color = QColorDialog::getColor(Qt::black, this);
        if (color.isValid()) {
                renderArea->setColor(color);
                colorSelectorButton->setStyleSheet(
                                                   QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue()));
        }
}

void Window::filterChanged()
{
        RenderArea::Filter filter = RenderArea::Filter(filtersComboBox->itemData(
                                                                     filtersComboBox->currentIndex(), IdRole)
                                                        .toInt());
        renderArea->setFilter(filter);
}

void Window::save()
{
        renderArea->save((saveLineEdit->text()+".bmp").toLocal8Bit().data());
}