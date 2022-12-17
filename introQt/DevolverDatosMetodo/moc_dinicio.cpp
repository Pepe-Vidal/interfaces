/****************************************************************************
** Meta object code from reading C++ file 'dinicio.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "dinicio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dinicio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DInicio_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DInicio_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DInicio_t qt_meta_stringdata_DInicio = {
    {
QT_MOC_LITERAL(0, 0, 7), // "DInicio"
QT_MOC_LITERAL(1, 8, 16), // "slotAbrirDialogo"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "slotActualizarDialogo"
QT_MOC_LITERAL(4, 48, 18), // "slotListoTransDato"
QT_MOC_LITERAL(5, 67, 14), // "slotListoTrans"
QT_MOC_LITERAL(6, 82, 12) // "slotRecTrans"

    },
    "DInicio\0slotAbrirDialogo\0\0"
    "slotActualizarDialogo\0slotListoTransDato\0"
    "slotListoTrans\0slotRecTrans"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DInicio[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    2,   41,    2, 0x0a /* Public */,
       5,    0,   46,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DInicio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DInicio *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotAbrirDialogo(); break;
        case 1: _t->slotActualizarDialogo(); break;
        case 2: _t->slotListoTransDato((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slotListoTrans(); break;
        case 4: _t->slotRecTrans(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DInicio::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DInicio.data,
    qt_meta_data_DInicio,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DInicio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DInicio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DInicio.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DInicio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
