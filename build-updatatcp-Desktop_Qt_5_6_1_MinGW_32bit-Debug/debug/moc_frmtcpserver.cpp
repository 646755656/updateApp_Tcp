/****************************************************************************
** Meta object code from reading C++ file 'frmtcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../updatatcp/frmtcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmtcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_frmTcpServer_t {
    QByteArrayData data[14];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmTcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmTcpServer_t qt_meta_stringdata_frmTcpServer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "frmTcpServer"
QT_MOC_LITERAL(1, 13, 15), // "clientConnected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "ip"
QT_MOC_LITERAL(4, 33, 4), // "port"
QT_MOC_LITERAL(5, 38, 18), // "clientDisconnected"
QT_MOC_LITERAL(6, 57, 8), // "sendData"
QT_MOC_LITERAL(7, 66, 4), // "data"
QT_MOC_LITERAL(8, 71, 11), // "receiveData"
QT_MOC_LITERAL(9, 83, 20), // "on_btnListen_clicked"
QT_MOC_LITERAL(10, 104, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(11, 124, 21), // "on_btnBrowser_clicked"
QT_MOC_LITERAL(12, 146, 21), // "on_btnConnect_clicked"
QT_MOC_LITERAL(13, 168, 21) // "on_btnUpgrate_clicked"

    },
    "frmTcpServer\0clientConnected\0\0ip\0port\0"
    "clientDisconnected\0sendData\0data\0"
    "receiveData\0on_btnListen_clicked\0"
    "on_btnClear_clicked\0on_btnBrowser_clicked\0"
    "on_btnConnect_clicked\0on_btnUpgrate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmTcpServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x08 /* Private */,
       5,    2,   64,    2, 0x08 /* Private */,
       6,    3,   69,    2, 0x08 /* Private */,
       8,    3,   76,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmTcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmTcpServer *_t = static_cast<frmTcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientConnected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->clientDisconnected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->receiveData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->on_btnListen_clicked(); break;
        case 5: _t->on_btnClear_clicked(); break;
        case 6: _t->on_btnBrowser_clicked(); break;
        case 7: _t->on_btnConnect_clicked(); break;
        case 8: _t->on_btnUpgrate_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject frmTcpServer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmTcpServer.data,
      qt_meta_data_frmTcpServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *frmTcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmTcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_frmTcpServer.stringdata0))
        return static_cast<void*>(const_cast< frmTcpServer*>(this));
    return QWidget::qt_metacast(_clname);
}

int frmTcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
