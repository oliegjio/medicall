/****************************************************************************
** Meta object code from reading C++ file 'loginpatientview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MedicallClient/loginpatientview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginpatientview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginPatientView_t {
    QByteArrayData data[12];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginPatientView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginPatientView_t qt_meta_stringdata_LoginPatientView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "LoginPatientView"
QT_MOC_LITERAL(1, 17, 17), // "switchToLoginView"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "backButton_Event"
QT_MOC_LITERAL(4, 53, 8), // "loggedIn"
QT_MOC_LITERAL(5, 62, 13), // "QVariantHash&"
QT_MOC_LITERAL(6, 76, 4), // "data"
QT_MOC_LITERAL(7, 81, 19), // "loginButton_Clicked"
QT_MOC_LITERAL(8, 101, 18), // "backButton_Clicked"
QT_MOC_LITERAL(9, 120, 14), // "login_Finished"
QT_MOC_LITERAL(10, 135, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 150, 5) // "reply"

    },
    "LoginPatientView\0switchToLoginView\0\0"
    "backButton_Event\0loggedIn\0QVariantHash&\0"
    "data\0loginButton_Clicked\0backButton_Clicked\0"
    "login_Finished\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginPatientView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void LoginPatientView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginPatientView *_t = static_cast<LoginPatientView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchToLoginView(); break;
        case 1: _t->backButton_Event(); break;
        case 2: _t->loggedIn((*reinterpret_cast< QVariantHash(*)>(_a[1]))); break;
        case 3: _t->loginButton_Clicked(); break;
        case 4: _t->backButton_Clicked(); break;
        case 5: _t->login_Finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
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
            typedef void (LoginPatientView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginPatientView::switchToLoginView)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LoginPatientView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginPatientView::backButton_Event)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LoginPatientView::*_t)(QVariantHash & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginPatientView::loggedIn)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LoginPatientView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginPatientView.data,
      qt_meta_data_LoginPatientView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LoginPatientView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginPatientView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginPatientView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginPatientView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LoginPatientView::switchToLoginView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LoginPatientView::backButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LoginPatientView::loggedIn(QVariantHash & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
