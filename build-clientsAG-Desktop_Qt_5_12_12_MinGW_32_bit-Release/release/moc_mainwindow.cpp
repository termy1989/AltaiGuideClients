/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientsAG-v.1.1/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "signalTimerStart"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "signalTimerStop"
QT_MOC_LITERAL(4, 45, 7), // "sqlAuth"
QT_MOC_LITERAL(5, 53, 8), // "username"
QT_MOC_LITERAL(6, 62, 8), // "password"
QT_MOC_LITERAL(7, 71, 10), // "sqlConnect"
QT_MOC_LITERAL(8, 82, 13), // "sqlDisconnect"
QT_MOC_LITERAL(9, 96, 17), // "confirmDisconnect"
QT_MOC_LITERAL(10, 114, 15), // "enableInterface"
QT_MOC_LITERAL(11, 130, 16), // "disableInterface"
QT_MOC_LITERAL(12, 147, 12), // "addSqlRecord"
QT_MOC_LITERAL(13, 160, 15), // "removeSqlRecord"
QT_MOC_LITERAL(14, 176, 15), // "updateSqlRecord"
QT_MOC_LITERAL(15, 192, 15), // "refreshSqlTable"
QT_MOC_LITERAL(16, 208, 7), // "sqlFind"
QT_MOC_LITERAL(17, 216, 3), // "str"
QT_MOC_LITERAL(18, 220, 14), // "checkBirthdays"
QT_MOC_LITERAL(19, 235, 14), // "createTrayIcon"
QT_MOC_LITERAL(20, 250, 12), // "readSettings"
QT_MOC_LITERAL(21, 263, 13), // "iconActivated"
QT_MOC_LITERAL(22, 277, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(23, 311, 6), // "reason"
QT_MOC_LITERAL(24, 318, 14), // "messageClicked"
QT_MOC_LITERAL(25, 333, 10), // "windowHide"
QT_MOC_LITERAL(26, 344, 13), // "windowRestore"
QT_MOC_LITERAL(27, 358, 16) // "applicationClose"

    },
    "MainWindow\0signalTimerStart\0\0"
    "signalTimerStop\0sqlAuth\0username\0"
    "password\0sqlConnect\0sqlDisconnect\0"
    "confirmDisconnect\0enableInterface\0"
    "disableInterface\0addSqlRecord\0"
    "removeSqlRecord\0updateSqlRecord\0"
    "refreshSqlTable\0sqlFind\0str\0checkBirthdays\0"
    "createTrayIcon\0readSettings\0iconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0messageClicked\0windowHide\0"
    "windowRestore\0applicationClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       3,    0,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,  123,    2, 0x08 /* Private */,
       7,    0,  128,    2, 0x08 /* Private */,
       8,    0,  129,    2, 0x08 /* Private */,
       9,    0,  130,    2, 0x08 /* Private */,
      10,    0,  131,    2, 0x08 /* Private */,
      11,    0,  132,    2, 0x08 /* Private */,
      12,    0,  133,    2, 0x08 /* Private */,
      13,    0,  134,    2, 0x08 /* Private */,
      14,    0,  135,    2, 0x08 /* Private */,
      15,    0,  136,    2, 0x08 /* Private */,
      16,    1,  137,    2, 0x08 /* Private */,
      18,    0,  140,    2, 0x08 /* Private */,
      19,    0,  141,    2, 0x08 /* Private */,
      20,    0,  142,    2, 0x08 /* Private */,
      21,    1,  143,    2, 0x08 /* Private */,
      24,    0,  146,    2, 0x08 /* Private */,
      25,    0,  147,    2, 0x08 /* Private */,
      26,    0,  148,    2, 0x08 /* Private */,
      27,    0,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalTimerStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalTimerStop(); break;
        case 2: _t->sqlAuth((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: { bool _r = _t->sqlConnect();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->sqlDisconnect(); break;
        case 5: _t->confirmDisconnect(); break;
        case 6: _t->enableInterface(); break;
        case 7: _t->disableInterface(); break;
        case 8: _t->addSqlRecord(); break;
        case 9: _t->removeSqlRecord(); break;
        case 10: _t->updateSqlRecord(); break;
        case 11: _t->refreshSqlTable(); break;
        case 12: _t->sqlFind((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->checkBirthdays(); break;
        case 14: _t->createTrayIcon(); break;
        case 15: _t->readSettings(); break;
        case 16: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 17: _t->messageClicked(); break;
        case 18: _t->windowHide(); break;
        case 19: _t->windowRestore(); break;
        case 20: _t->applicationClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalTimerStart)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalTimerStop)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalTimerStart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalTimerStop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
