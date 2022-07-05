#ifndef EXITWINDOW_H
#define EXITWINDOW_H

#include <QDialog>

namespace Ui {
class Exitwindow;
}


class Exitwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Exitwindow(QWidget *parent = nullptr);
    ~Exitwindow();

private slots:

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::Exitwindow *ui;

signals:
    void signal();



};

#endif // EXITWINDOW_H
