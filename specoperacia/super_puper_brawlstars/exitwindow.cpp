#include "exitwindow.h"
#include "ui_exitwindow.h"

Exitwindow::Exitwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exitwindow)
{
    ui->setupUi(this);
}

Exitwindow::~Exitwindow()
{
    delete ui;
}




void Exitwindow::on_pushButton_clicked()
{
emit signal();
    close();
}

void Exitwindow::on_pushButton_2_clicked()
{
close();
}

