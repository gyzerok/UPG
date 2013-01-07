/****************************************************************************
** Meta object code from reading C++ file 'QServerSide.h'
**
** Created: Mon 7. Jan 12:21:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UPG/QServerSide.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QServerSide.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QServerSide[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   12,   12,   12, 0x0a,
      89,   73,   12,   12, 0x0a,
     127,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QServerSide[] = {
    "QServerSide\0\0socket,request\0"
    "requestReceived(void*,QString)\0"
    "onReadyRead()\0socket,response\0"
    "onResponseReady(QList<void*>,QString)\0"
    "onDisconnected()\0"
};

void QServerSide::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QServerSide *_t = static_cast<QServerSide *>(_o);
        switch (_id) {
        case 0: _t->requestReceived((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->onReadyRead(); break;
        case 2: _t->onResponseReady((*reinterpret_cast< QList<void*>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->onDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QServerSide::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QServerSide::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_QServerSide,
      qt_meta_data_QServerSide, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QServerSide::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QServerSide::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QServerSide::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QServerSide))
        return static_cast<void*>(const_cast< QServerSide*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int QServerSide::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QServerSide::requestReceived(void * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
