/****************************************************************************
** Meta object code from reading C++ file 'httpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab3Nets/httpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HTTPClient_t {
    QByteArrayData data[13];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HTTPClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HTTPClient_t qt_meta_stringdata_HTTPClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HTTPClient"
QT_MOC_LITERAL(1, 11, 7), // "enabled"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "enb"
QT_MOC_LITERAL(4, 24, 5), // "error"
QT_MOC_LITERAL(5, 30, 3), // "err"
QT_MOC_LITERAL(6, 34, 7), // "message"
QT_MOC_LITERAL(7, 42, 3), // "txt"
QT_MOC_LITERAL(8, 46, 4), // "data"
QT_MOC_LITERAL(9, 51, 7), // "isValid"
QT_MOC_LITERAL(10, 59, 9), // "interrupt"
QT_MOC_LITERAL(11, 69, 7), // "getData"
QT_MOC_LITERAL(12, 77, 4) // "link"

    },
    "HTTPClient\0enabled\0\0enb\0error\0err\0"
    "message\0txt\0data\0isValid\0interrupt\0"
    "getData\0link"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HTTPClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       8,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   61,    2, 0x0a /* Public */,
      10,    0,   62,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QByteArray,    8,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   12,

       0        // eod
};

void HTTPClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HTTPClient *_t = static_cast<HTTPClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->data((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: { bool _r = _t->isValid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->interrupt(); break;
        case 6: _t->getData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HTTPClient::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HTTPClient::enabled)) {
                *result = 0;
            }
        }
        {
            typedef void (HTTPClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HTTPClient::error)) {
                *result = 1;
            }
        }
        {
            typedef void (HTTPClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HTTPClient::message)) {
                *result = 2;
            }
        }
        {
            typedef void (HTTPClient::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HTTPClient::data)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject HTTPClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HTTPClient.data,
      qt_meta_data_HTTPClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HTTPClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HTTPClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HTTPClient.stringdata0))
        return static_cast<void*>(const_cast< HTTPClient*>(this));
    return QObject::qt_metacast(_clname);
}

int HTTPClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void HTTPClient::enabled(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HTTPClient::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HTTPClient::message(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HTTPClient::data(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
