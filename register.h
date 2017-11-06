#ifndef REGISTER_H
#define REGISTER_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private:
    Ui::Register *ui;

public:
    void UsrRegister();

private slots:
    void on_pushButton_clicked();
};

#endif // REGISTER_H
