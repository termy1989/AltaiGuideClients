/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QLineEdit *lineEditUser;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelUser;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QString::fromUtf8("ConnectDialog"));
        ConnectDialog->resize(282, 169);
        ConnectDialog->setMinimumSize(QSize(282, 169));
        ConnectDialog->setMaximumSize(QSize(282, 169));
        lineEditUser = new QLineEdit(ConnectDialog);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));
        lineEditUser->setGeometry(QRect(75, 27, 171, 22));
        labelPassword = new QLabel(ConnectDialog);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        labelPassword->setGeometry(QRect(28, 68, 41, 16));
        lineEditPassword = new QLineEdit(ConnectDialog);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(75, 68, 171, 22));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        labelUser = new QLabel(ConnectDialog);
        labelUser->setObjectName(QString::fromUtf8("labelUser"));
        labelUser->setGeometry(QRect(35, 28, 34, 16));
        pushButtonOk = new QPushButton(ConnectDialog);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(75, 120, 80, 21));
        pushButtonCancel = new QPushButton(ConnectDialog);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(166, 120, 80, 21));

        retranslateUi(ConnectDialog);

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203", nullptr));
        labelPassword->setText(QApplication::translate("ConnectDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        labelUser->setText(QApplication::translate("ConnectDialog", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        pushButtonOk->setText(QApplication::translate("ConnectDialog", "\320\236\320\272", nullptr));
        pushButtonCancel->setText(QApplication::translate("ConnectDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
