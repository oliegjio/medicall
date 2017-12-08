/****************************************************************************
** Meta object code from reading C++ file 'patientregistrationview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MedicallClient/patientregistrationview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patientregistrationview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PatientRegistrationView_t {
    QByteArrayData data[11];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PatientRegistrationView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PatientRegistrationView_t qt_meta_stringdata_PatientRegistrationView = {
    {
QT_MOC_LITERAL(0, 0, 23), // "PatientRegistrationView"
QT_MOC_LITERAL(1, 24, 16), // "backButton_Event"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 10), // "registered"
QT_MOC_LITERAL(4, 53, 13), // "QVariantHash&"
QT_MOC_LITERAL(5, 67, 4), // "data"
QT_MOC_LITERAL(6, 72, 18), // "backButton_Clicked"
QT_MOC_LITERAL(7, 91, 22), // "registerButton_Clicked"
QT_MOC_LITERAL(8, 114, 17), // "register_Finished"
QT_MOC_LITERAL(9, 132, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 147, 5) // "reply"

    },
    "PatientRegistrationView\0backButton_Event\0"
    "\0registered\0QVariantHash&\0data\0"
    "backButton_Clicked\0registerButton_Clicked\0"
    "register_Finished\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PatientRegistrationView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void PatientRegistrationView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PatientRegistrationView *_t = static_cast<PatientRegistrationView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backButton_Event(); break;
        case 1: _t->registered((*reinterpret_cast< QVariantHash(*)>(_a[1]))); break;
        case 2: _t->backButton_Clicked(); break;
        case 3: _t->registerButton_Clicked(); break;
        case 4: _t->register_Finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            typedef void (PatientRegistrationView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientRegistrationView::backButton_Event)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PatientRegistrationView::*_t)(QVariantHash & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PatientRegistrationView::registered)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject PatientRegistrationView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PatientRegistrationView.data,
      qt_meta_data_PatientRegistrationView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PatientRegistrationView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PatientRegistrationView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PatientRegistrationView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PatientRegistrationView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PatientRegistrationView::backButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PatientRegistrationView::registered(QVariantHash & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
