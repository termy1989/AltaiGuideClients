#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSystemTrayIcon>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSettings>
#include "connectdialog.h"
#include "finddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);                              // конструктор
    ~MainWindow();                                                      // деструктор

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void sqlAuth(QString username, QString password);                   // авторизация
    bool sqlConnect();                                                  // подключение к базе
    void sqlDisconnect();                                               // отключение от базы
    void confirmDisconnect();                                           // подтверждение отключения от базы
    void enableInterface();                                             // активация интерфейса
    void disableInterface();                                            // дезактивация интерфейса
    void addSqlRecord();                                                // добавление записи
    void removeSqlRecord();                                             // удаление записи
    void updateSqlRecord();                                             // редактирование записи
    void refreshSqlTable();                                             // обновление таблицы
    void sqlFind(QString str);                                          // поиск записи в таблице
    void checkBirthdays();                                              // проверка дней рождения
    void createTrayIcon();                                              // инициализация иконки трея
    void readSettings();                                                // чтение настроек из файла
    void iconActivated(QSystemTrayIcon::ActivationReason reason);       // двойной клик - разворачивание окна из трея
    void messageClicked();                                              // клик по сообщению в трее
    void windowHide();                                                  // сворачивание окна в трей
    void windowRestore();                                               // разворачивание окна из трея
    void applicationClose();                                            // завершение работы приложения

signals:
    void signalTimerStart(int);                                         // запуск таймера проверки дней рождения
    void signalTimerStop();                                             // остановка таймера проверки дней рождения

private:
    Ui::MainWindow *ui = nullptr;                                       // окно программы
    QSqlDatabase db;                                                    // база данных
    QSqlTableModel *sqlModel = nullptr;                                 // модель таблицы
    QTimer *timerBirthdays = nullptr;                                   // таймер проверки дней рождения
    QSystemTrayIcon *trayIcon = nullptr;                                // иконка трея
    QMenu *trayIconMenu = nullptr;                                      // контекстное меню трея
    ConnectDialog *connectdialog = nullptr;                             // диалог авторизации
    FindDialog *finddialog = nullptr;                                   // диалог поиска

    QString db_username, db_password,                                   // логин и пароль доступа
            db_driver, db_name,                                         // драйвер базы и имя базы
            db_table, db_host;                                          // имя таблицы и адрес сервера

    int intervalWarning;                                                // интервал получения сообщений
    bool isConnected = false;                                           // флаг соединения с базой
    uint8_t messageType = 0;                                            // тип сообщения из трея
};

#endif // QT_NO_SYSTEMTRAYICON

#endif // MAINWINDOW_H
