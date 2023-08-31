// http://www.forum.crossplatform.ru/lofiversion/index.php/t3706.html

#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifndef QT_NO_SYSTEMTRAYICON

// конструктор
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // чтение настроек из файла
    readSettings();

    // инициализация трея
    createTrayIcon();

    // инициализация драйвера базы данных
    db = QSqlDatabase::addDatabase(db_driver);

    // отключение кнопки сворачивания окна
    this->setWindowFlags(Qt::Dialog |
                         Qt::WindowMaximizeButtonHint |
                         Qt::WindowTitleHint |
                         Qt::WindowCloseButtonHint |
                         Qt::WindowSystemMenuHint);

    // вызов диалога авторизации
    connectdialog = new ConnectDialog(this);
    connectdialog->show();

    // инициализация диалога поиска
    finddialog = new FindDialog(this);

    // инициализация компонентов управления
    connect(ui->action_connect, &QAction::triggered, connectdialog, &ConnectDialog::openDialog);
    connect(connectdialog, &ConnectDialog::signalLogin, this, &MainWindow::sqlAuth);
    connect(ui->action_disconnect, &QAction::triggered, this, &MainWindow::confirmDisconnect);
    connect(ui->action_quit, &QAction::triggered, this, &MainWindow::applicationClose);

    connect(ui->action_refresh, &QAction::triggered, this, &MainWindow::refreshSqlTable);
    connect(ui->action_add, &QAction::triggered, this, &MainWindow::addSqlRecord);
    connect(ui->action_del, &QAction::triggered, this, &MainWindow::removeSqlRecord);

    connect(ui->action_find, &QAction::triggered, finddialog, &FindDialog::openFind);
    connect(finddialog, &FindDialog::signalFind, this, &MainWindow::sqlFind);
    connect(ui->action_birthday, &QAction::triggered, this, &MainWindow::checkBirthdays);

    // инициализация таймера проверки дней рождения
    timerBirthdays = new QTimer(this);
    connect(this, SIGNAL(signalTimerStart(int)), timerBirthdays, SLOT(start(int)));
    connect(this, SIGNAL(signalTimerStop()), timerBirthdays, SLOT(stop()));
    connect(timerBirthdays, SIGNAL(timeout()), this, SLOT(checkBirthdays()));
}

// деструктор
MainWindow::~MainWindow()
{
    delete ui;
    delete connectdialog;
    delete finddialog;
    //delete sqlModel;
    delete timerBirthdays;
}

// авторизация
void MainWindow::sqlAuth(QString username, QString password)
{
    db_username = username;
    db_password = password;
    if (sqlConnect())
    {
        connectdialog->hide();
        this->hide();
        trayIcon->showMessage(tr("Добро пожаловать!"), tr("Авторизация успешно пройдена.\n"
                                                          "Приложение продолжает работу в трее"),
                              QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information), 10000);
        messageType = 0;
    }
    else
        QMessageBox::critical(this, tr("Ошибка подключения"),
                                    tr("Невозможно подключиться к базе данных.\n"
                                       "Убедитесь в правильности логина и пароля, "
                                       "проверьте соединение с базой SQL и повторите попытку"));
}

// подключение к базе
bool MainWindow::sqlConnect()
{  
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_username);
    db.setPassword(db_password);

    if (db.open())
    {
        enableInterface();
        isConnected = true;
    }
    return isConnected;
}

// отключение от базы
void MainWindow::sqlDisconnect()
{
    ui->tableView->selectionModel()->clear();
    db.close();
    disableInterface();
    isConnected = false;
}

