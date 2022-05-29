/****************************************************************************
** Meta object code from reading C++ file 'RenderArea.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RenderArea.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderArea.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RenderArea_t {
    QByteArrayData data[23];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderArea_t qt_meta_stringdata_RenderArea = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RenderArea"
QT_MOC_LITERAL(1, 11, 8), // "setShape"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "Shape"
QT_MOC_LITERAL(4, 27, 5), // "shape"
QT_MOC_LITERAL(5, 33, 9), // "setFilter"
QT_MOC_LITERAL(6, 43, 6), // "Filter"
QT_MOC_LITERAL(7, 50, 6), // "filter"
QT_MOC_LITERAL(8, 57, 11), // "setPenWidth"
QT_MOC_LITERAL(9, 69, 3), // "pen"
QT_MOC_LITERAL(10, 73, 8), // "setColor"
QT_MOC_LITERAL(11, 82, 5), // "color"
QT_MOC_LITERAL(12, 88, 8), // "setBrush"
QT_MOC_LITERAL(13, 97, 5), // "brush"
QT_MOC_LITERAL(14, 103, 11), // "rotateRight"
QT_MOC_LITERAL(15, 115, 10), // "rotateLeft"
QT_MOC_LITERAL(16, 126, 14), // "flipHorizontal"
QT_MOC_LITERAL(17, 141, 12), // "flipVertical"
QT_MOC_LITERAL(18, 154, 4), // "save"
QT_MOC_LITERAL(19, 159, 5), // "char*"
QT_MOC_LITERAL(20, 165, 4), // "name"
QT_MOC_LITERAL(21, 170, 4), // "load"
QT_MOC_LITERAL(22, 175, 4) // "path"

    },
    "RenderArea\0setShape\0\0Shape\0shape\0"
    "setFilter\0Filter\0filter\0setPenWidth\0"
    "pen\0setColor\0color\0setBrush\0brush\0"
    "rotateRight\0rotateLeft\0flipHorizontal\0"
    "flipVertical\0save\0char*\0name\0load\0"
    "path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderArea[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       5,    1,   72,    2, 0x0a /* Public */,
       8,    1,   75,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      12,    1,   81,    2, 0x0a /* Public */,
      14,    0,   84,    2, 0x0a /* Public */,
      15,    0,   85,    2, 0x0a /* Public */,
      16,    0,   86,    2, 0x0a /* Public */,
      17,    0,   87,    2, 0x0a /* Public */,
      18,    1,   88,    2, 0x0a /* Public */,
      21,    1,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QBrush,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   22,

       0        // eod
};

void RenderArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setShape((*reinterpret_cast< Shape(*)>(_a[1]))); break;
        case 1: _t->setFilter((*reinterpret_cast< Filter(*)>(_a[1]))); break;
        case 2: _t->setPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->setBrush((*reinterpret_cast< const QBrush(*)>(_a[1]))); break;
        case 5: _t->rotateRight(); break;
        case 6: _t->rotateLeft(); break;
        case 7: _t->flipHorizontal(); break;
        case 8: _t->flipVertical(); break;
        case 9: _t->save((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 10: _t->load((*reinterpret_cast< char*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RenderArea::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_RenderArea.data,
    qt_meta_data_RenderArea,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RenderArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RenderArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
