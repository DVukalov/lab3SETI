/****************************************************************************
** Meta object code from reading C++ file 'httpinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab3Nets/httpinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HTTPInterface_t {
    QByteArrayData data[8];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HTTPInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HTTPInterface_t qt_meta_stringdata_HTTPInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "HTTPInterface"
QT_MOC_LITERAL(1, 14, 4), // "load"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "saveHistory"
QT_MOC_LITERAL(4, 32, 13), // "updateHistory"
QT_MOC_LITERAL(5, 46, 12), // "clearHistory"
QT_MOC_LITERAL(6, 59, 9), // "showError"
QT_MOC_LITERAL(7, 69, 3) // "err"

    },
    "HTTPInterface\0load\0\0saveHistory\0"
    "updateHistory\0clearHistory\0showError\0"
    "err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HTTPInterface[] = {

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
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void HTTPInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HTTPInterface *_t = static_cast<HTTPInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load(); break;
        case 1: _t->saveHistory(); break;
        case 2: _t->updateHistory(); break;
        case 3: _t->clearHistory(); break;
        case 4: _t->showError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject HTTPInterface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HTTPInterface.data,
      qt_meta_data_HTTPInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HTTPInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HTTPInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HTTPInterface.stringdata0))
        return static_cast<void*>(const_cast< HTTPInterface*>(this));
    return QWidget::qt_metacast(_clname);
}

int HTTPInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
