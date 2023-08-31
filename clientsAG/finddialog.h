#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    ~FindDialog();

public slots:
    void openFind();

signals:
    void signalFind(QString);

private slots:
    void parameterChanged(int index);

    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::FindDialog *ui = nullptr;
    QString parameter = "";
};

#endif // FINDDIALOG_H
