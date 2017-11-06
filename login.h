#ifndef LOGIN_H
#define LOGIN_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QString>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    void UsrLogin();
    void MngLogin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
