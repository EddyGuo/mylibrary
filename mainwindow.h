#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include "register.h"
#include "insert.h"
#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QString>
#include <QSqlError>
#include <QDateTime>
#include <QDate>
#include <QTimer>
#include <QSqlRecord>

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
    QSqlTableModel *BkModel;
    QSqlTableModel *UsrModel;
    QSqlTableModel *LoanModel;
    QSqlTableModel *UsrLoanModel;
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QTimer *timer;

    int user_type;
    int book_store;
    QString id;

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

    enum LoanIndex
    {
        LUsrId=0,
        LBkId=1,
        LDate=2,
        LBackDate=3
    };

    enum{MANAGER,USER,VISITOR};

public:
    bool dbConnect();
    bool dbCreat();
    void UsrLogin();
    void UiUpdate();
    void MngLogin();


private slots:
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_17_clicked();
};


#endif // MAINWINDOW_H