void MainWindow::confirmDisconnect()
{
    if (QMessageBox::warning(this, tr("Отключение"),
                                   tr("Вы уверены, что хотите отключиться от базы данных?"),
                                   QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        sqlDisconnect();
}

// активация интерфейса
void MainWindow::enableInterface()
{
    // установки меню
    ui->tableView->setEnabled(true);
    ui->action_connect->setEnabled(false);
    ui->action_disconnect->setEnabled(true);
    ui->menu_edit->setEnabled(true);
    ui->menu_find->setEnabled(true);

    // заголовок окна
    this->setWindowTitle(tr("Алтай-Гид.Клиенты - Подключено"));

    // создание модели
    sqlModel = new QSqlTableModel(this);
    sqlModel->setTable(db_table);
    connect(sqlModel, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)),
                      this,
                      SLOT(updateSqlRecord()));

    // установка имен столбцов
    sqlModel->setHeaderData(1, Qt::Horizontal, tr("Ф.И.О."));
    sqlModel->setHeaderData(2, Qt::Horizontal, tr("Номер телефона"));
    sqlModel->setHeaderData(3, Qt::Horizontal, tr("Email"));
    sqlModel->setHeaderData(4, Qt::Horizontal, tr("Город"));
    sqlModel->setHeaderData(5, Qt::Horizontal, tr("Дата рождения"));
    sqlModel->setHeaderData(6, Qt::Horizontal, tr("Примечание"));
    ui->tableView->setStyleSheet("QHeaderView::section { background-color:lightGray }");

    // сортировка по возрастанию первичного ключа
    sqlModel->setSort(0, Qt::AscendingOrder);

    // метод редактирования - прием изменений вручную
    sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // установка модели в таблицу
    ui->tableView->setModel(sqlModel);

    // сокрытие столбца первичных ключей
    ui->tableView->setColumnHidden(0, true);

    // заполнение таблицы данными
    sqlModel->select();

    // смена обозначения в трее
    trayIcon->setIcon(QIcon(":/images/logo.png"));
    trayIcon->setToolTip(tr("Подключено к базе Алтай-Гид"));
}

// дезактивация интерфейса
void MainWindow::disableInterface()
{
    // установки меню
    ui->tableView->setEnabled(false);
    ui->action_connect->setEnabled(true);
    ui->action_disconnect->setEnabled(false);
    ui->menu_edit->setEnabled(false);
    ui->menu_find->setEnabled(false);

    // заголовок окна
    this->setWindowTitle(tr("Алтай-Гид.Клиенты - Отключено"));

    // деактивация модели
    delete sqlModel;

    // остановка таймера
    emit signalTimerStop();

    // смена обозначения в трее
    trayIcon->setIcon(QIcon(":/images/logoDisconnect.png"));
    trayIcon->setToolTip(tr("Нет подключения"));
}

// добавление записи
void MainWindow::addSqlRecord()
{
    // запрос на вставку дефолтной строки
    QSqlQuery query;
    QString str = "INSERT INTO `" + db_name + "`.`" + db_table + "` (clients_name, clients_tel, "
                                       "clients_email, clients_city, "
                                       "clients_date, clients_tour) "
                                       "VALUES ('<Имя>', '+7', '<Email>', "
                                       "'<Город>', NULL, '<Пусто>');";
    // выполнение запроса
    if (!query.exec(str))
        QMessageBox::critical(this, tr("Ошибка! Не удалось добавить запись"),
                                    query.lastError().text());
    else
    {
        // сортировка по возрастанию первичного ключа
        sqlModel->setSort(0, Qt::AscendingOrder);

        // обновление таблицы после добавления
        if (!sqlModel->select())
        {
            QMessageBox::critical(this, tr("Ошибка! Не удалось обновить таблицу"),
                                        sqlModel->lastError().text());
            sqlDisconnect();
        }
        else
        {
            // снятие всех имеющихся выделений по таблице
            ui->tableView->selectionModel()->clear();

            // выделение последней записи (добавленной)
            ui->tableView->selectRow(sqlModel->rowCount() - 1);
        }
    }
}

