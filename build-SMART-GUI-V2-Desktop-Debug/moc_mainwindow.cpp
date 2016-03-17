/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SMART-GUI-V2/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     116,  111,   11,   11, 0x08,
     151,  111,   11,   11, 0x08,
     186,  111,   11,   11, 0x08,
     221,  111,   11,   11, 0x08,
     256,   11,   11,   11, 0x08,
     280,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionSelect_algorithms_triggered()\0"
    "on_actionAbout_SMART_GUI_triggered()\0"
    "on_checkBox_released()\0arg1\0"
    "on_lineEdit_8_textChanged(QString)\0"
    "on_lineEdit_9_textChanged(QString)\0"
    "on_lineEdit_6_textChanged(QString)\0"
    "on_lineEdit_7_textChanged(QString)\0"
    "on_pushButton_pressed()\0"
    "on_pushButton_released()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionSelect_algorithms_triggered(); break;
        case 1: _t->on_actionAbout_SMART_GUI_triggered(); break;
        case 2: _t->on_checkBox_released(); break;
        case 3: _t->on_lineEdit_8_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_9_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_6_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_7_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_pressed(); break;
        case 8: _t->on_pushButton_released(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
