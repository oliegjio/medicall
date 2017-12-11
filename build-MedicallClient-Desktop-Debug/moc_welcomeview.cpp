/****************************************************************************
** Meta object code from reading C++ file 'welcomeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MedicallClient/welcomeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcomeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WelcomeView_t {
    QByteArrayData data[7];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WelcomeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WelcomeView_t qt_meta_stringdata_WelcomeView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WelcomeView"
QT_MOC_LITERAL(1, 12, 24), // "loginPatientButton_Event"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "loginDoctorButton_Event"
QT_MOC_LITERAL(4, 62, 27), // "registerPatientButton_Event"
QT_MOC_LITERAL(5, 90, 26), // "registerDoctorButton_Event"
QT_MOC_LITERAL(6, 117, 16) // "exitButton_Event"

    },
    "WelcomeView\0loginPatientButton_Event\0"
    "\0loginDoctorButton_Event\0"
    "registerPatientButton_Event\0"
    "registerDoctorButton_Event\0exitButton_Event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WelcomeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WelcomeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WelcomeView *_t = static_cast<WelcomeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginPatientButton_Event(); break;
        case 1: _t->loginDoctorButton_Event(); break;
        case 2: _t->registerPatientButton_Event(); break;
        case 3: _t->registerDoctorButton_Event(); break;
        case 4: _t->exitButton_Event(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WelcomeView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::loginPatientButton_Event)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WelcomeView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::loginDoctorButton_Event)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WelcomeView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::registerPatientButton_Event)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WelcomeView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::registerDoctorButton_Event)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (WelcomeView::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WelcomeView::exitButton_Event)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject WelcomeView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WelcomeView.data,
      qt_meta_data_WelcomeView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WelcomeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WelcomeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WelcomeView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WelcomeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WelcomeView::loginPatientButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WelcomeView::loginDoctorButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WelcomeView::registerPatientButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WelcomeView::registerDoctorButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WelcomeView::exitButton_Event()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
