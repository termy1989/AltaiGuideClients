#include "connectdialog.h"
#include "ui_connectdialog.h"

// конструктор
ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
}

// деструктор
ConnectDialog::~ConnectDialog()
{
    delete ui;
}

// открытие диалога
void ConnectDialog::openDialog()
{
    ui->lineEditUser->clear();
    ui->lineEditPassword->clear();
    show();
}

// кнопка "Ок"
void ConnectDialog::on_pushButtonOk_clicked()
{
    emit signalLogin(ui->lineEditUser->text(),
                     ui->lineEditPassword->text());
}

// кнопка "Отмена"
void ConnectDialog::on_pushButtonCancel_clicked()
{
    hide();
}
