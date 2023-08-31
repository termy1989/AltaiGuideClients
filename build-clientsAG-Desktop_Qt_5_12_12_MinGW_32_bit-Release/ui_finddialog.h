/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QLabel *labelValue;
    QLineEdit *lineValue;
    QComboBox *parameterBox;
    QDateEdit *dateEdit;
    QLabel *labelParameter;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->resize(335, 145);
        FindDialog->setMinimumSize(QSize(335, 145));
        FindDialog->setMaximumSize(QSize(335, 145));
        labelValue = new QLabel(FindDialog);
        labelValue->setObjectName(QString::fromUtf8("labelValue"));
        labelValue->setGeometry(QRect(17, 23, 51, 16));
        lineValue = new QLineEdit(FindDialog);
        lineValue->setObjectName(QString::fromUtf8("lineValue"));
        lineValue->setGeometry(QRect(75, 22, 241, 21));
        parameterBox = new QComboBox(FindDialog);
        parameterBox->setObjectName(QString::fromUtf8("parameterBox"));
        parameterBox->setGeometry(QRect(74, 62, 151, 22));
        dateEdit = new QDateEdit(FindDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(235, 62, 81, 22));
        labelParameter = new QLabel(FindDialog);
        labelParameter->setObjectName(QString::fromUtf8("labelParameter"));
        labelParameter->setGeometry(QRect(16, 62, 51, 20));
        pushButtonOk = new QPushButton(FindDialog);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(73, 102, 111, 21));
        pushButtonCancel = new QPushButton(FindDialog);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(206, 102, 111, 21));

        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QApplication::translate("FindDialog", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        labelValue->setText(QApplication::translate("FindDialog", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", nullptr));
        labelParameter->setText(QApplication::translate("FindDialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200:", nullptr));
        pushButtonOk->setText(QApplication::translate("FindDialog", "\320\236\320\272", nullptr));
        pushButtonCancel->setText(QApplication::translate("FindDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
