/****************************************************************************
** Meta object code from reading C++ file 'PatientRegistration_View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MedicallClient/PatientRegistration_View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PatientRegistration_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PatientRegistration_View_t {
    QByteArrayData data[10];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PatientRegistration_View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PatientRegistration_View_t qt_meta_stringdata_PatientRegistration_View = {
    {
QT_MOC_LITERAL(0, 0, 24), // "PatientRegistration_View"
QT_MOC_LITERAL(1, 25, 16), // "backButton_Event"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 10), // "registered"
QT_MOC_LITERAL(4, 54, 13), // "QVariantHash&"
QT_MOC_LITERAL(5, 68, 4), // "data"
QT_MOC_LITERAL(6, 73, 22), // "registerButton_Clicked"
QT_MOC_LITERAL(7, 96, 17), // "register_Finished"
QT_MOC_LITERAL(8, 114, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 129, 5) // "reply"

    },
    "PatientRegistration_View\0backButton_Event\0"
    "\0registered\0QVariantHash&\0data\0"
    "registerButton_Clicked\0register_Finished\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PatientRegistration_View[] = {

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
       6,    0,   38,    2, 0x08 /* Private */,
       7,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void PatientRegistration_View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PatientRegistration_View *_t = static_cast<PatientRegistration_View *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backButton_Event(); break;
        case 1: _t->registered((*reinterpret_cast< QVariantHash(*)>(_a[1]))); break;
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
            typedef void (PatientRegistration_View::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientRegistration_View::backButton_Event)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PatientRegistration_View::*_t)(QVariantHash & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientRegistration_View::registered)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PatientRegistration_View::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PatientRegistration_View.data,
      qt_meta_data_PatientRegistration_View,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PatientRegistration_View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PatientRegistration_View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PatientRegistration_View.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PatientRegistration_View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PatientRegistration_View::backButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PatientRegistration_View::registered(QVariantHash & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
