/****************************************************************************
** Meta object code from reading C++ file 'clParameterView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clParameterView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clParameterView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_clParameterView_t {
    QByteArrayData data[18];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_clParameterView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_clParameterView_t qt_meta_stringdata_clParameterView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "clParameterView"
QT_MOC_LITERAL(1, 16, 24), // "slotButtonRefreshPressed"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 21), // "slotButtonReadPressed"
QT_MOC_LITERAL(4, 64, 22), // "slotButtonWritePressed"
QT_MOC_LITERAL(5, 87, 23), // "slotButtonMethodPressed"
QT_MOC_LITERAL(6, 111, 21), // "slotTreeClassItemMenu"
QT_MOC_LITERAL(7, 133, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(8, 150, 4), // "item"
QT_MOC_LITERAL(9, 155, 1), // "i"
QT_MOC_LITERAL(10, 157, 24), // "slotTreeClassItemPressed"
QT_MOC_LITERAL(11, 182, 5), // "index"
QT_MOC_LITERAL(12, 188, 28), // "slotListPropertieItemPressed"
QT_MOC_LITERAL(13, 217, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 234, 14), // "slotNewElement"
QT_MOC_LITERAL(15, 249, 17), // "slotDeleteElement"
QT_MOC_LITERAL(16, 267, 15), // "slotEditElement"
QT_MOC_LITERAL(17, 283, 13) // "slotClassInfo"

    },
    "clParameterView\0slotButtonRefreshPressed\0"
    "\0slotButtonReadPressed\0slotButtonWritePressed\0"
    "slotButtonMethodPressed\0slotTreeClassItemMenu\0"
    "QTreeWidgetItem*\0item\0i\0"
    "slotTreeClassItemPressed\0index\0"
    "slotListPropertieItemPressed\0"
    "QListWidgetItem*\0slotNewElement\0"
    "slotDeleteElement\0slotEditElement\0"
    "slotClassInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clParameterView[] = {

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
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    2,   73,    2, 0x08 /* Private */,
      10,    2,   78,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,
      16,    0,   88,    2, 0x08 /* Private */,
      17,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,   11,
    QMetaType::Void, 0x80000000 | 13,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void clParameterView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<clParameterView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotButtonRefreshPressed(); break;
        case 1: _t->slotButtonReadPressed(); break;
        case 2: _t->slotButtonWritePressed(); break;
        case 3: _t->slotButtonMethodPressed(); break;
        case 4: _t->slotTreeClassItemMenu((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->slotTreeClassItemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slotListPropertieItemPressed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->slotNewElement(); break;
        case 8: _t->slotDeleteElement(); break;
        case 9: _t->slotEditElement(); break;
        case 10: _t->slotClassInfo(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject clParameterView::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_clParameterView.data,
    qt_meta_data_clParameterView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *clParameterView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clParameterView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_clParameterView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int clParameterView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
