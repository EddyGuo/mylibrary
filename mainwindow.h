#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include "register.h"
#include "login.h"
#include "insert.h"
#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

public:
    bool dbConnect();
    bool dbCreat();

    enum BkIndex
    {
        BkId=0,
        BkName=1,
        BkAuthor=2,
        BkPub=3,
        BkPubDate=4,
        BkAvail=5,
        BkStore=6,
        BkTotal=7

    };

    enum UsrIndex
    {
        UsrId=0,
        UsrPwd=1,
        UsrEmail=2,
        UsrLoan=3,
        UsrMax=4
    };


private slots:
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_4_clicked();
};


#endif // MAINWINDOW_H
