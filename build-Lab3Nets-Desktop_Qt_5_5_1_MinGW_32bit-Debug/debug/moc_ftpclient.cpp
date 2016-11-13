/****************************************************************************
** Meta object code from reading C++ file 'ftpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Lab3Nets/ftpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FtpWindow_t {
    QByteArrayData data[22];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FtpWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FtpWindow_t qt_meta_stringdata_FtpWindow = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FtpWindow"
QT_MOC_LITERAL(1, 10, 19), // "connectOrDisconnect"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "downloadFile"
QT_MOC_LITERAL(4, 44, 14), // "cancelDownload"
QT_MOC_LITERAL(5, 59, 12), // "connectToFtp"
QT_MOC_LITERAL(6, 72, 18), // "ftpCommandFinished"
QT_MOC_LITERAL(7, 91, 9), // "commandId"
QT_MOC_LITERAL(8, 101, 5), // "error"
QT_MOC_LITERAL(9, 107, 9), // "addToList"
QT_MOC_LITERAL(10, 117, 8), // "QUrlInfo"
QT_MOC_LITERAL(11, 126, 7), // "urlInfo"
QT_MOC_LITERAL(12, 134, 11), // "processItem"
QT_MOC_LITERAL(13, 146, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(14, 163, 4), // "item"
QT_MOC_LITERAL(15, 168, 6), // "column"
QT_MOC_LITERAL(16, 175, 10), // "cdToParent"
QT_MOC_LITERAL(17, 186, 26), // "updateDataTransferProgress"
QT_MOC_LITERAL(18, 213, 9), // "readBytes"
QT_MOC_LITERAL(19, 223, 10), // "totalBytes"
QT_MOC_LITERAL(20, 234, 20), // "enableDownloadButton"
QT_MOC_LITERAL(21, 255, 19) // "enableConnectButton"

    },
    "FtpWindow\0connectOrDisconnect\0\0"
    "downloadFile\0cancelDownload\0connectToFtp\0"
    "ftpCommandFinished\0commandId\0error\0"
    "addToList\0QUrlInfo\0urlInfo\0processItem\0"
    "QTreeWidgetItem*\0item\0column\0cdToParent\0"
    "updateDataTransferProgress\0readBytes\0"
    "totalBytes\0enableDownloadButton\0"
    "enableConnectButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FtpWindow[] = {

 // content:
       7,       // revision
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
       9,    1,   78,    2, 0x08 /* Private */,
      12,    2,   81,    2, 0x08 /* Private */,
      16,    0,   86,    2, 0x08 /* Private */,
      17,    2,   87,    2, 0x08 /* Private */,
      20,    0,   92,    2, 0x08 /* Private */,
      21,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   18,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FtpWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FtpWindow *_t = static_cast<FtpWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectOrDisconnect(); break;
        case 1: _t->downloadFile(); break;
        case 2: _t->cancelDownload(); break;
        case 3: _t->connectToFtp(); break;
        case 4: _t->ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->addToList((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 6: _t->processItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->cdToParent(); break;
        case 8: _t->updateDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 9: _t->enableDownloadButton(); break;
        case 10: _t->enableConnectButton(); break;
        default: ;
        }
    }
}

const QMetaObject FtpWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FtpWindow.data,
      qt_meta_data_FtpWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FtpWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FtpWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FtpWindow.stringdata0))
        return static_cast<void*>(const_cast< FtpWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int FtpWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
