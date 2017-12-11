/****************************************************************************
** Meta object code from reading C++ file 'DoctorRegistration_View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MedicallClient/DoctorRegistration_View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DoctorRegistration_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoctorRegistration_View_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoctorRegistration_View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoctorRegistration_View_t qt_meta_stringdata_DoctorRegistration_View = {
    {
QT_MOC_LITERAL(0, 0, 23), // "DoctorRegistration_View"
QT_MOC_LITERAL(1, 24, 18), // "backButton_Clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 16), // "registered_Event"
QT_MOC_LITERAL(4, 61, 4), // "data"
QT_MOC_LITERAL(5, 66, 22), // "registerButton_Clicked"
QT_MOC_LITERAL(6, 89, 17), // "register_Finished"
QT_MOC_LITERAL(7, 107, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 122, 5) // "reply"

    },
    "DoctorRegistration_View\0backButton_Clicked\0"
    "\0registered_Event\0data\0registerButton_Clicked\0"
    "register_Finished\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoctorRegistration_View[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantHash,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void DoctorRegistration_View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DoctorRegistration_View *_t = static_cast<DoctorRegistration_View *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backButton_Clicked(); break;
        case 1: _t->registered_Event((*reinterpret_cast< QVariantHash(*)>(_a[1]))); break;
        case 2: _t->registerButton_Clicked(); break;
        case 3: _t->register_Finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DoctorRegistration_View::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorRegistration_View::backButton_Clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DoctorRegistration_View::*_t)(QVariantHash );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorRegistration_View::registered_Event)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DoctorRegistration_View::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DoctorRegistration_View.data,
      qt_meta_data_DoctorRegistration_View,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DoctorRegistration_View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoctorRegistration_View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoctorRegistration_View.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DoctorRegistration_View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DoctorRegistration_View::backButton_Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DoctorRegistration_View::registered_Event(QVariantHash _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
