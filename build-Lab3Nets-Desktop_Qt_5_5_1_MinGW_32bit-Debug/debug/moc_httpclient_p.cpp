/****************************************************************************
** Meta object code from reading C++ file 'httpclient_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab3Nets/httpclient_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpclient_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HTTPClientPrivate_t {
    QByteArrayData data[11];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HTTPClientPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HTTPClientPrivate_t qt_meta_stringdata_HTTPClientPrivate = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HTTPClientPrivate"
QT_MOC_LITERAL(1, 18, 4), // "init"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "getInfo"
QT_MOC_LITERAL(4, 32, 4), // "site"
QT_MOC_LITERAL(5, 37, 4), // "path"
QT_MOC_LITERAL(6, 42, 13), // "connectToHost"
QT_MOC_LITERAL(7, 56, 4), // "host"
QT_MOC_LITERAL(8, 61, 8), // "getError"
QT_MOC_LITERAL(9, 70, 11), // "const char*"
QT_MOC_LITERAL(10, 82, 13) // "function_name"

    },
    "HTTPClientPrivate\0init\0\0getInfo\0site\0"
    "path\0connectToHost\0host\0getError\0"
    "const char*\0function_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HTTPClientPrivate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    2,   35,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,    4,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::QByteArray, 0x80000000 | 9,   10,

       0        // eod
};

void HTTPClientPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HTTPClientPrivate *_t = static_cast<HTTPClientPrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->getInfo((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->connectToHost((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: { QByteArray _r = _t->getError((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject HTTPClientPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HTTPClientPrivate.data,
      qt_meta_data_HTTPClientPrivate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HTTPClientPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HTTPClientPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HTTPClientPrivate.stringdata0))
        return static_cast<void*>(const_cast< HTTPClientPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int HTTPClientPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
