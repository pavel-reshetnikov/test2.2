#include "practic.h"
#include "ui_practic.h"
#include "exitwindow.h"

practic::practic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::practic)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE"); // ПОДКЛЮЧЕНИЕ БАЗЫ ДАННЫХ
    db.setDatabaseName("./testDB.db");
    if (db.open()){
        qDebug("open");
    }
    else{
        qDebug("no open");
    }

    query = new QSqlQuery(db); // СОЗДАНИЕ ТАБЛИЦЫ
    query->exec("CREATE TABLE TelephoneBook(Firstname TEXT, Lastname TEXT, Telephone TEXT);");

    model = new QSqlTableModel(this, db);
    model -> setTable("TelephoneBook");
    model->select();

    ui->tableView->setModel(model);
    ewindow = new Exitwindow;
    connect(ewindow, &Exitwindow::signal, this, &practic::slot);
}

practic::~practic()
{
    delete ui;
}


void practic::on_pushButton_clicked()
{
    model->insertRow(model->rowCount());
}


void practic::on_pushButton_2_clicked()
{
    model->removeRow(row); // УДАЛЕНИЕ ТАБЛИЦЫ

}


void practic::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row(); // ПОЛУЧЕНИЕ ИНДЕКСА ТАБЛИЦЫ
}


void practic::on_pushButton_3_clicked()
{
    ewindow->show();

}

void practic::slot()
{
    qDebug("close");
close();
}


void practic::on_pushButton_4_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