// удаление записи
void MainWindow::removeSqlRecord()
{
    // выбор выделенных строк
    QItemSelection selection = ui->tableView->selectionModel()->selection();

    // составление массива из индексов выбранных строк
    QList<int> removeRows;
    foreach (QModelIndex index, selection.indexes())
    {
        if (!removeRows.contains(index.row()))
            removeRows.append(index.row());
    }

    // проверка на то, что какие-то строки выбраны
    if (removeRows.count() == 0)
        QMessageBox::critical(this, tr("Удаление записи"),
                                    tr("Не выбраны записи для удаления"));
    else
    {

        // подтверждение на удаление
        if (QMessageBox::warning(this, tr("Удаление записи"),
                                       tr("Вы уверены, что хотите удалить эту запись?"),
                                       QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        {
            // цикл по количеству выделенных строк
            for (int i = 0; i < removeRows.count(); i++)
            {
                // уменьшение числа строк после текущей строки
                for (int j = i; j < removeRows.count(); j++)
                {
                    if(removeRows.at(j) > removeRows.at(i))
                        removeRows[j]--;
                }

                // удаление выбранной строки
                if (!sqlModel->removeRows(removeRows.at(i), 1))
                {
                    QMessageBox::critical(this, tr("Ошибка! Не удалось удалить запись"),
                                                sqlModel->lastError().text());
                    // откат изменений в случае ошибки
                    sqlModel->revertRow(removeRows.at(i));
                }
                else
                {
                    // применение изменений
                    if (!sqlModel->submitAll())
                    {
                        QMessageBox::critical(this, tr("Ошибка! Не удалось удалить запись"),
                                                    sqlModel->lastError().text());
                        // откат изменений в случае ошибки
                        sqlModel->revertRow(removeRows.at(i));
                    }
                }
            }
        }
    }
}

// редактирование записи
void MainWindow::updateSqlRecord()
{
    // применение изменений
    if (!sqlModel->submitAll())
    {
        QMessageBox::critical(this, tr("Ошибка! Не удалось изменить запись"),
                                    sqlModel->lastError().text());
        // откат изменений в случае ошибки
        sqlModel->revertAll();
    }
}

// обновление таблицы
void MainWindow::refreshSqlTable()
{
    if (!sqlModel->select())
    {
        QMessageBox::critical(this, tr("Ошибка! Не удалось обновить таблицу"),
                                    sqlModel->lastError().text());
        sqlDisconnect();
    }
}

// поиск записи в таблице
void MainWindow::sqlFind(QString str)
{
    QSqlQuery query;
    str = "SELECT * FROM `" + db_name + "`.`" + db_table + "` " + str;

    // ошибка запроса
    if (!query.exec(str))
    {
        QMessageBox::critical(nullptr, tr("Ошибка соединения с базой данных!"),
                          query.lastError().text());
        finddialog->hide();
        sqlDisconnect();
    }
    // запрос выполнен
    else
    {
        // снятие всех имеющихся выделений по таблице
        ui->tableView->selectionModel()->clear();

        // есть данные
        if (query.size() != 0)
        {
            finddialog->hide();
            ui->tableView->setSelectionMode(QAbstractItemView::MultiSelection);
            while (query.next())
            {
                for (int i = 0; i < sqlModel->rowCount(); i++)
                {
                    QModelIndex idx = sqlModel->index(i, 0);
                    if (sqlModel->data(idx).toInt() == query.value(0).toInt())
                    {
                        ui->tableView->selectRow(i);
                        break;
                    }
                }
            }
            ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        }
        else
            QMessageBox::information(nullptr, tr("Поиск записи"),
                              tr("Записей по указанным параметрам не найдено!"));
    }
}

// проверка дней рождения
void MainWindow::checkBirthdays()
{

    // запрос на дни рождения
    QSqlQuery query;
    QString str = "SELECT "
                  "round(timestampdiff(day, date(`clients_date`), date(now())) / 365) as age,"
                  "date_add(date(`clients_date`), interval round(timestampdiff(day, date(`clients_date`), date(now())) / 365) year) as new_birth,"
                  "timestampdiff(day, date(now()), date_add(date(`clients_date`), interval round(timestampdiff(day, date(`clients_date`), date(now())) / 365) year)) as days_left,"
                  "u.* "
                  "FROM "
                  "`" + db_name + "`.`" + db_table + "` as u "
                  "having days_left >= 0 and days_left <= 3 "
                  "order by days_left;";

    // ошибка запроса
    if (!query.exec(str))
    {
        if (this->isHidden())
        {
            trayIcon->showMessage(tr("Ошибка соединения с базой данных!"), query.lastError().text(),
                                  QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Critical), 15000);
            messageType = 2;
        }
        else
            QMessageBox::critical(nullptr, tr("Ошибка соединения с базой данных!"),
                              query.lastError().text());

        sqlDisconnect();
    }
    // запрос выполнен
    else
    {
        // снятие всех имеющихся выделений по таблице
        ui->tableView->selectionModel()->clear();

        // есть данные
        if (query.size() != 0)
        {
            // приложение свернуто - предупреждение
            if (this->isHidden())
            {
                trayIcon->showMessage(tr("Внимание!"), tr("Проверьте дни рождения клиентов!"),
                                      QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information), 15000);
                messageType = 1;
            }
            // приложение развернуто - выделение нужных строк
            else
            {
                ui->tableView->setSelectionMode(QAbstractItemView::MultiSelection);
                while (query.next())
                {
                    for (int i = 0; i < sqlModel->rowCount(); i++)
                    {
                        QModelIndex idx = sqlModel->index(i, 0);
                        if (sqlModel->data(idx).toInt() == query.value(3).toInt())
                        {
                            ui->tableView->selectRow(i);
                            break;
                        }
                    }
                }
                ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
            }
        }
    }
}

