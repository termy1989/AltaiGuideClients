/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_connect;
    QAction *action_disconnect;
    QAction *action_quit;
    QAction *action_refresh;
    QAction *action_add;
    QAction *action_del;
    QAction *action_find;
    QAction *action_birthday;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menu_db;
    QMenu *menu_edit;
    QMenu *menu_find;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(794, 469);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_connect = new QAction(MainWindow);
        action_connect->setObjectName(QString::fromUtf8("action_connect"));
        action_connect->setEnabled(true);
        action_disconnect = new QAction(MainWindow);
        action_disconnect->setObjectName(QString::fromUtf8("action_disconnect"));
        action_disconnect->setEnabled(false);
        action_quit = new QAction(MainWindow);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        action_refresh = new QAction(MainWindow);
        action_refresh->setObjectName(QString::fromUtf8("action_refresh"));
        action_refresh->setEnabled(true);
        action_add = new QAction(MainWindow);
        action_add->setObjectName(QString::fromUtf8("action_add"));
        action_del = new QAction(MainWindow);
        action_del->setObjectName(QString::fromUtf8("action_del"));
        action_find = new QAction(MainWindow);
        action_find->setObjectName(QString::fromUtf8("action_find"));
        action_find->setEnabled(true);
        action_birthday = new QAction(MainWindow);
        action_birthday->setObjectName(QString::fromUtf8("action_birthday"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setLayoutDirection(Qt::LeftToRight);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(true);

        verticalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 794, 20));
        menu_db = new QMenu(menubar);
        menu_db->setObjectName(QString::fromUtf8("menu_db"));
        menu_edit = new QMenu(menubar);
        menu_edit->setObjectName(QString::fromUtf8("menu_edit"));
        menu_edit->setEnabled(false);
        menu_find = new QMenu(menubar);
        menu_find->setObjectName(QString::fromUtf8("menu_find"));
        menu_find->setEnabled(false);
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_db->menuAction());
        menubar->addAction(menu_edit->menuAction());
        menubar->addAction(menu_find->menuAction());
        menu_db->addAction(action_connect);
        menu_db->addAction(action_disconnect);
        menu_db->addSeparator();
        menu_db->addAction(action_quit);
        menu_edit->addAction(action_refresh);
        menu_edit->addSeparator();
        menu_edit->addAction(action_add);
        menu_edit->addAction(action_del);
        menu_find->addAction(action_find);
        menu_find->addAction(action_birthday);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\220\320\273\321\202\320\260\320\271-\320\223\320\270\320\264. \320\232\320\273\320\270\320\265\320\275\321\202\321\213 - \320\236\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\276", nullptr));
        action_connect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
#ifndef QT_NO_SHORTCUT
        action_connect->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        action_disconnect->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
#ifndef QT_NO_SHORTCUT
        action_disconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        action_quit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#ifndef QT_NO_SHORTCUT
        action_quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        action_refresh->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
#ifndef QT_NO_SHORTCUT
        action_refresh->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
#ifndef QT_NO_SHORTCUT
        action_add->setShortcut(QApplication::translate("MainWindow", "F6", nullptr));
#endif // QT_NO_SHORTCUT
        action_del->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
#ifndef QT_NO_SHORTCUT
        action_del->setShortcut(QApplication::translate("MainWindow", "F7", nullptr));
#endif // QT_NO_SHORTCUT
        action_find->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        action_find->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        action_birthday->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\264\320\275\320\270 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
#ifndef QT_NO_SHORTCUT
        action_birthday->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_NO_SHORTCUT
        menu_db->setTitle(QApplication::translate("MainWindow", "\320\241\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        menu_edit->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        menu_find->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
