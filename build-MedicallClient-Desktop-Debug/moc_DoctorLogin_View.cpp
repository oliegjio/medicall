/****************************************************************************
** Meta object code from reading C++ file 'DoctorLogin_View.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MedicallClient/DoctorLogin_View.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DoctorLogin_View.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoctorLogin_VIew_t {
    QByteArrayData data[10];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoctorLogin_VIew_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoctorLogin_VIew_t qt_meta_stringdata_DoctorLogin_VIew = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DoctorLogin_VIew"
QT_MOC_LITERAL(1, 17, 18), // "backButton_Clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "loggedIn_Event"
QT_MOC_LITERAL(4, 52, 13), // "QVariantHash&"
QT_MOC_LITERAL(5, 66, 4), // "data"
QT_MOC_LITERAL(6, 71, 14), // "login_Finished"
QT_MOC_LITERAL(7, 86, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 101, 5), // "reply"
QT_MOC_LITERAL(9, 107, 19) // "loginButton_Clicked"

    },
    "DoctorLogin_VIew\0backButton_Clicked\0"
    "\0loggedIn_Event\0QVariantHash&\0data\0"
    "login_Finished\0QNetworkReply*\0reply\0"
    "loginButton_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoctorLogin_VIew[] = {

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
       6,    1,   38,    2, 0x08 /* Private */,
       9,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void DoctorLogin_VIew::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DoctorLogin_VIew *_t = static_cast<DoctorLogin_VIew *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backButton_Clicked(); break;
        case 1: _t->loggedIn_Event((*reinterpret_cast< QVariantHash(*)>(_a[1]))); break;
        case 2: _t->login_Finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->loginButton_Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            typedef void (DoctorLogin_VIew::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorLogin_VIew::backButton_Clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DoctorLogin_VIew::*_t)(QVariantHash & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoctorLogin_VIew::loggedIn_Event)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DoctorLogin_VIew::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DoctorLogin_VIew.data,
      qt_meta_data_DoctorLogin_VIew,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DoctorLogin_VIew::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoctorLogin_VIew::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoctorLogin_VIew.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DoctorLogin_VIew::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DoctorLogin_VIew::backButton_Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DoctorLogin_VIew::loggedIn_Event(QVariantHash & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