// инициализация иконки трея
void MainWindow::createTrayIcon()
{
    // меню трея
    QAction *action_restore = new QAction(tr("Развернуть"), this);
    QAction *action_quit = new QAction(tr("Выход"), this);
    connect(action_restore, &QAction::triggered, this, &MainWindow::windowRestore);
    connect(action_quit, &QAction::triggered, this, &MainWindow::applicationClose);
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(action_restore);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(action_quit);

    // иконка трея
    trayIcon = new QSystemTrayIcon(this);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::iconActivated);
    connect(trayIcon, &QSystemTrayIcon::messageClicked, this, &MainWindow::messageClicked);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(":/images/logoDisconnect.png"));
    trayIcon->setToolTip(tr("Нет подключения"));
    trayIcon->show();
}

// чтение настроек из файла
void MainWindow::readSettings()
{
    QSettings *settings = new QSettings("config.ini", QSettings::IniFormat, this);
    settings->beginGroup("sql");
    db_driver = settings->value("driver", "QMYSQL").toString();
    db_name = settings->value("db", "null").toString();
    db_table = settings->value("table", "null").toString();
    db_host = settings->value("host", "127.0.0.1").toString();
    intervalWarning = settings->value("interval", 1).toInt();
    delete settings;
}

// закрытие формы - сворачивание в трей
void MainWindow::closeEvent(QCloseEvent *event)
{
#ifdef Q_OS_OSX
    if (!event->spontaneous() || !isVisible()) {
        return;
    }
#endif
    if (trayIcon->isVisible()) {
        windowHide();
        event->ignore();
    }
}

// двойной клик - разворачивание окна из трея
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::DoubleClick:
        windowRestore();
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        ;
    }
}

// клик по сообщению в трее
void MainWindow::messageClicked()
{
    switch (messageType)
    {
        case 0: break;
        case 1:
            windowRestore();
            if (isConnected)
                checkBirthdays();
        break;
        case 2: windowRestore(); break;
    }
}

// сворачивание окна в трей
void MainWindow::windowHide()
{
    if (!finddialog->isHidden())
        finddialog->hide();
    if (!connectdialog->isHidden())
        connectdialog->hide();
    hide();

    if (isConnected)
        emit signalTimerStart(intervalWarning * 60 * 1000);
    else
    {
        trayIcon->showMessage(tr("Внимание!"), tr("Проверьте подключение к базе данных!"),
                              QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Warning), 15000);
        messageType = 2;
    }
}

// разворачивание окна из трея
void MainWindow::windowRestore()
{
    if (this->isHidden())
    {
        show();
        ui->tableView->sortByColumn(1, Qt::AscendingOrder);
        //sqlModel->setSort(1, Qt::AscendingOrder);
        emit signalTimerStop();
    }
}

// завершение работы приложения
void MainWindow::applicationClose()
{
    if (QMessageBox::warning(this, tr("Выход"),
                                   tr("Вы уверены, что хотите завершить работу приложения?"),
                                   QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        qApp->quit();
}

#endif
