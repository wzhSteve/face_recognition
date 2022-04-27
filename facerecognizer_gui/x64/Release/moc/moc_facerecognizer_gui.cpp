/****************************************************************************
** Meta object code from reading C++ file 'facerecognizer_gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../facerecognizer_gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'facerecognizer_gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_facerecognizer_gui_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_facerecognizer_gui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_facerecognizer_gui_t qt_meta_stringdata_facerecognizer_gui = {
    {
QT_MOC_LITERAL(0, 0, 18), // "facerecognizer_gui"
QT_MOC_LITERAL(1, 19, 18), // "ShowButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "TakePhoto_clicked"
QT_MOC_LITERAL(4, 57, 13), // "Train_clicked"
QT_MOC_LITERAL(5, 71, 20), // "CloseCarmera_clicked"
QT_MOC_LITERAL(6, 92, 10), // "closeEvent"
QT_MOC_LITERAL(7, 103, 12), // "QCloseEvent*"
QT_MOC_LITERAL(8, 116, 1) // "e"

    },
    "facerecognizer_gui\0ShowButton_clicked\0"
    "\0TakePhoto_clicked\0Train_clicked\0"
    "CloseCarmera_clicked\0closeEvent\0"
    "QCloseEvent*\0e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_facerecognizer_gui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void facerecognizer_gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        facerecognizer_gui *_t = static_cast<facerecognizer_gui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowButton_clicked(); break;
        case 1: _t->TakePhoto_clicked(); break;
        case 2: _t->Train_clicked(); break;
        case 3: _t->CloseCarmera_clicked(); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject facerecognizer_gui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_facerecognizer_gui.data,
      qt_meta_data_facerecognizer_gui,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *facerecognizer_gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *facerecognizer_gui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_facerecognizer_gui.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int facerecognizer_gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
