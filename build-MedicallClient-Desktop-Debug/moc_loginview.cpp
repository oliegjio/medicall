/****************************************************************************
** Meta object code from reading C++ file 'loginview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MedicallClient/loginview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginView_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginView_t qt_meta_stringdata_LoginView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LoginView"
QT_MOC_LITERAL(1, 10, 17), // "switchToLoginView"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "switchToWelcomeView"
QT_MOC_LITERAL(4, 49, 8), // "loggedIn"
QT_MOC_LITERAL(5, 58, 5), // "token"
QT_MOC_LITERAL(6, 64, 12), // "loginClicked"
QT_MOC_LITERAL(7, 77, 11), // "backClicked"
QT_MOC_LITERAL(8, 89, 20), // "loginRequestFinished"
QT_MOC_LITERAL(9, 110, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 125, 5) // "reply"

    },
    "LoginView\0switchToLoginView\0\0"
    "switchToWelcomeView\0loggedIn\0token\0"
    "loginClicked\0backClicked\0loginRequestFinished\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginView[] = {

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
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void LoginView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginView *_t = static_cast<LoginView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchToLoginView(); break;
        case 1: _t->switchToWelcomeView(); break;
        case 2: _t->loggedIn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->loginClicked(); break;
        case 4: _t->backClicked(); break;
        case 5: _t->loginRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
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
            typedef void (LoginView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginView::switchToLoginView)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LoginView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginView::switchToWelcomeView)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LoginView::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginView::loggedIn)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LoginView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginView.data,
      qt_meta_data_LoginView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LoginView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void LoginView::switchToLoginView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LoginView::switchToWelcomeView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LoginView::loggedIn(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
