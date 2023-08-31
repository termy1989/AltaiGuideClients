#include "finddialog.h"
#include "ui_finddialog.h"

// конструктор
FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);

    QStringList parameters = {"Ф.И.О.", "Номер телефона", "Email", "Город", "Дата рождения", "Примечание"};
    ui->parameterBox->addItems(parameters);
    connect(ui->parameterBox, SIGNAL(currentIndexChanged(int)), this, SLOT(parameterChanged(int)));
}

// деструктор
FindDialog::~FindDialog()
{
    delete ui;
}

// открытие диалогового окна
void FindDialog::openFind()
{
    // установка начальных параметров поиска
    ui->lineValue->clear();
    ui->lineValue->setEnabled(true);
    ui->parameterBox->setCurrentIndex(0);
    parameter = "`clients_name`";
    ui->dateEdit->setEnabled(false);

    // открытие формы
    show();
}

// смена параметров поиска
void FindDialog::parameterChanged(int index)
{
    switch(index)
    {
        case 0:
            parameter = "`clients_name`";
            ui->lineValue->setEnabled(true);
            ui->dateEdit->setEnabled(false);
            break;
        case 1:
            parameter = "`clients_tel`";
            ui->lineValue->setEnabled(true);
            ui->dateEdit->setEnabled(false);
            break;
        case 2:
            parameter = "`clients_email`";
            ui->lineValue->setEnabled(true);
            ui->dateEdit->setEnabled(false);
            break;
        case 3:
            parameter = "`clients_city`";
            ui->lineValue->setEnabled(true);
            ui->dateEdit->setEnabled(false);
            break;
        case 4:
            parameter = "`clients_date`";
            ui->lineValue->setEnabled(false);
            ui->dateEdit->setEnabled(true);
            break;
        default:
            parameter = "`clients_tour`";
            ui->lineValue->setEnabled(true);
            ui->dateEdit->setEnabled(false);
            break;
    }
}

// кнопка "Ок"
void FindDialog::on_pushButtonOk_clicked()
{
    if (ui->parameterBox->currentIndex() != 4)
        emit signalFind("WHERE " + parameter + " like '%" +
                ui->lineValue->text() + "%';");
    else
        emit signalFind("WHERE " + parameter + "='" +
                ui->dateEdit->date().toString("yyyy-MM-dd") + "';");
}

// кнопка "Отмена"
void FindDialog::on_pushButtonCancel_clicked()
{
    hide();
}
