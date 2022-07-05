#ifndef PRACTIC_H
#define PRACTIC_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <exitwindow.h>
#include <QApplication>
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui { class practic; }
QT_END_NAMESPACE

class practic : public QMainWindow
{
    Q_OBJECT

public:
    practic(QWidget *parent = nullptr);
    ~practic();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::practic *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;

    int row;
    Exitwindow *ewindow;

public slots:
    void slot();

};
#endif // PRACTIC_H
